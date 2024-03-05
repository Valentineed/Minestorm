#ifndef __MISSILE
#define __MISSILE


#include "arguments.h"
#include "player.h"

#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <math.h>

typedef struct s_missile
{
	float x;
	float y;
	float speed_x;
	float speed_y;
	float speed;
	float time_left;
	float angle;

	struct s_missile* next;


} t_missile;

void missile_display(SDL_Renderer* renderer);
void hitbox_missile(SDL_Renderer* renderer);
void hitbox_single_missile(t_missile* missile, SDL_Renderer* renderer);
void get_corner_missile(t_missile* missile, float* pos_x1, float* pos_y1, 
float* pos_x2, float* pos_y2, float* pos_x3, float* pos_y3, float* pos_x4, float* pos_y4);

void missile_add(const t_player* player);
void missile_destroy(t_missile* missile);
void missile_move(float delta);
void missile_destroy_all();
bool missile_move_single(t_missile* missile, float delta);
void missile_display_single(t_missile* missile, SDL_Renderer* renderer);
#endif // __MISSILE

