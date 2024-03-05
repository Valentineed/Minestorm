#ifndef __ARGUMENTS
#define __ARGUMENTS

//-----------------------------------------//
//--------------STATIC VALUE---------------//
//-----------------------------------------//
#define WINDOW_W 550//OK
#define WINDOW_H 750//OK

#define GAME_W 100
#define GAME_H 68

#define BACKGROUND_IMAGE "resource/wallpaper.png"//OK
#define PAUSE_IMAGE "resource/pause.png"//OK
#define GAMEOVER_IMAGE "resource/gameover.png"

#define MENU_W 69
#define MENU_H 24
#define MENU_IMAGE "resource/menu.png"
#define MENU_IMAGE_W 345
#define MENU_IMAGE_H 480

#define PLAYER_W 35//ok
#define PLAYER_H 25//ok
#define PLAYER_Y 69
#define PLAYER_SPEED 5
#define PLAYER_LIFE 3
#define PLAYER_LIFE_X 78 // WINDOW_W - WINDOW_SP - (PLAYER_W + PLAYER_LIFE_SP) * PLAYER_LIFE + PLAYER_LIFE_SP 
#define PLAYER_LIFE_SP 2
#define PLAYER_IMAGE "resource/player2png.png"

#define ENEMY_W 30
#define ENEMY_H 30
#define ENEMY_BIG_SIZE 60
#define ENEMY_MEDIUM_SIZE 40
#define ENEMY_SMALL_SIZE 20
#define FLOATING_PIXEL_W 100
#define FLOATING_PIXEL_H 100
#define MAGNETIC_PIXEL_W 100
#define MAGNETIC_PIXEL_H 100
#define ENEMY_LIFE 1
#define FLOATING_IMAGE "resource/enemy.png"
#define MAGNETIC_IMAGE "resource/enemy.png"
#define ENEMY_IMAGE_EXPLOSION "resource/enemy_explosion.png"

#define SHIELD_W 2
#define SHIELD_H 2
#define SHIELD_COL_QTY 4
#define SHIELD_ROW_QTY 3
#define SHIELD_QTY 4

#define SHIELD_IMAGE_5 "resource/shield5.png"
#define SHIELD_IMAGE_4 "resource/shield4.png"
#define SHIELD_IMAGE_3 "resource/shield3.png"
#define SHIELD_IMAGE_2 "resource/shield2.png"
#define SHIELD_IMAGE_1 "resource/shield1.png"

#define MISSILE_W 15//OK
#define MISSILE_H 5//OK
#define MISSILE_SPEED 500//OK
#define MISSILE_IMAGE "resource/missile.png"

#define FOOTER_Y 385 // GAME_H + player

#define FONT_TTF "resource/Retro Gaming.ttf"

//-----------------------------------------//
//-------------DYNAMIC VALUE---------------//
//-----------------------------------------//

#define MENU_X_D (WINDOW_W/2 - MENU_W/2 +1) * PIXEL_SIZE
#define MENU_Y_D (WINDOW_H/2 - MENU_H/2 +1) * PIXEL_SIZE
#define MENU_W_D MENU_W * PIXEL_SIZE
#define MENU_H_D MENU_H * PIXEL_SIZE

#define SHIELD_X_SP GAME_W / SHIELD_QTY
#define SHIELD_X SHIELD_X_SP / 2 + 1 - (SHIELD_COL_QTY / 2) * SHIELD_W
#define SHIELD_Y ENEMY_ROW_H *2

#define DEBUG 0

#endif // __ARGUMENTS

