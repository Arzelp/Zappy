/*
** default_values.h for default in /client/inc/
**
** Made by Frederic Oddou
** Login   <frederic.oddou@epitech.eu>
**
** Started on  Fri Jun 16 11:26:36 2017 Frederic Oddou
** Last update Thu Jun 29 18:42:15 2017 Paskal Arzel
*/

#pragma once

#ifdef DEBUG_MODE
# define DEBUG true
#else
# define DEBUG true
#endif

#define NAME_SIZE		256
#define HOST_SIZE		2048
#define BUFFER_SIZE		2048
#define KEY_SIZE		15

#define DFLT_SERVER_PORT	4242
#define DFLT_SERVER_HOST	"localhost"
#define DELT_MAX_LVL		8

#define	MAX_CALLS			5

#define START_FERT		10
#define CD_FERTILITY	30
#define MIN_SAFE_FOOD	10
#define MAX_RUSH			20
#define MAX_FOOD			75

#define PRIMARY_FACT		5
#define SECONDARY_FACT	3

/*
** @Action's cost
*/

#define CLASSIC_COST		7
#define EGG_COST		42
#define BORN_TIME		600
#define INV_COST		1
