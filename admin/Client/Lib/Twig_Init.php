<?php

require_once 'Lib/Twig/Autoloader.php';

function  Twig_Init()
{

  Twig_Autoloader::register();

  $loader = new Twig_Loader_Filesystem('Templates/');
  $twig = new Twig_Environment($loader, array(
        'cache' => 'Cache/',
  ));
  return ($twig);
}

?>
