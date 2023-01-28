#include "player.h"

bool map_mode = false;
player_t player;

void turn_player()
{
	bool turned = false;
	if (keys['a']) { player.angle_degrees -= PLAYER_TURN_SPEED; turned = true; }
	if (keys['d']) { player.angle_degrees += PLAYER_TURN_SPEED; turned = true; }

	if (turned)
	{
		fix_angle(&player.angle_degrees);
		player.angle_radians = radians(player.angle_degrees);
		player.delta_x = cos(player.angle_radians);
		player.delta_y = sin(player.angle_radians);
	}
}

void move_player()
{
	int dir = 0;
	if (keys['s']) dir = -1;
	if (keys['w']) dir =  1;

	if (dir)
	{
		float x_offset = player.delta_x * PLAYER_MOVEMENT_SPEED * dir;
		float y_offset = player.delta_y * PLAYER_MOVEMENT_SPEED * dir; 

		int map_x = player.x / TILE_SIZE;
		int map_y = player.y / TILE_SIZE;
		int new_map_x = (player.x + x_offset) / TILE_SIZE;
		int new_map_y = (player.y + y_offset) / TILE_SIZE;

		if (!map_index(new_map_x, map_y))
			player.x += x_offset;
		if (!map_index(map_x, new_map_y))
			player.y += y_offset;
	}
}

void init_player()
{
	player.x = WIDTH / 2;
	player.y = HEIGHT / 2;

	player.delta_x = 1.0;
	player.delta_y = 0.0;

	player.angle_degrees = 0;
	player.angle_radians = 0.0;
}

void draw_player()
{
	float red[] = { 1, 0, 0 };
	glColor3fv(red);
	draw_circle(player.x, player.y, PLAYER_RADIUS);

	float yellow[] = { 1, 1, 0 };
	glColor3fv(yellow);
	draw_line(player.x, player.y, player.x + player.delta_x * 20, player.y + player.delta_y * 20);
}

void updt_player()
{
	if (keys['j'])	map_mode = 1;
	else			map_mode = 0;

	turn_player();
	move_player();
}
