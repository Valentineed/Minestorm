#include "../include/player.h"

bool is_player_alive(t_player* player)
{
	return player->life == 0;
}
