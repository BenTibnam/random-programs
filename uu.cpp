/**
 * does all the updating in one command
 * great for lazy updates
 */

#include<iostream>
#include<stdlib.h>
#include<ctime>

void wait(long s){
	long st = time(0);
	long t = 0;
	
	while(1){
		t = time(0);
		if(t >= st+s){
			break;
		}
	}
}


int main(){
	system("sudo apt update --assume-yes");
	system("sudo apt upgrade --assume-yes");
	system("sudo apt autoremove --assume-yes");
	
	printf("rebooting in 5 seconds\n");
	wait(1);
	for(int i = 4; i > 0; i--){
		printf("rebooting in %d seconds\n", i);
		wait(1);
	}
	
	system("init 6");
	return 0;
}
