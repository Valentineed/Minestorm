#ifndef __FLOATING_MINE__
#define __FLOATING_MINE__
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <math.h>

#include "arguments.h"
#include "player.h"

typedef enum mine_type
{
	MT_floating = 0,
	MT_floating_fire,
	MT_magnetic,
	MT_magnetic_fire,

	MT_max//keep end 
}e_mine_type;

typedef struct s_enemy
{
	struct s_enemy* prev;	
	struct s_enemy* next;

	float x;
	float y;
	float direction;
	float speed;
	float angle;
	float dir_x;
	float dir_y;
	int score;
	int life;
	bool magnetic;	
	bool fire;
	
	SDL_Surface* surface;
	
	SDL_Texture* texture;


} t_enemy;

t_enemy* g_first_enemy;

typedef enum mine_size
{
	MS_big = ENEMY_BIG_SIZE,
	MS_medium = ENEMY_MEDIUM_SIZE,
	MS_small = ENEMY_SMALL_SIZE
}e_mine_size;


void enemy_set_enum_size(t_enemy* enemy);
void set_level(int level);
void init_arrays();
int get_speed(enum mine_size);
int get_point(enum mine_size, enum mine_type);

//-------------------------------------------------------|
void floating_move(float delta);//			 |floating
void floating_move_single(t_enemy* enemy, float delta);//|_move.c
//-------------------------------------------------------|

t_enemy* fireball_mine_create(SDL_Renderer* renderer);
t_enemy* floating_create(SDL_Renderer* renderer);
void floating_init(t_enemy* enemy, SDL_Renderer* renderer);

//----------------------------------------------------------------------|
void floating_display(SDL_Renderer* renderer);//			|
void floating_display_single(t_enemy* enemy, SDL_Renderer* renderer);// |floating
void hitbox_floating(SDL_Renderer* renderer);//				|_display.c
void hitbox_floating_single(t_enemy* enemy, SDL_Renderer* renderer);//	|
//----------------------------------------------------------------------|

t_enemy* magnetic_fireball_mine_create(SDL_Renderer* renderer);
t_enemy* magnetic_create(SDL_Renderer* renderer);
void magnetic_init(t_enemy* enemy, SDL_Renderer* renderer);

//-------------------------------------------------------------------------|
void magnetic_move(float delta);//					   |magnetic
void magnetic_move_single(t_enemy* enemy, t_player* player, float delta);//|_move.c
//-------------------------------------------------------------------------|

//----------------------------------------------------------------------|
void magnetic_display(SDL_Renderer* renderer);//			|
void magnetic_display_single(t_enemy* enemy, SDL_Renderer* renderer);// |magnetic
void hitbox_magnetic(SDL_Renderer* renderer);//			        |_display.c
void hitbox_magnetic_single(t_enemy* enemy, SDL_Renderer* renderer);//  |
void get_corner_enemy(t_enemy* enemy, float* pos_x1, float* pos_y1, 
float* pos_x2, float* pos_y2, float* pos_x3, float* pos_y3, 
float* pos_x4, float* pos_y4);//					|
//----------------------------------------------------------------------|

void enemy_destroy(t_enemy* enemy);

#endif
