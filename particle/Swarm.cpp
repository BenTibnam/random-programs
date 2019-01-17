#include "Swarm.h"

Swarm::Swarm(): lastTime(0){
    this->m_pParticles = new Particle[NPARTICLES];
}

Swarm::~Swarm(){
    delete [] this->m_pParticles;
}

void Swarm::update(int elapsed){
    int interval = elapsed - this->lastTime;

    for(int i = 0; i < Swarm::NPARTICLES; i++){
        this->m_pParticles[i].update(interval);
    }
    
    this->lastTime = elapsed;
}
