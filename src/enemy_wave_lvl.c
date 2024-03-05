#include "enemy.h"

extern SDL_Renderer* renderer;

void set_level(int level)
{
	switch(level)
	{
		case 1:
			floating_create(renderer);
			magnetic_create(renderer);
			floating_create(renderer);
			//magnetic_fireball(renderer);
			magnetic_create(renderer);
			floating_create(renderer);
			magnetic_create(renderer);
			floating_create(renderer);
			break;
		case 2:
					 	         
			floating_create(renderer);//fire true
			magnetic_create(renderer);//fire false
			floating_create(renderer);//fire true
			magnetic_create(renderer);//fire false	
			floating_create(renderer);//fire false
			magnetic_create(renderer);//fire false
			floating_create(renderer);//fire false
			break;
		case 3:
					  		        
			magnetic_create(renderer);//fire true
			floating_create(renderer);//fire true
			floating_create(renderer);//fire true
			magnetic_create(renderer);//fire false
			floating_create(renderer);//fire true
			magnetic_create(renderer);//fire false
			floating_create(renderer);//fire false
			break;
		case 4:
					  		         
			floating_create(renderer);//fire true
			magnetic_create(renderer);//fire true
			floating_create(renderer);//fire false
			magnetic_create(renderer);//fire true
			floating_create(renderer);//fire true
			magnetic_create(renderer);//fire false
			floating_create(renderer);//fire false
			break;
		case 5:
					  		         
			floating_create(renderer);//fire true
			magnetic_create(renderer);//fire true
			floating_create(renderer);//fire false
			magnetic_create(renderer);//fire false
			floating_create(renderer);//fire true
			magnetic_create(renderer);//fire false
			floating_create(renderer);//fire true
			break;
		case 6:
    
			floating_create(renderer);//fire true
			magnetic_create(renderer);//fire true
			floating_create(renderer);//fire true
			magnetic_create(renderer);//fire false
			floating_create(renderer);//fire true
			magnetic_create(renderer);//fire false 
			floating_create(renderer);//fire true
			break;
		case 7:
					  	         
			floating_create(renderer);//fire true
			magnetic_create(renderer);//fire true
			floating_create(renderer);//fire true
			magnetic_create(renderer);//fire false	
			floating_create(renderer);//fire true
			magnetic_create(renderer);//fire false
			floating_create(renderer);//fire true
			break;
		case 8:
							       
			floating_create(renderer);//fire true
			magnetic_create(renderer);//fire true
			floating_create(renderer);//fire true
			magnetic_create(renderer);//fire true
			floating_create(renderer);//fire true 
			magnetic_create(renderer);//fire false
			floating_create(renderer);//fire true
			break;
		case 9:
					  		        
			floating_create(renderer);//fire true
			magnetic_create(renderer);//fire true
			floating_create(renderer);//fire true
			magnetic_create(renderer);//fire false
			floating_create(renderer);//fire true
			magnetic_create(renderer);//fire true 
			floating_create(renderer);//fire true
			break;
		case 10:
			// all fire true
			magnetic_create(renderer);
			magnetic_create(renderer);
			magnetic_create(renderer);
			magnetic_create(renderer);
			magnetic_create(renderer);
			magnetic_create(renderer);
			magnetic_create(renderer);
			break;	
	}
}	
