#include "game.h"
#include "enemy.h"
#include "missile.h"
#include "player.h"
#include <stdio.h>
extern t_enemy* g_first_enemy;	
extern t_missile* g_missile;
extern t_player* player;

void check_colision()
{
	
	

	float pos_x1, pos_x2, pos_y2;
	float pos_y3;
	float m_pos_x1, m_pos_y1, m_pos_x2, m_pos_y2;
	float m_pos_x3, m_pos_y3, m_pos_x4, m_pos_y4;
	float p_pos_x1, p_pos_y1, p_pos_x2, p_pos_y2;
	float p_pos_x3, p_pos_y3, p_pos_x4, p_pos_y4;
	float delet;
	
	
	t_enemy* enemy = g_first_enemy;	
	t_missile* missile = g_missile;

	
	while(missile != NULL)
	{
		while (enemy != NULL)
		{
			get_corner_enemy(enemy, &pos_x1, &delet , &pos_x2, &pos_y2, &delet, &pos_y3 , &delet , &delet);
			t_enemy* next = enemy->next;
				
			get_corner_missile(missile, &m_pos_x1, &m_pos_y1 , &m_pos_x2, &m_pos_y2, &m_pos_x3, &m_pos_y3 , &m_pos_x4 , &m_pos_y4);
			
			if(pos_x1 <= m_pos_x1 && m_pos_x1 <= pos_x2 && pos_y2 < m_pos_y1 && m_pos_y1 <= pos_y3)
			{
				missile_enemy_collision(enemy);
			}
			else if(pos_x1 <= m_pos_x2 && m_pos_x2 <= pos_x2 && pos_y2 <= m_pos_y2 && m_pos_y2 <= pos_y3)
			{
				missile_enemy_collision(enemy);
			}
			else if(pos_x1 <= m_pos_x3 && m_pos_x3 <= pos_x2 && pos_y2 <= m_pos_y3 && m_pos_y3 <= pos_y3)
			{
				missile_enemy_collision(enemy);
			}
			else if(pos_x1 <= m_pos_x4 && m_pos_x4 <= pos_x2 && pos_y2 <= m_pos_y4 && m_pos_y4 <= pos_y3)
			{
				missile_enemy_collision(enemy);
			}
			enemy = next;
		}
		missile = missile->next;
	}

	while (enemy != NULL)
	{
		get_corner_enemy(enemy, &pos_x1, &delet , &pos_x2, &pos_y2, &delet, &pos_y3 , &delet , &delet);
		t_enemy* next = enemy->next;
		
		get_corner_player(player, &p_pos_x1, &p_pos_y1 , &p_pos_x2, &p_pos_y2, &p_pos_x3, &p_pos_y3 , &p_pos_x4 , &p_pos_y4);

		if(pos_x1 <= p_pos_x1 && p_pos_x1 <= pos_x2 && pos_y2 < p_pos_y1 && p_pos_y1 <= pos_y3)
		{
			player_enemy_collision(enemy);
		}
		else if(pos_x1 <= p_pos_x2 && p_pos_x2 <= pos_x2 && pos_y2 <= p_pos_y2 && p_pos_y2 <= pos_y3)
		{
			player_enemy_collision(enemy);
		}
		else if(pos_x1 <= p_pos_x3 && p_pos_x3 <= pos_x2 && pos_y2 <= p_pos_y3 && p_pos_y3 <= pos_y3)
		{
			player_enemy_collision(enemy);
		}
		else if(pos_x1 <= p_pos_x4 && p_pos_x4 <= pos_x2 && pos_y2 <= p_pos_y4 && p_pos_y4 <= pos_y3)
		{
			player_enemy_collision(enemy);
		}

		enemy = next;
	}
}

void missile_enemy_collision(t_enemy* enemy)
{
	enemy_destroy(enemy);
	
}

void player_enemy_collision(t_enemy* enemy)
{
	enemy_destroy(enemy);
	player->life --;
	
}

/*while(missile != NULL)
	{	//prendre les position du missile
		get_corner_missile(missile, &m_pos_x1, &delet , &m_pos_x2, &m_pos_y2, &delet, &m_pos_y3 , &delet , &delet);
		get_corner_player(player, &p_pos_x1, &p_pos_y1 , &p_pos_x2, &p_pos_y2, &p_pos_x3, &p_pos_y3 , &p_pos_x4 , &p_pos_y4);

		if(m_pos_x1 <= p_pos_x1 && p_pos_x1 <= m_pos_x2 && m_pos_y2 < p_pos_y1 && p_pos_y1 <= m_pos_y3)
		{
			player->life --;
		}
		else if(m_pos_x1 <= p_pos_x2 && p_pos_x2 <= m_pos_x2 && m_pos_y2 <= p_pos_y2 && p_pos_y2 <= m_pos_y3)
		{
			player->life --;
		}
		else if(m_pos_x1 <= p_pos_x3 && p_pos_x3 <= m_pos_x2 && m_pos_y2 <= p_pos_y3 && p_pos_y3 <= m_pos_y3)
		{
			player->life --;
		}
		else if(m_pos_x1 <= p_pos_x4 && p_pos_x4 <= m_pos_x2 && m_pos_y2 <= p_pos_y4 && p_pos_y4 <= m_pos_y3)
		{
			player->life --;
		}
		missile = missile->next;
	}*/

