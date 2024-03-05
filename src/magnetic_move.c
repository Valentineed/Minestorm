#include "enemy.h"
#include "player.h"
#include <math.h>

extern t_player* player;

void magnetic_move(float delta)
{
	t_enemy* search = g_first_enemy;	
	while (search != NULL)
	{
		if(search->magnetic)
		{
			magnetic_move_single(search,player, delta);
		}
		search = search->next;
	}

}
void magnetic_move_single(t_enemy* enemy, t_player* player, float delta)
{
	if(enemy == NULL)
	{
		return;
	}//TODO bonus: magnetic mine go to through window
	enemy->dir_x = player->x - enemy->x;
	enemy->dir_y = player->y - enemy->y;
	float hyp = sqrt(enemy->dir_x * enemy->dir_x + enemy->dir_y * enemy->dir_y);
	enemy->dir_x /= hyp;
	enemy->dir_y /= hyp;
	enemy->x += enemy->dir_x * enemy->speed * delta;
	enemy->y += enemy->dir_y * enemy->speed * delta;
	
	if(enemy->y < 0 - ENEMY_W)
	{
		enemy->y = WINDOW_H;
	}
	if(enemy->y > WINDOW_H + ENEMY_W)
	{
		enemy->y = 0 - ENEMY_H;
	}
	if(enemy->x <= 0 - ENEMY_H - 4)
	{
		enemy->x = WINDOW_W;
		
	}
	if(enemy->x > (WINDOW_W + ENEMY_W))
	{
		enemy->x = 0 - ENEMY_H;
		
	}
}
