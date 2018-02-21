#include<stdbool.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

const int MIN = 0;
const int MAX = 1;
const int LEN = 4;

// Representation of LEDs
class Light{
  private:
    int port;
    int value;
    int stat;
    bool sorted;
  public:
    int getPort();
    int getValue();
    int getStat();
    bool getSorted();
    void setStat(int);
    void setSorted(bool);
    void setPort(int);
    void blinkLight(int);
    void blinkDuelLight(Light, int);
    void on();
    void off();
    Light(int, int, int, bool);
    Light();
};

int Light::getPort(){return this->port;}
int Light::getValue(){return this->value;}
int Light::getStat(){return this->stat;}
bool Light::getSorted(){return this->sorted;}
void Light::setStat(int amt){this->stat = amt;}
void Light::setSorted(bool val){this->sorted = val;}
void Light::setPort(int num){this->port = num;}

Light::Light(int p, int v, int s, bool sort)
:port(p), value(v), stat(s), sorted(sort)
{
    
}

Light::Light(){
    
}

void Light::on(){
  this->stat = MAX;
  digitalWrite(this->port, this->stat);  
}

void Light::off(){
  this->stat = MIN;
  digitalWrite(this->port, this->stat);
}

void Light::blinkLight(int ms){
  int opp = (this->stat == MAX) ? MIN : MAX;
  int curr = this->stat;

  digitalWrite(this->port, opp);
  delay(ms);
  digitalWrite(this->port, curr);
  delay(ms);
}

void Light::blinkDuelLight(Light l, int ms){
  l.on();
  this->on();
  delay(ms);
  l.off();
  this->off();
  delay(ms);
  if(l.getSorted()) l.on();
  if(this->getSorted()) this->on();
}


Light light(3, 1, MIN, false);

// sorts array through selection and than returns sorted array
Light* selection(Light arr[], int n){  
    int len = n;
    Light* sorted = arr;
    Light temp, curr, tempValHold;
    int start, small, tempValPort1, tempValPort2;
    
    for(int i = 0; i < len; i++){
        temp = sorted[i];
        start = small = i;
        light.blinkDuelLight(temp, 250);
        light.blinkDuelLight(temp, 250);
        
        for(int j = i+1; j < len; j++){
            curr = sorted[j];
            temp.blinkLight(250);
            curr.blinkLight(250);
            if(curr.getValue() < temp.getValue()){
                temp.on();
                curr.off();
                for(int i = 0; i < 2; i++) temp.blinkDuelLight(curr, 250);
                small = j;
                temp = curr;
                curr.off();
                temp.off();
            }
        }
        
        tempValHold = sorted[start];
        tempValPort1 = tempValHold.getPort();
        tempValPort2 = sorted[small].getPort();
        
        sorted[start] = sorted[small];
        sorted[start].setPort(tempValPort1);
        sorted[small] = tempValHold;
        sorted[small].setPort(tempValPort2);
        sorted[start].on();
        sorted[start].setSorted(true);
    }


    sorted[len-1].on();
    delay(1000);
    
    return sorted;
}

Light* insertion(Light arr[], int n){
  Light* sorted = arr;
  Light temp;
  int j;
  
  for(int i = 1; i < n; i++){
    j = i;
    sorted[j].blinkDuelLight(sorted[j-1], 1000);
    while(j > 0 && sorted[j-1].getValue() > sorted[j].getValue()){
      for(int i = 0; i < 3; i++) sorted[j].blinkDuelLight(sorted[j-1], 250);
      temp = sorted[j];
      int tempPort = temp.getPort();
      int backPort = sorted[j-1].getPort();
      sorted[j] = sorted[j-1];
      sorted[j].setPort(tempPort);
      sorted[j-1] = temp;
      sorted[j-1].setPort(backPort);
      j--;
    }
  }
  
  return sorted;
}

Light light2(4, 3, MIN, false);
Light light3(5, 6, MIN, false);
Light light4(6, 5, MIN, false);
Light light5(7, 2, MIN, false);
Light light6(8, 4, MIN, false);
Light light7(9, 1, MIN, false);

Light lights[] = {light2, light3, light4, light5, light6, light7};

void setup(){
    // power on test
    light.blinkLight(100);
    for(Light l : lights) l.blinkLight(100);
}

void loop(){
  Light* sortOne = selection(lights, 6);
  Light* sortTwo = insertion(lights, 6);

  lights[0] = light2;
  lights[1] = light3;
  lights[2] = light4;
  lights[3] = light5;
  lights[4] = light6;
  lights[5] = light7;
  for(Light l : lights)l.off();
} 