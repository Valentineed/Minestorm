#include "enemy.h"

extern t_enemy* g_first_enemy;

void floating_move(float delta)
{
	t_enemy* search = g_first_enemy;	
	while (search != NULL)
	{
		if(!search->magnetic)
			floating_move_single(search, delta);
		
		search = search->next;
	}
}

void floating_move_single(t_enemy* enemy, float delta)
{
	if(enemy == NULL)
	{
		return;
	}
	enemy->x += cos(enemy->angle*M_PI/180) * delta * enemy->speed ;
	enemy->y += sin(enemy->angle*M_PI/180) * delta * enemy->speed ;
	
	if(enemy->y < 0 + ENEMY_W/2)
	{
		enemy->y = WINDOW_H - ENEMY_W/2;
	}
	else if(enemy->y > WINDOW_H - ENEMY_W/2)
	{
		enemy->y = 0 + ENEMY_H/2;
	}
	if(enemy->x <= 0 - ENEMY_W/2)
	{
		enemy->x = WINDOW_W - ENEMY_W/2;
		
	}
	else if(enemy->x > WINDOW_W + ENEMY_W/2)
	{
		enemy->x = 0 + ENEMY_W/2;
		
	}
}
