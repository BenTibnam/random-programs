#include<time.h>

/* causes the program to pause in a loop for s seconds */
void wait(int s){
  int startTime = time();
  while((time(0) - startTime) != s);
}
