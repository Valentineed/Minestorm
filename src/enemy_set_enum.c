#include "enemy.h"

int __speed[3];
int __point[3][4];

void init_arrays()
{
	__speed[0] = 100;//big
	__speed[1] = 200;//medium
	__speed[2] = 300;//small

	__point[0][0] = 100;//big floating
	__point[0][1] = 325;//big floating fire
	__point[0][2] = 500;//big magnetic
	__point[0][3] = 750;//big magnetic fire

	__point[1][0] = 135;//medium floating
	__point[1][1] = 360;//medium floating fire
	__point[1][2] = 535;//medium magnetic
	__point[1][3] = 585;//medium magnetic fire

	__point[2][0] = 200;//small floating
	__point[2][1] = 425;//small floating fire
	__point[2][2] = 600;//small magnetic
	__point[2][3] = 850;//small magnetic fire
}

int get_speed(e_mine_size size)
{
	return __speed[size];
}

int get_point(e_mine_size size, e_mine_type type)
{
	return __point[size][type];
}
