#include "internal.h"
#include "arguments.h"
#include "game_manager.h"
#include "player.h"
#include "enemy.h"
#include "missile.h"

#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>

SDL_Window* window;
SDL_Renderer* renderer;

SDL_Surface* background_surface;
SDL_Texture* background_texture;


SDL_Surface* pause_surface;
SDL_Texture* pause_texture;

SDL_Surface* gameover_surface;
SDL_Texture* gameover_texture;

SDL_Texture* menu_texture;
SDL_Surface* menu_surface;


SDL_Texture* missile_texture;
SDL_Surface* missile_surface;

TTF_Font* font;

// Global
t_enemy* g_first_enemy;
bool g_player_shoot = false;
bool g_player_tp = false;
bool g_hitbox = false;
bool g_pause;
int player_score;
int g_current_level;

// entities
t_player* player;
t_missile* g_missile;

int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	if(init_fail())
	{
		printf("\n>>>>> init fail\n");
		quit();
		printf(">>>>> quit successfully done\n");
		printf(">>>>> exit with: EXIT_FAILURE\n\n");
		return EXIT_FAILURE;
	}

	launch();
	
	quit();
	printf("\n>>>>> quit successfully done\n");
	printf(">>>>> exit with: EXIT_SUCCESS\n\n");
	return EXIT_SUCCESS;
}

bool init_fail()
{
	set_null();
	
	srand(time(NULL));

	init_global();

	if(init_graphic_fail())
		return true;

	return create_entities_fail();
}

void init_global()
{
	g_first_enemy = NULL;
	g_player_shoot = false;
	g_player_tp = false;
	g_hitbox = false;
	g_pause = false;
	init_arrays();
	player_score = 0;
	g_current_level = 0;
}

bool init_graphic_fail()
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
		return true;

	if(create_renderer_fail())
		return true;

	if(load_menu_fail())
		return true;

	if(load_background_fail())
		return true;

	if(load_missile_fail())
		return true;

	if(load_pause_fail())
		return true;
	
	if(load_gameover_fail())
		return true;

	return load_font_fail();
}

bool create_renderer_fail()
{
	window = SDL_CreateWindow("Mine Storm",
			SDL_WINDOWPOS_CENTERED,
		       	SDL_WINDOWPOS_CENTERED,
			WINDOW_W,
			WINDOW_H,
		       	SDL_WINDOW_SHOWN);
	if(!window)
		return true;

	renderer = SDL_CreateRenderer(window, 0,
		       SDL_RENDERER_PRESENTVSYNC);
	return !renderer;
}

bool load_menu_fail()
{
	menu_surface = IMG_Load(MENU_IMAGE);
	if(!menu_surface)
		return true;
	menu_texture = SDL_CreateTextureFromSurface(
			renderer, menu_surface);
	
	return !menu_texture;
}

bool load_background_fail()
{
	background_surface = IMG_Load(BACKGROUND_IMAGE);
	if(!background_surface)
		return true;

	background_texture = SDL_CreateTextureFromSurface(
			renderer, background_surface);
	return !background_texture;
}

bool load_missile_fail()
{
	missile_surface = IMG_Load(MISSILE_IMAGE);
	if(!missile_surface)
		return true;

	missile_texture = SDL_CreateTextureFromSurface(
			renderer, missile_surface);
	return !missile_texture;
}

bool load_pause_fail()
{
	pause_surface = IMG_Load(PAUSE_IMAGE);
	if(!pause_surface)
		return true;

	pause_texture = SDL_CreateTextureFromSurface(
			renderer, pause_surface);
	return !pause_texture;
}

bool load_gameover_fail()
{
	gameover_surface = IMG_Load(GAMEOVER_IMAGE);
	if(!gameover_surface)
		return true;

	gameover_texture = SDL_CreateTextureFromSurface(
				renderer, gameover_surface);
	
	return !gameover_texture;
}

bool load_font_fail()
{

	if(TTF_Init() < 0)
		return true;

	font = TTF_OpenFont(FONT_TTF, 24);
	return !font;
}

bool create_entities_fail()
{
	player = player_create(renderer);
	if(!player)
	{
		return true;
	}
	return false;
}


void set_null()
{
	window = NULL;
	renderer = NULL;

	background_surface = NULL;
	background_texture = NULL;

	missile_surface = NULL;
	missile_texture = NULL;

	pause_surface = NULL;
	pause_texture = NULL;

	menu_texture = NULL;
	menu_surface = NULL;

	gameover_surface = NULL;
	gameover_texture = NULL;

	player = NULL;
	g_missile = NULL;
}

void quit()
{
	
	player_destroy(player);
	missile_destroy_all();

	SDL_DestroyTexture(menu_texture);
	SDL_DestroyTexture(background_texture);
	SDL_DestroyTexture(pause_texture);
	SDL_DestroyTexture(missile_texture);
	SDL_DestroyTexture(gameover_texture);

	SDL_FreeSurface(menu_surface);
	SDL_FreeSurface(background_surface);
	SDL_FreeSurface(missile_surface);
	SDL_FreeSurface(pause_surface);
	SDL_FreeSurface(gameover_surface);

	SDL_DestroyRenderer(renderer);

	SDL_DestroyWindow(window);

	TTF_CloseFont(font);

	TTF_Quit();
	SDL_Quit();
}

