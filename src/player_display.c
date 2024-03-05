#include <SDL2/SDL.h>
#include <stdio.h>

#include "player.h"


void player_display(t_player* player, SDL_Renderer* renderer){

	player_display_position(player, renderer);
	player_display_lives(player, renderer);
}

void player_display_position(t_player* player, SDL_Renderer* renderer){

	SDL_Rect dest;
	dest.x = player->x;
	dest.y = player->y;
	dest.w = PLAYER_W;
	dest.h = PLAYER_H;
	SDL_RenderCopyEx(renderer,player->texture,NULL,&dest,player->angle,NULL,SDL_FLIP_NONE);
}

void hitbox_player(t_player* player, SDL_Renderer* renderer)
{
	if(player == NULL || renderer == NULL)
		return;
	
	
	float pos_x1, pos_y1 , pos_x2, pos_y2, pos_x3, pos_y3 , pos_x4 , pos_y4 ;
	get_corner_player(player, &pos_x1, &pos_y1 , &pos_x2, &pos_y2, &pos_x3, &pos_y3 , &pos_x4 , &pos_y4);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	
	SDL_RenderDrawLine(renderer, pos_x1, pos_y1, pos_x2, pos_y2);
	SDL_RenderDrawLine(renderer, pos_x2, pos_y2, pos_x3, pos_y3);
	SDL_RenderDrawLine(renderer, pos_x3, pos_y3, pos_x4, pos_y4);
	SDL_RenderDrawLine(renderer, pos_x4, pos_y4, pos_x1, pos_y1);
	
	
}
void get_corner_player(t_player* player, float* pos_x1, float* pos_y1, float* pos_x2, float* pos_y2, float* pos_x3, float* pos_y3, float* pos_x4, float* pos_y4)
{
	*pos_x1 = player->x + PLAYER_W/2 + (-PLAYER_W/2 * cos((player->angle) * M_PI/180)) - (-PLAYER_H/2 * sin((player->angle) * M_PI/180));
	*pos_y1 = player->y + PLAYER_H/2 + (-PLAYER_W/2 * sin((player->angle) * M_PI/180)) + (-PLAYER_H/2 * cos((player->angle) * M_PI/180));

	*pos_x2 = player->x + PLAYER_W/2 + (PLAYER_W/2 * cos((player->angle) * M_PI/180)) - (-PLAYER_H/2 * sin((player->angle) * M_PI/180));
	*pos_y2 = player->y + PLAYER_H/2 + (PLAYER_W/2 * sin((player->angle) * M_PI/180)) + (-PLAYER_H/2 * cos((player->angle) * M_PI/180));

	*pos_x3 = player->x + PLAYER_W/2 + (PLAYER_W/2 * cos((player->angle) * M_PI/180)) - (PLAYER_H/2 * sin((player->angle) * M_PI/180));
	*pos_y3 = player->y + PLAYER_H/2 + (PLAYER_W/2 * sin((player->angle) * M_PI/180)) + (PLAYER_H/2 * cos((player->angle) * M_PI/180));
	
	*pos_x4 = player->x + PLAYER_W/2 + (-PLAYER_W/2 * cos((player->angle) * M_PI/180)) - (PLAYER_H/2 * sin((player->angle) * M_PI/180));
	*pos_y4 = player->y + PLAYER_H/2 + (-PLAYER_W/2 * sin((player->angle) * M_PI/180)) + (PLAYER_H/2 * cos((player->angle) * M_PI/180));
}

void player_display_lives(t_player* player, SDL_Renderer* renderer){
	for(int i = 0; i < player->life; i++)
	{
		SDL_Rect dest;
		dest.x = PLAYER_LIFE_X + (PLAYER_W + PLAYER_LIFE_SP) * i;
		dest.y = FOOTER_Y + 300;
		dest.w = PLAYER_W;
		dest.h = PLAYER_H;
		SDL_RenderCopy(renderer, player->texture, NULL, &dest);
	}
}
