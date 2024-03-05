#ifndef __INTERNAL
#define __INTERNAL

#include <stdbool.h>

bool create_entities_fail();

bool create_renderer_fail();

bool init_fail();

void init_global();

bool init_graphic_fail();

bool load_background_fail();

bool load_missile_fail();

bool load_font_fail();

bool load_menu_fail();

bool load_pause_fail();

bool load_gameover_fail();

void quit();

void set_null();

#endif // __INTERNAL

