#include <SDL2/SDL.h>
#include <stdio.h>

#include "missile.h"

extern t_missile* g_missile;
extern SDL_Texture* missile_texture;

void missile_display(SDL_Renderer* renderer)
{
	t_missile* search = g_missile;	
	while (search != NULL)
	{
		missile_display_single(search, renderer);
		search = search->next;
	}
}

void missile_display_single(t_missile* missile, SDL_Renderer* renderer)
{
	if(missile == NULL || renderer == NULL)
		return;

	SDL_Rect dest;
	dest.x = missile->x;
	dest.y = missile->y;
	dest.w = MISSILE_W;
	dest.h = MISSILE_H;



	SDL_RenderCopyEx(renderer,missile_texture,NULL,&dest,missile->angle,NULL,SDL_FLIP_NONE);

	

}

void hitbox_missile(SDL_Renderer* renderer)
{int i = 0;
	t_missile* search = g_missile;	
	while (search != NULL)
	{
		hitbox_single_missile(search, renderer);
		search = search->next;
		i++;
	}
}

void hitbox_single_missile(t_missile* missile, SDL_Renderer* renderer)
{
	if(missile == NULL || renderer == NULL)
		return;

	float pos_x1, pos_y1 , pos_x2, pos_y2, pos_x3, pos_y3 , pos_x4 , pos_y4 ;
	get_corner_missile(missile, &pos_x1, &pos_y1 , &pos_x2, &pos_y2, &pos_x3, &pos_y3 , &pos_x4 , &pos_y4);
	
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	
	SDL_RenderDrawLine(renderer, pos_x1, pos_y1, pos_x2, pos_y2);
	SDL_RenderDrawLine(renderer, pos_x2, pos_y2, pos_x3, pos_y3);
	SDL_RenderDrawLine(renderer, pos_x3, pos_y3, pos_x4, pos_y4);
	SDL_RenderDrawLine(renderer, pos_x4, pos_y4, pos_x1, pos_y1);
	printf("\n MISSILE == posx1:%f  posy1:%f  posx2:%f  posy2:%f  posx3:%f  posy3:%f  posx4:%f  posy4:%f\n",pos_x1,pos_y1,pos_x2,pos_y2,pos_x3,pos_y3,pos_x4,pos_y4);
	
}
void get_corner_missile(t_missile* missile, float* pos_x1, float* pos_y1, float* pos_x2, float* pos_y2, float* pos_x3, float* pos_y3, float* pos_x4, float* pos_y4)
{
	*pos_x1 = missile->x + MISSILE_W/2 + (-MISSILE_W/2 * cos((missile->angle) * M_PI/180)) - (-MISSILE_H/2 * sin((missile->angle) * M_PI/180));
	*pos_y1 = missile->y + MISSILE_H/2 + (-MISSILE_W/2 * sin((missile->angle) * M_PI/180)) + (-MISSILE_H/2 * cos((missile->angle) * M_PI/180));

	*pos_x2 = missile->x + MISSILE_W/2 + (MISSILE_W/2 * cos((missile->angle) * M_PI/180)) - (-MISSILE_H/2 * sin((missile->angle) * M_PI/180));
	*pos_y2 = missile->y + MISSILE_H/2 + (MISSILE_W/2 * sin((missile->angle) * M_PI/180)) + (-MISSILE_H/2 * cos((missile->angle) * M_PI/180));

	*pos_x3 = missile->x + MISSILE_W/2 + (-MISSILE_W/2 * cos((missile->angle) * M_PI/180)) - (MISSILE_H/2 * sin((missile->angle) * M_PI/180));
	*pos_y3 = missile->y + MISSILE_H/2 + (-MISSILE_W/2 * sin((missile->angle) * M_PI/180)) + (MISSILE_H/2 * cos((missile->angle) * M_PI/180));

	*pos_x4 = missile->x + MISSILE_W/2 + (MISSILE_W/2 * cos((missile->angle) * M_PI/180)) - (MISSILE_H/2 * sin((missile->angle) * M_PI/180));
	*pos_y4 = missile->y + MISSILE_H/2 + (MISSILE_W/2 * sin((missile->angle) * M_PI/180)) + (MISSILE_H/2 * cos((missile->angle) * M_PI/180));
}
