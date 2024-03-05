#ifndef __PLAYER__
#define __PLAYER__
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "arguments.h"
#include <math.h>

typedef struct s_player
{
	int life;
	
	float x;
	float y;

	float acceleration;
	float angle;
	float speed;
	float max_speed;
	float rotation_speed;
	

	SDL_Surface* surface;

	SDL_Texture* texture;

} t_player;

void player_display(t_player* player, SDL_Renderer* renderer);
void player_display_position(t_player* player, SDL_Renderer* renderer);
void player_display_lives(t_player* player, SDL_Renderer* renderer);
void hitbox_player(t_player* player, SDL_Renderer* renderer);
void get_corner_player(t_player* player, float* pos_x1, float* pos_y1, 
float* pos_x2, float* pos_y2, float* pos_x3, float* pos_y3, float* pos_x4, float* pos_y4);

bool is_player_alive(t_player* player);

t_player* player_create(SDL_Renderer* renderer);

void player_destroy(t_player* player);

void player_turn(t_player* player,float delta);

void player_moving(t_player* player,float delta);

void player_teleportation(t_player* player);

void player_init(t_player* player, SDL_Renderer* renderer);

#endif
