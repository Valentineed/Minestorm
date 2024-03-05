#include "../include/menu.h"
#include "../include/arguments.h"
#include "../include/game_manager.h"
#include "../include/game.h"
#include <SDL2/SDL.h>
#include <stdbool.h>

extern SDL_Renderer* renderer;
extern SDL_Texture* background_texture;
extern SDL_Texture* menu_texture;

t_loop* g_loop;

void set_loop_to_menu(t_loop* loop)
{
	loop->process = &menuProcess;
	loop->update = &menuUpdate;
	loop->render = &menu_display;

	g_loop = loop;
}

bool menuProcess()
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
				return true;

			case SDLK_f:
				setLoopToGame1(g_loop);
				break;

			case SDLK_k:
				setLoopToGame2(g_loop);
				break;
		}
	}
	return false;
}

void menuUpdate(float delta)
{
	(void)delta;
}

void menu_display()
{

	SDL_RenderCopy(renderer, menu_texture, NULL, NULL);
	SDL_RenderPresent(renderer);
}


