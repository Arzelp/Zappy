<?php

error_reporting(E_ALL);
set_time_limit(0);

ob_start('ob_gzhandler');
date_default_timezone_set('Europe/Paris');
session_start();

require_once("Src/Constants.php");
require_once("Src/Server.php");
require_once("Lib/Class_Database.php");

$Database = new Database;

class Core
{
        private $Database       = NULL;
        private $Server         = array();
        public $Continue        = true;

        public function __construct()
        {
        }

        public function Exec()
        {
                global $Database;

                while ($this->Continue)
                {
                        echo "Refreshing all servers\n";
                        $Server_List = $Database->query("SELECT * FROM ".MYSQL_PREFIX."server WHERE server_status != 'lost';");
                        while ($donnees = $Server_List->fetch())
                        {
                                switch ($donnees["server_status"])
                                {
                                        case 'disconnected':
                                                $New_Server = new Server($donnees["server_id"], $donnees["server_host"], $donnees["server_port"]);
                                                if ($New_Server->Socket_Connect())
                                                {
                                                        $New_Server->Init_To_Server();
                                                        $this->Server[] = $New_Server;
                                                }
                                                else
                                                        unset($New_Server);
                                                break;
                                        case 'connected':
                                                foreach ($this->Server as $key => $value)
                                                {
                                                        if ($this->Server[$key]->S_ID == $donnees['server_id'])
                                                        {
                                                                $this->Server[$key]->Refresh();
                                                                break;
                                                        }
                                                }
                                                break;
                                }
                        }
                        sleep(1);
                }
        }
}

?>
