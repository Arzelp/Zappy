<?php

error_reporting(E_ALL);
set_time_limit(0);

ob_start('ob_gzhandler');
date_default_timezone_set('Europe/Paris');
session_start();

require_once("Src/Constants.php");
require_once("Lib/Class_Database.php");
require_once("Lib/Twig_Init.php");
require_once("Lib/HTTP_Class.php");

$Database       = new Database;
$Twig           = Twig_Init();

class Core
{
        public function __construct()
        {
        }

        public function __destruct()
        {
        }

        public function Page()
        {
            $p1         = HTTP::_REQUEST("page", "home");
            $ucfirstp1	= ucfirst($p1);
            $docpage	= "Src/Pages/";
            $lien       = $docpage."Class_{$ucfirstp1}_Page.php";

            if (file_exists($lien))
            {
                include($lien);
                $PageClass = "Class_{$ucfirstp1}_Page";
            }
            if (!empty($PageClass))
            {
                $PageClass_Ex = new $PageClass();
                $PageClass_Ex();
            }
        }
}

?>
