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

void raycast()
{
	int ray_angle = player.angle_degrees - 30;
	for (int i = 0; i < 60; ++i, ++ray_angle)
	{
		fix_angle(&ray_angle);
		float ray_angle_radians = radians(ray_angle);

		float	ray_x = (float) player.x / TILE_SIZE,
				ray_y = (float) player.y / TILE_SIZE;

		float	ray_dir_x = cos(ray_angle_radians),
				ray_dir_y = sin(ray_angle_radians);

		float	step_size_x = sqrt(1.0 + sqr(ray_dir_y / ray_dir_x)),
				step_size_y = sqrt(1.0 + sqr(ray_dir_x / ray_dir_y));

		int		map_check_x = ray_x,
				map_check_y = ray_y;
		
		float	ray_length_x,
				ray_length_y;

		int		step_x,
				step_y;

		if (ray_dir_x < 0)
		{
			step_x = -1;
			ray_length_x = (ray_x - (float)map_check_x) * step_size_x;
		}
		else
		{
			step_x = 1;
			ray_length_x = ((float)map_check_x + 1.0 - ray_x) * step_size_x;
		}

		if (ray_dir_y < 0)
		{
			step_y = -1;
			ray_length_y = (ray_y - (float)map_check_y) * step_size_y;
		}
		else
		{
			step_y = 1;
			ray_length_y = ((float)map_check_y + 1.0 - ray_y) * step_size_y;
		}

		bool tile_found = false;
		float distance = 0;
		float max_distance = max(MAP_W, MAP_H);

		while (!tile_found && distance < max_distance)
		{
			if (ray_length_x < ray_length_y)
			{
				map_check_x += step_x;
				distance = ray_length_x;
				ray_length_x += step_size_x;
			}
			else
			{
				map_check_y += step_y;
				distance = ray_length_y;
				ray_length_y += step_size_y;
			}

			if (map_check_x >= 0 && map_check_x < MAP_W &&
				map_check_y >= 0 && map_check_y < MAP_H)
			{
				if (map_index(map_check_x, map_check_y))
				{
					tile_found = 1;
				}
			}
		}

		float intersection_x,
			  intersection_y;
		if (tile_found)
		{
			intersection_x = ray_x + ray_dir_x * distance;
			intersection_y = ray_y + ray_dir_y * distance;

			draw_line(player.x, player.y, intersection_x * TILE_SIZE, intersection_y * TILE_SIZE);
		}
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
