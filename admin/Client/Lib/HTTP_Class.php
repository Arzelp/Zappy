<?php

class HTTP
{
	public function _REQUEST($name, $default = '', $value = NULL, $type = NULL)
	{
		if (!empty($type))
		{
			if ($type == 'GET')
				$REQUEST	= $_GET[$name];
			else if ($type == 'POST')
				$REQUEST	= $_POST[$name];
			else
				$REQUEST	= $_REQUEST[$name];
		}
		else
			$REQUEST	= $_REQUEST[$name];

		if (!isset($REQUEST) || empty($REQUEST))
			return $default;

		switch ($value)
		{
			case 'numeric':
				if ($REQUEST == 'on')
					return (1);
				else if ($REQUEST == 'off')
					return (0);
				if (!is_numeric($REQUEST))
					return $default;
				break;
			case 'alphanumeric':
				if (!preg_match('/^[a-zA-Z]+$/', $REQUEST))
					return $default;
				break;
			case 'notfloat':
				if (is_float($REQUEST))
					return $default;
				break;
		}
		$REQUEST = htmlentities($REQUEST, ENT_QUOTES, "UTF-8");
		return ($REQUEST);
	}
}
?>
