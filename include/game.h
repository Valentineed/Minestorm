#ifndef __GAME_LOOP
#define __GAME_LOOP

#include "menu.h"
#include "game_manager.h"
#include "enemy.h"
#include <stdbool.h>

void reset_game();

void gameUpdate(float delta);

void setLoopToGame1(t_loop* loop);
void setLoopToGame2(t_loop* loop);

bool game1Process();
void pause_display();
void gameover_display();
void game_display();
void game_output();
void check_colision();
void missile_enemy_collision(t_enemy* enemy);
void player_enemy_collision(t_enemy* enemy);
void play_round(float delta);
void move_player(float delta);
void move_enemy(float delta);
void move_missile(float delta);
void input_manager();

#endif

