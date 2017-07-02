<?php

class Class_Home_Page
{
    public function __construct()
    {
        $this->Display();
    }

    private function Get_Server_List()
    {
        global $Database;

        $List = array();
        $Servers_List = $Database->query("SELECT * FROM ".MYSQL_PREFIX."server WHERE server_status = 'connected' ORDER BY server_id DESC;");
        while ($donnees = $Servers_List->fetch())
        {
            $List[] = array(
                "ID"        => $donnees['server_id'],
                "Host"      => $donnees['server_host'],
                "Port"      => $donnees['server_port']
            );
        }
        return ($List);
    }

    private function Get_Action_List()
    {
        global $Database;

        $List = array();
        $Action_List = $Database->query("SELECT * FROM ".MYSQL_PREFIX."action INNER JOIN ".MYSQL_PREFIX."server on action_server_id = server_id ORDER BY action_id DESC LIMIT 15;");
        while ($donnees = $Action_List->fetch())
        {
            $List[] = array(
                "ID"        => $donnees['action_id'],
                "Server"    => "{$donnees['server_host']}:{$donnees['server_port']} (ID:{$donnees['action_server_id']})",
                "Type"      => $donnees['action_type'],
                "Values"    => $donnees['action_values'],
                "Status"    => $donnees['action_result']
            );
        }
        return ($List);
    }

    private function Display()
    {
        global $Twig;

        $TwigArray = array(
            "Action"    => $this->Get_Action_List(),
            "Servers"   => $this->Get_Server_List(),
            "Page"      => "Home",
        );
        echo $Twig->render('Page_Home.html', $TwigArray);
    }
}

?>
