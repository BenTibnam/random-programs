#include "stack.h"
#include<iostream>
#include<stdio.h>

int main(){
	std::string command;
	char arg, lastPop;

	while(command != "exit"){
		printf("$ ");
		std::cin >> command;
		std::cin >> arg;
		
		try{
			if(command == "push") Stack::push(arg);
			else if (command == "pop") lastPop = Stack::pop();
		} catch (Stack::Overflow) {
			printf("Error, cannot pop, stack has reached max size. Consider popping to add new value");
		}
		
	}
}
