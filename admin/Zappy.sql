SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;


CREATE TABLE IF NOT EXISTS `zappy_action` (
`action_id` int(11) NOT NULL,
  `action_server_id` int(11) NOT NULL DEFAULT '0',
  `action_type` varchar(255) DEFAULT NULL,
  `action_values` varchar(255) DEFAULT NULL,
  `action_result` enum('list','ok','ko') NOT NULL DEFAULT 'list'
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

CREATE TABLE IF NOT EXISTS `zappy_player` (
`player_id` int(11) NOT NULL,
  `player_server_id` int(11) NOT NULL DEFAULT '0',
  `player_team_id` int(11) NOT NULL DEFAULT '0',
  `player_inventaire` varchar(255) DEFAULT NULL,
  `player_x` int(11) NOT NULL DEFAULT '0',
  `player_y` int(11) NOT NULL DEFAULT '0',
  `player_direction` int(11) NOT NULL DEFAULT '0',
  `player_level` int(11) NOT NULL DEFAULT '0',
  `player_real_id` int(11) NOT NULL DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

CREATE TABLE IF NOT EXISTS `zappy_server` (
`server_id` int(11) NOT NULL,
  `server_host` varchar(255) DEFAULT NULL,
  `server_port` int(11) NOT NULL,
  `server_status` enum('disconnected','connected','lost') NOT NULL DEFAULT 'disconnected'
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

CREATE TABLE IF NOT EXISTS `zappy_team` (
`team_id` int(11) NOT NULL,
  `team_server_id` int(11) NOT NULL DEFAULT '0',
  `team_name` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;


ALTER TABLE `zappy_action`
 ADD PRIMARY KEY (`action_id`);

ALTER TABLE `zappy_player`
 ADD PRIMARY KEY (`player_id`);

ALTER TABLE `zappy_server`
 ADD PRIMARY KEY (`server_id`);

ALTER TABLE `zappy_team`
 ADD PRIMARY KEY (`team_id`);


ALTER TABLE `zappy_action`
MODIFY `action_id` int(11) NOT NULL AUTO_INCREMENT;
ALTER TABLE `zappy_player`
MODIFY `player_id` int(11) NOT NULL AUTO_INCREMENT;
ALTER TABLE `zappy_server`
MODIFY `server_id` int(11) NOT NULL AUTO_INCREMENT;
ALTER TABLE `zappy_team`
MODIFY `team_id` int(11) NOT NULL AUTO_INCREMENT;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
