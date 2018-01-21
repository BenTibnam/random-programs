#include "stack.h"
#include <stdio.h>
#include <iostream>

namespace Stack{
	const int MAX_SIZE = 200;
	char v[MAX_SIZE];
	int top = -1;
}

void Stack::push(char c){
	top++;
	if(top >= MAX_SIZE) throw Overflow();
	else v[top] = c;
}

char Stack::pop(){
	top--;
	if(top < 0) throw Underflow();
	else{
		for(int i = 1; i < MAX_SIZE; i++){
			v[i-1] = v[i];
		}
	} return v[top];
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

