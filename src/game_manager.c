#include "../include/game_manager.h"
#include "../include/game.h"
#include "../include/menu.h"
#include "../include/arguments.h"
#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
void launch()
{
	t_loop loop;
	set_loop_to_menu(&loop);

	Uint32 previous = 0;
	bool quit = false;
	while(false == quit)
	{
		Uint32 current = SDL_GetTicks();
		float delta = (current - previous)/1000.0;
		previous = current;


		quit = loop.process();
		loop.update(delta);
		loop.render();
	}
}

