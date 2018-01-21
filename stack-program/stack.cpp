#include "stack.h"
#include <stdio.h>
#include <iostream>

namespace Stack{
	const int MAX_SIZE = 200;
	char v[MAX_SIZE];
	const int top = 0;
	int spotFilled = 0;
}

void Stack::push(char c){
	spotFilled++;
	
	if(spotFilled >= 200){
		spotFilled = MAX_SIZE;
		throw Overflow();
	}else{
		char indexBuff = v[0];
		v[0] = c;
		
		for(int i = 1; i < MAX_SIZE; i++){
			char secondIndexBuff = v[i];
			v[i] = indexBuff;
			indexBuff = secondIndexBuff;
		}
	}
}

char Stack::pop(){
	spotFilled--;
	if(spotFilled < 0){
		spotFilled = 0;
		throw Underflow();
	}else{
		for(int i = 1; i < MAX_SIZE; i++){
			v[i-1] = v[i];
		}
	} 
	
	return v[top];
}

void Stack::printStack(){
	for(char c : v) printf("%c ", c);
	printf("\n");
}

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
			else if (command == "print" || command == "echo") Stack::printStack();
		} catch (Stack::Overflow) {
			printf("Error, cannot push, stack has reached max size. Consider popping to add new value\n");
		} catch (Stack::Underflow){
			printf("Error, cannot pop, stack has reached min size. Consider adding values to pop them\n"); 
		}
	}

	return 0;
}

