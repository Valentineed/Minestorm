#ifndef __MENU_LOOP
#define __MENU_LOOP

#include "../include/game_manager.h"
#include <stdbool.h>

void set_loop_to_menu(t_loop* loop);
void menu_display();
bool menuProcess();
void menuUpdate(float delta);

#endif

