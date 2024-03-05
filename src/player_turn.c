#include "../include/player.h"
#include <stdio.h>

void player_turn(t_player* player,float delta){
if(DEBUG>4)printf(" -> in player_go_right\n");

	if (player == NULL)
	{
		return;
	}
	player->angle += player->rotation_speed * delta;
}


