/*
** default_values.h for default in /client/inc/
**
** Made by Frederic Oddou
** Login   <frederic.oddou@epitech.eu>
**
** Started on  Fri Jun 16 11:26:36 2017 Frederic Oddou
** Last update Tue Jun 27 22:47:16 2017 Frederic Oddou
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

#define DFLT_SERVER_PORT	4242
#define DFLT_SERVER_HOST	"localhost"
#define DELT_MAX_LVL		8

#define START_FERT		30
#define MIN_SAFE_FOOD		5
#define MAX_RUSH			20

/*
** @Action's cost
*/

#define CLASSIC_COST		7
#define EGG_COST		42
#define BORN_TIME		600
#define INV_COST		1
