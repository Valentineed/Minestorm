#include "../include/player.h"

void player_destroy(t_player* player)
{
	if (player == NULL)
	{
		return;
	}

	SDL_FreeSurface(player->surface);
	SDL_DestroyTexture(player->texture);
	free(player);
}
