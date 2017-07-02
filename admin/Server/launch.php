<?php

require_once("Src/Core.php");

while (@ob_end_flush());
ob_implicit_flush(true);

echo "Welcome on the server administration manager.\n";

$Core = new Core;
$Core->Exec();

?>
