#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<ctime>
#include "SDL.h"
#include "Screen.h"
#include "Swarm.h"


int main(int argc, char* argv[]){
	quarternibble::Screen screen;
	srand(time(NULL));
	
	if(screen.init() == false){
		std::cout << "Error init screen" << std::endl;
		return 1;
	}
	
	bool quit = false;
	SDL_Event event;
	
	Swarm swarm;
	
	
	while(!quit){
	    int elapsed = SDL_GetTicks();   // returns number of milliseconds since program started
        
		// update particles
		swarm.update(elapsed);
		// draw particles
	    
	    const Particle * const pParticles = swarm.getParticles();
	   
	    unsigned char green = (1 +sin(elapsed * 0.0001)) * 128 ;       // returns value between -1 and 1 multiplies by 0.001 to reduce numbers we jump around with
		unsigned char red = (1+sin(elapsed*0.0002)) * 128;
		unsigned char blue = (1+sin(elapsed*0.0003)) * 128;
	 
	    for(int i = 0; i < Swarm::NPARTICLES; i++){
	        Particle particle = pParticles[i];
	        int x = (particle.m_x + 1) * (quarternibble::Screen::SCREEN_WIDTH/2.0);
	        int y = (particle.m_y * quarternibble::Screen::SCREEN_WIDTH/2.0) + quarternibble::Screen::SCREEN_HEIGHT/2;
	        
	        screen.setPixel(x, y, red, green, blue);
	    }
	    
	    /*
		for(int y = 0; y < quarternibble::Screen::SCREEN_HEIGHT; y++){
			for(int x = 0; x < quarternibble::Screen::SCREEN_WIDTH; x++){
				screen.setPixel(x, y, red , green, blue);
			}
		}*/
		
		screen.setPixel(400, 300, 255, 255, 255);
		screen.boxBlur();
		// draw on screen
		screen.update();
		
		// check for messages and events
		
		if(!screen.processEvent()){
			quit = true;
		}
	}
	
	screen.close();
}
