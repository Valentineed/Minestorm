#ifndef __GAME
#define __GAME

#include <stdbool.h>

void launch();
typedef struct s_loop
{
	bool (*process)();
	void (*update)(float delta);
	void (*render)();

}t_loop;
#endif
