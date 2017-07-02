<?php

class Server
{
        public $S_ID            = 0;
        public $S_Host          = NULL;
        public $S_Port          = NULL;
        public $S_SizeX         = 0;
        public $S_SizeY         = 0;
        private $S_Socket       = NULL;

        public function __construct($ID, $Host, $Port)
        {
                $this->S_ID = $ID;
                $this->S_Host = $Host;
                $this->S_Port = $Port;
                echo "[Creating Server] {$this->S_Host}:{$this->S_Port} (ID:{$this->S_ID})\n";
        }

        public function __destruct()
        {
                global $Database;

                if ($this->S_Socket)
                        socket_close($this->S_Socket);
                $Database->query("UPDATE ".MYSQL_PREFIX."server SET server_status = 'lost' WHERE server_id = '{$this->S_ID}';");
                echo "[Closing Server] {$this->S_Host}:{$this->S_Port} (ID:{$this->S_ID})\n";
        }

        public function Socket_Connect()
        {
                global $Database;

                if (($this->S_Socket = socket_create(AF_INET, SOCK_STREAM, SOL_TCP)) === false)
                {
                    echo "socket_create() failed: reason: " . socket_strerror(socket_last_error()) . "\n";
                    return (false);
                }

                if (($result = socket_connect($this->S_Socket, gethostbyname($this->S_Host), $this->S_Port)) === false)
                {
                    echo "socket_connect() failed.\nReason: ($result) " . socket_strerror(socket_last_error($this->S_Socket)) . "\n";
                    return (false);
                }
                $Database->query("UPDATE ".MYSQL_PREFIX."server SET server_status = 'connected' WHERE server_id = '{$this->S_ID}';");
                echo "[Connecting to distant Server] {$this->S_Host}:{$this->S_Port} (ID:{$this->S_ID})\n";
                return (true);
        }

        public function Receive()
        {
                $buffer = "";
                $buf = "";
                while (socket_recv($this->S_Socket, $buf, 1, MSG_WAITALL) > 0)
                {
                        if ($buf == "\n")
                                return ($buffer);
                        $buffer .= $buf;
                        $buf = "";
                }
                return ($buffer);
        }

        public function Send($message)
        {
                $message .= "\n";
                if (socket_write($this->S_Socket, $message, strlen($message)) == FALSE)
                        return (false);
                return (true);
        }

        public function Init_To_Server()
        {
                $buffer = "";
                if (($buffer = $this->Receive()) == "WELCOME")
                {
                        $this->Send(SERVER_PASSWD);
                }
        }

        private function UpdateTeam($List)
        {
                global $Database;

                foreach ($List as $key => $value)
                {
                        $count = $Database->countquery("SELECT * FROM ".MYSQL_PREFIX."team WHERE team_name = '{$value["team"]}' AND team_server_id = '{$this->S_ID}';");
                        if ($count == 0)
                                $Database->query("INSERT INTO ".MYSQL_PREFIX."team SET team_name = '{$value["team"]}', team_server_id = '{$this->S_ID}';");
                }
        }

        private function UpdatePlayer($List)
        {
                global $Database;

                foreach ($List as $key => $value)
                {
                        $count = $Database->countquery("SELECT * FROM ".MYSQL_PREFIX."player WHERE player_real_id = '{$value['id']}' AND player_server_id = '{$this->S_ID}';");
                        if ($count == 0)
                        {
                                $Team = $Database->selectquery("SELECT * FROM ".MYSQL_PREFIX."team WHERE team_name = '{$value["team"]}' AND team_server_id = '{$this->S_ID}';");
                                $Database->query("INSERT INTO ".MYSQL_PREFIX."player SET  player_x = '{$value['pos_x']}',
                                                                                        player_y = '{$value['pos_y']}',
                                                                                        player_inventaire = '{$value['inventory']}',
                                                                                        player_level = '{$value['level']}',
                                                                                        player_direction = '{$value['direction']}',
                                                                                        player_team_id = '{$Team["team_id"]}',
                                                                                        player_real_id = '{$value["id"]}',
                                                                                        player_server_id = '{$this->S_ID}';");
                        }
                        else
                        {
                                $Database->query("UPDATE ".MYSQL_PREFIX."player SET  player_x = '{$value['pos_x']}',
                                                                                        player_y = '{$value['pos_y']}',
                                                                                        player_inventaire = '{$value['inventory']}',
                                                                                        player_level = '{$value['level']}',
                                                                                        player_direction = '{$value['direction']}'
                                                                              WHERE
                                                                                        player_real_id = '{$value["id"]}' AND
                                                                                        player_server_id = '{$this->S_ID}';");
                        }
                }
        }

        private function GetList()
        {
                $this->Send("list");
                $List = array();
                while (($recv = $this->Receive()) != "" && $recv != "Command successfull" && $recv != "Command failed")
                {
                        $Infos = array();
                        list($Infos['id'], $Infos['team'], $Infos['pos_x'], $Infos['pos_y'], $Infos['direction'], $Infos['level'], $Infos['inventory']) = sscanf($recv, "list: ID:%d Team:%s Position:%d/%d Direction:%d Level:%d Inventory:%s");
                        $List[] = $Infos;

                }
                $this->UpdateTeam($List);
                $this->UpdatePlayer($List);
        }

        private function ExecAction()
        {
                global $Database;

                $Action_List = $Database->query("SELECT * FROM ".MYSQL_PREFIX."action WHERE action_result = 'list' AND action_server_id = '{$this->S_ID}';");
                while ($donnees = $Action_List->fetch())
                {
                        switch ($donnees['action_type'])
                        {
                                case "levelup":
                                        $Message = "lvlup {$donnees['action_values']}";
                                        $this->Send($Message);
                                        $Answer = $this->Receive();
                                        $Database->query("UPDATE ".MYSQL_PREFIX."action
                                                                                        SET action_result = '".(($Answer == "Command successfull") ? 'ok' : 'ko')."'
                                                                                        WHERE action_id = '{$donnees['action_id']}';");
                                        echo "[{$Answer}] {$Message}\n";
                                        break;
                                case "kill":
                                        $Message = "kill {$donnees['action_values']}";
                                        $this->Send($Message);
                                        $Answer = $this->Receive();
                                        $Database->query("UPDATE ".MYSQL_PREFIX."action
                                                                                        SET action_result = '".(($Answer == "Command successfull") ? 'ok' : 'ko')."'
                                                                                        WHERE action_id = '{$donnees['action_id']}';");
                                        echo "[{$Answer}] {$Message}\n";
                                        break;
                                case "quit":
                                        $Message = "quit";
                                        $this->Send($Message);
                                        $Database->query("UPDATE ".MYSQL_PREFIX."action SET action_result = 'ok' WHERE action_id = '{$donnees['action_id']}';");
                                        echo "[Command successfull] {$Message}\n";
                                        $this->__destruct();
                                        break;
                                default:
                                        echo "[Command failed] \"{$donnees['action_type']}\" dosen't exist.\n";
                                        break;
                        }
                }
        }

        public function Refresh()
        {
                echo "[Refresh] {$this->S_Host}:{$this->S_Port} (ID:{$this->S_ID})\n";
                $this->GetList();
                $this->ExecAction();
        }
}

?>
