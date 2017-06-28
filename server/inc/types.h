/*
** types.h for lol in /home/tetra/rendu/psu/PSU_2016_zappy/server
** 
** Made by Arthur Josso
** Login   <arthur.josso@epitech.eu>
** 
** Started on  Wed Jun  7 14:08:32 2017 Arthur Josso
** Last update Wed Jun 28 18:24:21 2017 Arthur Josso
*/

#pragma once

#include <poll.h>

typedef struct pollfd t_poll;

typedef struct
{
  int32_t	x;
  int32_t	y;
} t_pos;

typedef t_pos t_size;

typedef enum
  {
    ENTITY_NONE = 0,
    ENTITY_PLAYER,
    ENTITY_GRAPHIC,
    ENTITY_ADMIN
  } t_entity_type;

typedef enum
  {
    RES_NONE = -1,
    RES_FOOD = 0,
    RES_LINEMATE,
    RES_DERAUMERE,
    RES_SIBUR,
    RES_MENDIANE,
    RES_PHIRAS,
    RES_THYSTAME,
    RES_NBR
  } t_ressource;

typedef enum
  {
    DIR_NORTH = 0,
    DIR_EAST,
    DIR_SOUTH,
    DIR_WEST,
    DIR_NBR
  } t_direction;

typedef enum
  {
    MOVE_LEFT = -1,
    MOVE_FORWARD,
    MOVE_RIGHT
  } t_move;

typedef enum
  {
    COORD_X = 0,
    COORD_Y,
    COORD_NBR
  } t_coordinate;

typedef enum
  {
    CMD_NONE,
    CMD_WELCOME,
    CMD_PLAYER_NBR_FREE_SLOT,
    CMD_PLAYER_MAP_SIZE,
    CMD_PLAYER_OK,
    CMD_PLAYER_KO,
    CMD_PLAYER_DEAD,
    CMD_PLAYER_INCANTATION_START,
    CMD_PLAYER_INCANTATION_END,
    CMD_PLAYER_EJECT,
    CMD_PLAYER_BROADCAST,
    CMD_GRAPHIC_BAD_CMD,
    CMD_GRAPHIC_BAD_ARG,
    CMD_GRAPHIC_MAP_SIZE,
    CMD_GRAPHIC_TILE_CONTENT,
    CMD_GRAPHIC_TEAM_NAME,
    CMD_GRAPHIC_PLAYER_POS,
    CMD_GRAPHIC_PLAYER_LVL,
    CMD_GRAPHIC_PLAYER_INVENTORY,
    CMD_GRAPHIC_TIME_REF,
    CMD_GRAPHIC_NEW_PLAYER,
    CMD_GRAPHIC_PUSH,
    CMD_GRAPHIC_BROADCAST,
    CMD_GRAPHIC_INCANTATION_START,
    CMD_GRAPHIC_INCANTATION_END,
    CMD_GRAPHIC_FORK_START,
    CMD_GRAPHIC_FORK_DROP,
    CMD_GRAPHIC_FORK_END,
    CMD_GRAPHIC_DROP,
    CMD_GRAPHIC_TAKE,
    CMD_GRAPHIC_DIE,
    CMD_GRAPHIC_EGG_CONNECT,
    CMD_GRAPHIC_EGG_DIES,
    CMD_GRAPHIC_END,
    CMD_ADMIN_BAD_CMD,
    CMD_ADMIN_LIST
  } t_cmd_type;
