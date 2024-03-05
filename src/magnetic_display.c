#include <SDL2/SDL.h>
#include <stdio.h>

#include "enemy.h"


void magnetic_display(SDL_Renderer* renderer)
{
	t_enemy* search = g_first_enemy;	
	while (search != NULL)
	{
		if(search->magnetic)
		{
			magnetic_display_single(search, renderer);
		}
		search = search->next;
	}
}

void magnetic_display_single(t_enemy* enemy, SDL_Renderer* renderer)
{
	if(enemy == NULL || renderer == NULL)
		return;

	SDL_Rect dest;
	dest.x = enemy->x;
	dest.y = enemy->y;
	dest.w = ENEMY_W;
	dest.h = ENEMY_H;

	SDL_Rect src;
	src.x = 300;
	src.y = 300;
	src.w = MAGNETIC_PIXEL_W;
	src.h = MAGNETIC_PIXEL_H;
	SDL_RenderCopy(renderer,enemy->texture,&src,&dest);
}

void hitbox_magnetic(SDL_Renderer* renderer)
{
	t_enemy* search = g_first_enemy;	
	while (search != NULL)
	{	
		if(search->magnetic)
		{
			hitbox_magnetic_single(search, renderer);
		}
		search = search->next;
	}
}

void hitbox_magnetic_single(t_enemy* enemy, SDL_Renderer* renderer)
{
	if(enemy == NULL || renderer == NULL)
		return;

	
	float pos_x1, pos_y1 , pos_x2, pos_y2, pos_x3, pos_y3 , pos_x4 , pos_y4 ;

	get_corner_enemy(enemy, &pos_x1, &pos_y1 , &pos_x2, &pos_y2, &pos_x3, &pos_y3 , &pos_x4 , &pos_y4);
	
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	
	SDL_RenderDrawLine(renderer, pos_x1, pos_y1, pos_x2, pos_y2);
	SDL_RenderDrawLine(renderer, pos_x2, pos_y2, pos_x3, pos_y3);
	SDL_RenderDrawLine(renderer, pos_x3, pos_y3, pos_x4, pos_y4);
	SDL_RenderDrawLine(renderer, pos_x4, pos_y4, pos_x1, pos_y1);
	
}

void get_corner_enemy(t_enemy* enemy, float* pos_x1, float* pos_y1, float* pos_x2, float* pos_y2, float* pos_x3, float* pos_y3, float* pos_x4, float* pos_y4)
{
	 *pos_x1 = enemy->x + ENEMY_W/2 + (-ENEMY_W/2 * cos((0) * M_PI/180)) - (-ENEMY_H/2 * sin((0) * M_PI/180));
	 *pos_y1 = enemy->y + ENEMY_H/2 + (-ENEMY_W/2 * sin((0) * M_PI/180)) + (-ENEMY_H/2 * cos((0) * M_PI/180));
		
	 *pos_x2 = enemy->x + ENEMY_W/2 + (ENEMY_W/2 * cos((0) * M_PI/180)) - (-ENEMY_H/2 * sin((0) * M_PI/180));
	 *pos_y2 = enemy->y + ENEMY_H/2 + (ENEMY_W/2 * sin((0) * M_PI/180)) + (-ENEMY_H/2 * cos((0) * M_PI/180));

	 *pos_x3 = enemy->x + ENEMY_W/2 + (ENEMY_W/2 * cos((0) * M_PI/180)) - (ENEMY_H/2 * sin((0) * M_PI/180));
	 *pos_y3 = enemy->y + ENEMY_H/2 + (ENEMY_W/2 * sin((0) * M_PI/180)) + (ENEMY_H/2 * cos((0) * M_PI/180));

	 *pos_x4 = enemy->x + ENEMY_W/2 + (-ENEMY_W/2 * cos((0) * M_PI/180)) - (ENEMY_H/2 * sin((0) * M_PI/180));
	 *pos_y4 = enemy->y + ENEMY_H/2 + (-ENEMY_W/2 * sin((0) * M_PI/180)) + (ENEMY_H/2 * cos((0) * M_PI/180));
}



