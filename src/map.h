#ifndef __MAP_H
#define __MAP_H
#include "include.h"
#include "vars.h"
#include "draw.h"

#define TILE_SIZE 40
#define MAP_W (WIDTH / TILE_SIZE)
#define MAP_H (HEIGHT / TILE_SIZE)
#define MAP_LEN (MAP_W * MAP_H)

extern int map[MAP_LEN];

int map_index(int x, int y);
void draw_map();
#endif
