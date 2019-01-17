#include "Screen.h"
#include<iostream>

namespace quarternibble{
Screen::Screen(): m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer(NULL), m_buffer2(NULL){
	
}

bool Screen::init(){
	if(SDL_Init(SDL_INIT_VIDEO) < 0){
		std::cout << "SDL init failed..." << std::endl;
		return false;
	}
	
	this->m_window = SDL_CreateWindow("Particle Fire Explosion",
										SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
										SCREEN_WIDTH, SCREEN_HEIGHT,
										SDL_WINDOW_SHOWN);
										
	if(this->m_window == NULL){
		SDL_Quit();
		printf("could not create window %s\n", SDL_GetError());
		return false;
	}
	
	this->m_renderer = SDL_CreateRenderer(this->m_window, -1, SDL_RENDERER_PRESENTVSYNC);
	this->m_texture = SDL_CreateTexture(this->m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
	
	if(this->m_renderer == NULL){
		SDL_DestroyWindow(this->m_window);
		SDL_Quit();
		printf("could not create renderer %s\n", SDL_GetError());
		return false;
	}
	
	if(this->m_texture == NULL){
		SDL_DestroyRenderer(this->m_renderer);
		SDL_DestroyWindow(this->m_window);
		SDL_Quit();
		printf("could not create texture %s\n", SDL_GetError());
		return false;
	}
	
	this->m_buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
	this->m_buffer2 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
	
	memset(this->m_buffer, 0x0, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));
	memset(this->m_buffer2, 0x0, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));
	
	this->m_buffer[30000] = 0x0000ffff; // 0xrrggbbaa
	
	for(int i = 0; i < SCREEN_WIDTH*SCREEN_HEIGHT; i++){
		this->m_buffer[i] = 0x000000ff;
	}
	
	SDL_UpdateTexture(this->m_texture, NULL, this->m_buffer, SCREEN_WIDTH*sizeof(Uint32));
	SDL_RenderClear(this->m_renderer);
	SDL_RenderCopy(this->m_renderer, this->m_texture, NULL, NULL);
	SDL_RenderPresent(this->m_renderer);
	return true;	
}

bool Screen::processEvent(){
	SDL_Event event;
	
	while(SDL_PollEvent(&event)){
		if(event.type == SDL_QUIT){
			return false;
		}
	}
	
	return true;
}

void Screen::close(){
	delete [] this->m_buffer;
	delete [] this->m_buffer2;
	SDL_DestroyRenderer(this->m_renderer);
	SDL_DestroyTexture(this->m_texture);
	SDL_DestroyWindow(this->m_window);
	SDL_Quit();
}

void Screen::update(){
	SDL_UpdateTexture(this->m_texture, NULL, this->m_buffer, SCREEN_WIDTH*sizeof(Uint32));
	SDL_RenderClear(this->m_renderer);
	SDL_RenderCopy(this->m_renderer, this->m_texture, NULL, NULL);
	SDL_RenderPresent(this->m_renderer);
}

void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue){
	Uint32 color = 0;
	Uint8 alpha = 0xFF;
	
	// Poorly done, but better to do clipping
	if(x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT){
	    return;
	}
	
	color += red;
	color <<= 8;
	color += green;
	color <<= 8;
	color += blue;
	color <<= 8;
	color += alpha;
	
	this->m_buffer[(y * SCREEN_WIDTH) + x] = color;
}

void Screen::clear(){
    memset(this->m_buffer, 0 , SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
    memset(this->m_buffer2, 0 , SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
}

void Screen::boxBlur(){
    // swap buffers so pixel info is in m_buffer2 and we are drawing to m_buffer2
    Uint32 *temp = this->m_buffer;
    this->m_buffer = this->m_buffer2;
    this->m_buffer2 = temp;
    
    for(int y = 0; y < quarternibble::Screen::SCREEN_HEIGHT; y++){
        for(int x = 0; x < quarternibble::Screen::SCREEN_WIDTH; x++){
            /*
             * 0 0 0
             * 0 1 0
             * 0 0 0
             */
             
             int redTotal = 0;
             int greenTotal = 0;
             int blueTotal = 0;
             
             for(int row = -1; row <= 1; row++){
                for(int col = -1; col <= 1; col++){
                    int currentX = x + col;
                    int currentY = y + row;
                    
                    if(currentX >= 0 && currentX < quarternibble::Screen::SCREEN_WIDTH && currentY >= 0 && currentY < quarternibble::Screen::SCREEN_HEIGHT){
                       Uint32 color = m_buffer2[currentY * quarternibble::Screen::SCREEN_WIDTH + currentX];
                       
                       Uint8 red = color >> 24; // gets red value 0xRRGGBB
                       Uint8 green = color >> 16;
                       Uint8 blue = color >> 8;
                      
                       redTotal += red;
                       greenTotal += green;
                       blueTotal += blue;
                    }
                    
                    // getting color of pixel at current location
                }
             }
             
             Uint8 red = redTotal / 9;
             Uint8 green = greenTotal / 9;
             Uint8 blue = blueTotal / 9;
             
             setPixel(x, y, red, green, blue);
        }
    }
}
}
