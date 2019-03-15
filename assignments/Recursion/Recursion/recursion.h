#include <iostream>
void writeUp(int number){
    if(number == 0)
        return;
    else{
        writeUp(number - 1);
        std::cout << number << std::endl;
    }
    
    
}

void writeDown(int number){
    if(number == 0)
        return;
    else{
        std::cout << number << std::endl;
        writeDown(number - 1);
    }
}

int factorial(int number){
    if(number == 0)
        return 1;
    else {
        return number * factorial(number - 1);
    }
}

int Fib(int number){
    if(number <= 1)
        return 1;
    else
    {
        return Fib(number-1)+Fib(number-2); 
    }
}
