#ifndef PARTICLE_H_
#define PARTICLE_H_
class Particle{
public:
    double m_x;
    double m_y;
  
    double m_speed;    
    double m_direction;
public:
    Particle();
    void update(int interval);
    
private:
    void init();
};
#endif
