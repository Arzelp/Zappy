<?php

class Database
{
	private $db = NULL;

	public function __construct()
	{
		$this->db = new PDO('mysql:host='.MYSQL_HOST.';dbname='.MYSQL_BDD, MYSQL_USERS, MYSQL_PSWD);
		if (mysqli_connect_error())
			throw new Exception("Database connexion failled", 1);
		$this->db->query("set names ".TYPE_ENCODAGE);
		$this->db->query("SET SESSION sql_mode = 'STRICT_ALL_TABLES';");
	}

	/* Using for every request */
	public function query($requete)
	{
		$result = $this->db->query($requete);
		return ($result);
	}

	/* Select only one line and give the array */
	public function selectquery($requete)
	{
		$result = $this->db->query($requete);
		$result = $result->fetch();
		return ($result);
	}

	/* Count the number of line */
	public function countquery($requete)
	{
		$result = $this->db->query($requete);
		$result = $result->rowCount();
		return ($result);
	}

	/* Creating an array from a request */
	public function fetchquery($requete)
	{
		$result = $this->db->query($requete);
		$result->setFetchMode(PDO::FETCH_ASSOC);
		return ($result);
	}
}

?>
