<?php

class Class_Servers_Page
{
    public function __construct()
    {
        if (!empty($_REQUEST['mode']))
        {
            $mode = HTTP::_REQUEST("mode");
            switch ($mode)
            {
                case 'close':
                    $this->Close();
                    break;
                case 'reload':
                    $this->Reload();
                    break;
                case 'add':
                    $this->Add();
                    break;
            }
        }
        $this->Display();
    }

    private function GetList()
    {
        global $Database;

        $List = array();
        $Servers_List = $Database->query("SELECT * FROM ".MYSQL_PREFIX."server ORDER BY server_id DESC;");
        while ($donnees = $Servers_List->fetch())
        {
            $List[] = array(
                "ID"        => $donnees['server_id'],
                "Host"      => $donnees['server_host'],
                "Port"      => $donnees['server_port'],
                "Status"    => $donnees['server_status']
            );
        }
        return ($List);
    }

    private function Close()
    {
        global $Database;

        if (empty($_REQUEST['id']))
            return (false);
        $id     = HTTP::_REQUEST("id", 0, "numeric");
        $Database->query("INSERT INTO ".MYSQL_PREFIX."action SET action_server_id = '{$id}', action_type = 'quit', action_values = '', action_result = 'list';");
        return (true);
    }

    private function Reload()
    {
        global $Database;

        if (empty($_REQUEST['id']))
            return (false);
        $id     = HTTP::_REQUEST("id", 0, "numeric");
        $Database->query("UPDATE ".MYSQL_PREFIX."server SET server_status = 'disconnected' WHERE server_id = '{$id}';");
        return (true);
    }

    private function Add()
    {
        global $Database;

        if (empty($_REQUEST['hostname']) || empty($_REQUEST['port']))
            return (false);
        $host   = HTTP::_REQUEST("hostname", "localhost");
        $port   = HTTP::_REQUEST("port", 0, "numeric");
        $Database->query("INSERT INTO ".MYSQL_PREFIX."server SET server_host = '{$host}', server_port = '{$port}', server_status = 'disconnected';");
        return (true);
    }

    private function Display()
    {
        global $Twig;

        $TwigArray = array(
            "List"  => $this->GetList(),
            "Page"  => "Servers",
        );
        echo $Twig->render('Page_Servers.html', $TwigArray);
    }
}

?>
