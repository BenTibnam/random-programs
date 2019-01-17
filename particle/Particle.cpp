#include "Particle.h"
#include "Screen.h"
#include <stdlib.h>
#include <ctime>

Particle::Particle(): m_x(0), m_y(0){   
    init();
}

void Particle::init(){
    this->m_x = 0;
    this->m_y = 0;
    this->m_direction = (2 * M_PI * rand()) / RAND_MAX;
    this->m_speed = (0.04 * rand()) / RAND_MAX;
    
    // squaring speed to make it more ragged, so the average distance of the particles are more distan
    this->m_speed *= this->m_speed; 
}

void Particle::update(int interval){
    const double CURL = 0.0004;
    this->m_direction += interval * CURL; // adds curl to particles

    double xspeed = m_speed * cos(m_direction);
    double yspeed = m_speed * sin(m_direction);
     
    this->m_x += xspeed * interval;
    this->m_y += yspeed * interval;
    
    if(m_x < -1 || m_x > 1 || m_y < -1 || m_y > 1){
       init();
    }
    
    if(rand() < RAND_MAX/100){
        init();
    }
}
