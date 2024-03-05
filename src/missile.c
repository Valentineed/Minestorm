#include "missile.h"
#include <stdlib.h>
#include <stdio.h>

extern t_missile* g_missile;

void missile_add(const t_player* player)
{

	t_missile* missile = malloc(sizeof(t_missile));
	if(missile == NULL)
		return;
	if(player == NULL)
		return;
	
	missile->next = NULL;
	
	t_missile* search = g_missile;
	if (search != NULL)
	{	
		while (search->next != NULL)
		{
			search = search->next;
		}
		search->next = missile;
	}
	else
	{
		g_missile = missile;
	}
printf("missile create\n");

	missile->x = player->x;
	missile->y = player->y;
	missile->speed_x = cos(player->angle*M_PI/180) * MISSILE_SPEED;
	missile->speed_y = sin(player->angle*M_PI/180) * MISSILE_SPEED;
	missile->time_left = 0.8*WINDOW_W/MISSILE_SPEED;
	missile->angle = player->angle;
}
void missile_destroy_all()
{
	t_missile* search = g_missile;	
	while (search != NULL)
	{
		t_missile* temp = search;
		search = search->next;
		missile_destroy(temp);
	}
}
void missile_destroy(t_missile* missile)
{
	if(missile == NULL)
		return;
	printf("missile_destroy\n");
	free(missile);
}

void missile_move(float delta)
{
	t_missile* search = g_missile;	
	while (search != NULL)
	{
		bool is_destroy = missile_move_single(search, delta);
		if(is_destroy)
		{
			g_missile = g_missile->next;//since we are adding missile at the tail, only head missile can expire.
		}
		search = search->next;
	}

}
bool missile_move_single(t_missile* missile, float delta)
{
	missile->time_left = missile->time_left - delta;
	if(missile->time_left <= 0)
	{
		missile_destroy(missile);
		return true;
	}

	missile->x += missile->speed_x * delta;
	missile->y += missile->speed_y * delta;

	if(missile->y < 0 - MISSILE_H - 4)
	{
		missile->y = WINDOW_H - MISSILE_H - 4;
	}
	if(missile->y > WINDOW_H - MISSILE_H - 4)
	{
		missile->y = 0 - MISSILE_H - 4;
	}
	if(missile->x < 0 - MISSILE_H - 4)
	{
		missile->x = WINDOW_W - MISSILE_H;
		
	}
	if(missile->x > (WINDOW_W - MISSILE_H))
	{
		missile->x = 0 - MISSILE_H - 4;
		
	}

	return false;
}
