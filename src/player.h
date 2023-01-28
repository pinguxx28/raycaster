#ifndef __PLAYER_H
#define __PLAYER_H
#include "include.h"
#include "vars.h"
#include "draw.h"
#include "keys.h"
#include "helper.h"
#include "map.h"

#define PLAYER_RADIUS 4
#define PLAYER_TURN_SPEED 8
#define PLAYER_MOVEMENT_SPEED 4

typedef struct
{
	int		x, y;
	float	delta_x, delta_y;
	int		angle_degrees;
	float	angle_radians;
}
player_t;

extern bool map_mode;
extern player_t player;

void turn_player();
void move_player();

void init_player();
void draw_player();
void updt_player();

#endif
