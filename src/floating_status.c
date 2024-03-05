#include "enemy.h"

#include <SDL2/SDL.h>
#include <time.h>
#include <stdio.h>


t_enemy* fireball_mine_create(SDL_Renderer* renderer)
{
	t_enemy* enemy = floating_create(renderer);
	enemy->fire = true;
	return enemy;
	
}
t_enemy* floating_create(SDL_Renderer* renderer)
{
	t_enemy* new_enemy = malloc(sizeof(t_enemy));
	if(new_enemy == NULL)
	{
		printf("malloc fail\n");
	}
	floating_init(new_enemy, renderer);

	t_enemy * search = g_first_enemy;
	if (search != NULL)//verify if the block is the last
	{	
		while (search->next != NULL)
		{
			search = search->next;
		}
		//Set previous : new_block
		new_enemy->prev = search;
		search->next = new_enemy;
	}
	else
	{
		g_first_enemy = new_enemy;
	};
	return new_enemy;
}

void floating_init(t_enemy* enemy, SDL_Renderer* renderer)
{
	int pos_x = rand() % WINDOW_W;
	int pos_y = rand() % WINDOW_H;
	
	
	if(enemy == NULL || renderer == NULL)
		return;	
	
	enemy->life = ENEMY_LIFE;
	
	enemy->x = pos_x;

	enemy->y = pos_y;

	enemy->dir_x = 0;

	enemy->dir_y = 0;
	
	enemy->speed = 50;
	
	enemy->angle = rand() % 360;

	enemy->magnetic = false;

	enemy->fire = false;

	enemy->next = NULL;
	enemy->prev = NULL;
	
	enemy->surface = IMG_Load(FLOATING_IMAGE);
	enemy->texture = SDL_CreateTextureFromSurface(renderer, enemy->surface);
	
}




