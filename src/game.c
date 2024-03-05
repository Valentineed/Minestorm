#include "game.h"
#include "player.h"
#include "missile.h"
#include "menu.h"
#include "enemy.h"

#include <stdio.h>
#include <unistd.h>

extern SDL_Renderer* renderer;
extern SDL_Texture* background_texture;
extern SDL_Texture* pause_texture;
extern SDL_Texture* gameover_texture;

extern t_player* player;
extern t_missile* g_missile;
extern t_enemy* g_first_enemy;

extern int g_current_level;
extern int player_score;
extern bool g_player_shoot;
extern bool g_player_tp;
extern bool g_hitbox;
extern bool g_pause;

t_loop* g_loop_game;

void reset_wave()
{	
	if(NULL == g_first_enemy)
	{
		g_current_level++;
		set_level(g_current_level);
		/*if(g_current_level = 10)
		{
			//TODO player win
		}*/
	}	
}

void setLoopToGame1(t_loop* loop)
{
	loop->process = &game1Process;
	loop->update = &gameUpdate;
	loop->render = &game_display;

	g_pause = false;
	g_loop_game = loop;
}

void setLoopToGame2(t_loop* loop)
{
	loop->process = &game1Process;//TODO implement gameprocess for 2 players
	loop->update = &gameUpdate;
	loop->render = &game_display;

	g_pause = false;
	g_loop_game = loop;
}
/*
bool game2Process()
{
	TODO

}*/
bool game1Process()
{

	
	SDL_Event event;
		while(SDL_PollEvent(&event))
		{
			
			if(event.type == SDL_WINDOWEVENT)
			if(event.window.event == SDL_WINDOWEVENT_CLOSE)
			{
				return true;
			}
			if(event.type == SDL_KEYDOWN)
			switch(event.key.keysym.sym)
			{
				case SDLK_ESCAPE:
					if(g_pause)
						set_loop_to_menu(g_loop_game);
					break;

				case SDLK_f:
					g_player_shoot = true;
					break;
				
				case SDLK_t:
					g_player_tp = true;
					break;

				case SDLK_LEFT:
					player->rotation_speed = -400;
					break;

				case SDLK_RIGHT:
					player->rotation_speed = 400;
					break;

				case SDLK_UP:
					player->acceleration = 100;
					break;
				
				case SDLK_c:
					g_hitbox = !g_hitbox;
					break;

				case SDLK_SPACE:
					g_pause = (g_pause) ? false : true;
					break;
			}
			if(event.type == SDL_KEYUP)
			switch(event.key.keysym.sym)
			{
				case SDLK_UP:
					player->acceleration = -50;
					break;	
				case SDLK_LEFT:
					player->rotation_speed = 0;
					break;

				case SDLK_RIGHT:
					player->rotation_speed = 0;
					break;				
			}
		}
		return false;
}

void gameUpdate(float delta)
{
	if(!g_pause)
	{
		play_round(delta);
		if(player->life <= 0)
		{
			gameover_display();//TODO 
		}
	}

}

void game_display()
{
	if(g_pause)
		pause_display();
	else
		game_output();
}

void gameover_display()
{
	SDL_RenderCopy(renderer, gameover_texture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

void pause_display(){

	
	SDL_RenderCopy(renderer, pause_texture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

void game_output(){

	SDL_RenderCopy(renderer, background_texture, NULL, NULL);

	player_display(player, renderer);
	floating_display(renderer); 
	magnetic_display(renderer); 
	missile_display(renderer);

	if(g_hitbox == true)
	{
		hitbox_player(player, renderer);
		hitbox_missile(renderer);

		if(g_first_enemy != NULL)
		{
			hitbox_floating(renderer);
		}
		if(g_first_enemy->next != NULL)
			hitbox_magnetic(renderer);

	}		

	SDL_RenderPresent(renderer);
}

void play_round(float delta)
{
	
	check_colision();
	move_player(delta);
	move_missile(delta);
	move_enemy(delta);
	if(NULL == g_first_enemy)
	{	
		reset_wave();
	}
}

void move_player(float delta)
{	
	player_turn(player,delta);
	player_moving(player,delta);
	if(g_player_tp == true)
	{
		
		player_teleportation(player);
		g_player_tp = false;
	}
}

void move_enemy(float delta)
{	
	t_enemy * search = g_first_enemy;
	if (search != NULL)
	{
		while(search->next != NULL)
		{
			if(true == search->magnetic)
			{
				
				magnetic_move(delta);
			}
			else
			{
				floating_move(delta);
			}/*
			if(true == search->fire)
			{
				shoot();
			}*/
			search = search->next;
		}
	}

}

void move_missile(float delta)
{
	if(g_player_shoot == true)
	{
		missile_add(player);
		g_player_shoot = false;
	}
	missile_move(delta);
}




