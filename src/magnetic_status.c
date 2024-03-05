#include "enemy.h"

#include <SDL2/SDL.h>
#include <time.h>
#include <stdio.h>

t_enemy* magnetic_fireball_mine_create(SDL_Renderer* renderer)
{
	t_enemy* enemy = magnetic_create(renderer);
	enemy->fire = true;
	return enemy;
	
}
t_enemy* magnetic_create(SDL_Renderer* renderer)
{
	t_enemy* new_enemy = malloc(sizeof(t_enemy));
	if(new_enemy == NULL)
	{
		printf("malloc fail\n");
	}
	magnetic_init(new_enemy, renderer);

	t_enemy * search = g_first_enemy;
	if (search != NULL)//verify if the enemy is the last
	{	
		while (search->next != NULL)
		{
			search = search->next;
		}
		//Set previous : new_enemy
		new_enemy->prev = search;
		search->next = new_enemy;
	}
	else
	{	
		g_first_enemy = new_enemy;
	}	
	return new_enemy;
}

void magnetic_init(t_enemy* enemy, SDL_Renderer* renderer)
{
	int pos_x = rand() % WINDOW_W - 100;
	int pos_y = rand() % WINDOW_H - 100;
	
	if(enemy == NULL || renderer == NULL)
		return;	
	
	enemy->life = ENEMY_LIFE;
	
	enemy->x = pos_x;

	enemy->y = pos_y;
	
	enemy->speed = 30;
	
	enemy->direction = 0;

	enemy->dir_x = 5;
	enemy->dir_y = 5;

	enemy->magnetic = true;
	enemy->fire = false;
	enemy->next = NULL;
	enemy->prev = NULL;
	
	enemy->surface = IMG_Load(MAGNETIC_IMAGE);
	enemy->texture = SDL_CreateTextureFromSurface(renderer, enemy->surface);
	
}


