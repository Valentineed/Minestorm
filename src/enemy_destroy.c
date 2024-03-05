#include "enemy.h"
#include <stdio.h>

extern t_enemy* g_first_enemy;

void enemy_destroy(t_enemy* enemy)
{
	if (enemy == NULL)
	{
		return;
	}
	if(enemy == g_first_enemy)
	{
		g_first_enemy = enemy->next;
	}
	else
	{
		enemy->prev->next = enemy->next;
		if(NULL != enemy->next)
		{
			enemy->next->prev = enemy->prev;
		}
	}
	SDL_FreeSurface(enemy->surface);
	SDL_DestroyTexture(enemy->texture);
	free(enemy);
}
