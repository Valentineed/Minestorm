#include "../include/player.h"

void player_init(t_player* player, SDL_Renderer* renderer)
{
	if (player == NULL)
	{
		return;
	}
	
	player->angle = 0;	
	
	player->life = PLAYER_LIFE;
	
	player->x = (GAME_W/2 - PLAYER_W/2) +1;

	player->y = (WINDOW_H/2);

	player->surface = IMG_Load(PLAYER_IMAGE);
	
	player->acceleration = 0;

	player->max_speed = 250;

	player->rotation_speed = 0;

	player->texture = SDL_CreateTextureFromSurface(renderer, player->surface);
}

