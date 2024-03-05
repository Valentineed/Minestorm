#include <SDL2/SDL.h>
#include <stdio.h>

#include "enemy.h"

void floating_display(SDL_Renderer* renderer)
{
	t_enemy* search = g_first_enemy;	
	while (search != NULL)
	{
		if(!search->magnetic)
		{
			floating_display_single(search, renderer);
		
		}
		search = search->next;
	}
}

void floating_display_single(t_enemy* enemy, SDL_Renderer* renderer)
{

	
	if(enemy == NULL || renderer == NULL)
		return;

	SDL_Rect dest;
	dest.x = enemy->x;
	dest.y = enemy->y;
	dest.w = ENEMY_W;
	dest.h = ENEMY_H;
	SDL_Rect src;
	src.x = 400;
	src.y = 1000;
	src.w = FLOATING_PIXEL_W;
	src.h = FLOATING_PIXEL_H;
	SDL_RenderCopy(renderer,enemy->texture,&src,&dest);
}

void hitbox_floating(SDL_Renderer* renderer)
{
	t_enemy* search = g_first_enemy;	
	while (search != NULL)
	{
		if(!search->magnetic)
		{
			hitbox_floating_single(search, renderer);
		}
		search = search->next;
	}
}

void hitbox_floating_single(t_enemy* enemy, SDL_Renderer* renderer)
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
