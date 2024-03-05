#include "../include/player.h"
#include <math.h>

void player_moving(t_player* player,float delta)
{
	if (player == NULL)
	{
		return;
	}
	player->speed += player->acceleration * delta;

	if(player->speed > player->max_speed)
	{
		player->speed = player->max_speed;
	}
	if(player->speed < 0)
	{
		player->speed = 0;
	}

	player->x += cos(player->angle*M_PI/180)  * player->speed * delta;
	player->y += sin(player->angle*M_PI/180)  * player->speed * delta;


	if(player->y < 0 - PLAYER_W)
	{
		player->y = WINDOW_H;
	}
	if(player->y > WINDOW_H + PLAYER_W)
	{
		player->y = 0 - PLAYER_H;
	}
	if(player->x <= 0 - PLAYER_H - 4)
	{
		player->x = WINDOW_W;
		
	}
	if(player->x > (WINDOW_W + PLAYER_W))
	{
		player->x = 0 - PLAYER_H;
		
	}

}
void player_teleportation(t_player* player)
{

	player->x +=  cos(player->angle*M_PI/180) * 300;
	player->y +=  sin(player->angle*M_PI/180)  * 300;


	if(player->y <= 0 - PLAYER_W)
	{
		player->y += WINDOW_H;
	}
	if(player->y >= WINDOW_H + PLAYER_W)
	{
		player->y -= WINDOW_H;
	}
	if(player->x <= 0 - PLAYER_H - 4)
	{
		player->x += WINDOW_W;
		
	}
	if(player->x >= (WINDOW_W + PLAYER_W))
	{
		player->x -= WINDOW_W;
		
	}
}

