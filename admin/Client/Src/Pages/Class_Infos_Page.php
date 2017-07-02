<?php

class Class_Infos_Page
{
    private $id = 0;

    public function __construct()
    {
        global $Database;

        if (!empty($_REQUEST['id']))
        {
            $this->id     = HTTP::_REQUEST("id", 0, "numeric");
            $count = $Database->countquery("SELECT * FROM ".MYSQL_PREFIX."server WHERE server_id = '{$this->id}';");
            if ($count)
            {
                if (!empty($_REQUEST['mode']))
                {
                    $mode   = HTTP::_REQUEST("mode");
                    switch ($mode)
                    {
                        case 'lvlup':
                            $this->LevelUp();
                            break;
                        case 'kill':
                            $this->Kill();
                            break;
                    }
                }
                $this->Display();
            }
        }
    }

    private function GetPlayer($team_id)
    {
        global $Database;

        $List           = array();
        $Player_List    = $Database->query("SELECT * FROM ".MYSQL_PREFIX."player WHERE player_server_id = '{$this->id}' AND player_team_id = '{$team_id}' ORDER BY player_id ASC;");
        while ($donnees = $Player_List->fetch())
        {
            $List[] = array(
                "ID"                => $donnees['player_id'],
                "pos_x"             => $donnees['player_x'],
                "pos_y"             => $donnees['player_y'],
                "direction"         => $donnees['player_direction'],
                "level"             => $donnees['player_level'],
                "real_id"           => $donnees['player_real_id'],
			    "inventary"         => $donnees['player_inventaire']
            );
        }
        return ($List);
    }

    private function GetTeam($id)
    {
        global $Database;

        $List       = array();
        $Team_List  = $Database->query("SELECT * FROM ".MYSQL_PREFIX."team WHERE team_server_id = '{$this->id}' ORDER BY team_id ASC;");
        while ($donnees = $Team_List->fetch())
        {
            $List[] = array(
                "ID"        => $donnees['team_id'],
                "name"      => $donnees['team_name'],
                "players"   => $this->GetPlayer($donnees['team_id'])
            );
        }
        return ($List);
    }

    private function LevelUp()
    {
        global $Database;

        if (empty($_REQUEST['uid']))
            return (false);
        $uid = HTTP::_REQUEST("uid", 0, "numeric");
        $Database->query("INSERT INTO ".MYSQL_PREFIX."action SET action_server_id = '{$this->id}', action_type = 'levelup', action_values = '{$uid}', action_result = 'list';");
        return (true);
    }

    private function Kill()
    {
        global $Database;

        if (empty($_REQUEST['uid']))
            return (false);
        $uid = HTTP::_REQUEST("uid", 0, "numeric");
        $Database->query("INSERT INTO ".MYSQL_PREFIX."action SET action_server_id = '{$this->id}', action_type = 'kill', action_values = '{$uid}', action_result = 'list';");
        return (true);
    }

    private function Display()
    {
        global $Twig;

        $TwigArray = array(
            "List"      => $this->GetTeam(),
            "id"        => $this->id,
            "Page"      => "Server informations",
        );
        echo $Twig->render('Page_Infos.html', $TwigArray);
    }
}

?>
