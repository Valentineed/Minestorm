#include "../include/player.h"

t_player* player_create(SDL_Renderer* renderer)
{
	t_player* player = malloc(sizeof(t_player));
	
	player_init(player, renderer);
	
	return player;
}
