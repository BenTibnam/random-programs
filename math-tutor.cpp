// your own personal basic math tutor

#include<iostream>
#include<stdlib.h>
#include<ctime>

/* all the data for equation */
typedef struct equation{
    char op;
    int i1;
    int i2;
} equation;

/* prints an equation without an answer */
void printEquation(int a, int b, char op){
    std::cout << "    " << a << '\n';
    std::cout << op << "   " <<  b << '\n';
    std::cout << "---------" << '\n';
}

/* prints an equation with an answer */
void printAnswer(int a, int b, int c, char op){
    printEquation(a, b, op);
    std::cout << "    " << c << "\n";
}

/* creates an equation struct */
equation constructEquation(char op, int i1, int i2){
    equation e = {op, i1, i2};
    return e;
}

double getAnswer(char op, int i1, int i2){
    double d1 = (double) i1, d2 = (double) i2;
    if(op == '+') return d1 + d2;
    else if(op == '-') return d1 - d2;
    else if(op == '*') return d1 * d2;
    else return d1 / d2;
}

/* creates a random equation */
equation generateRandomEquation(char op, int* max){
    srand(time(0));
    int tempMax = *max;
    int rand1 = rand() % tempMax++;
    int rand2 = rand() % tempMax++;
    *max = tempMax;
    if(op == '/' && rand2 == 0) rand2 = 1;  // avoids devide by zero error
    equation e = {op, rand1, rand2};
    return e;
}



int main(){
    int opNum = -1;  // number that matches operation; 0=+, 1=-, 2=*, 3=/
    char op;

    std::cout << "Your personal math tutor\n";

    // we'll break out when conditions are met
    while(1){
        int cap = 1;
        std::cout << "Enter the number next to the operation you wish to practice on\n1.) +\n2.) -\n3.) *\n4.) /\n5.) quit program\n> ";
        std::cin >> opNum;
        opNum--;

        if(opNum == 4) break;
        else if(opNum < 0 || opNum > 3){
            std::cout << "ERR: Invalid operator selected\n";
            std::cin.clear();
            std::cin.ignore(250, '\n');
            continue;
        }else if(opNum == 5) break;
        else op = (opNum == 0) ? '+' : ((opNum == 1) ? '-' : ((opNum == 2) ? '*' : '/'));

        // once again we'll break out when conditions are met
        std::cout << "If at anytime, you wish to exit the program during execution press CTRL-Z\n\n";
        while(1){
            double userAns, ans;
            equation e = generateRandomEquation(op, &cap);
            ans = getAnswer(e.op, e.i1, e.i2);
            printEquation(e.i1, e.i2, e.op);
            std::cout << '\n';
            std::cout << "ans: ";
            std::cin >> userAns;
            std::cin.clear();
            std::cin.ignore(250, '\n');

            if((double)ans == (double)userAns) std::cout << "CORRECT!\n\n";
            else std::cout << "WRONG\n\n";

            printAnswer(e.i1, e.i2, ans, op);
            std::cout << '\n';
        }
           
    }
    
    return 0;
}
