#include <iostream>
const char* createString(){
    return "Practice makes a man perfect";
}
int* createInt(){
    int x = 100;
    return &x;
}
int main(){
    const char *str = createString();
    std::cout << "string = " << str << std::endl;
    int *ip = createInt();
    std::cout << "integer = " << *ip << std::endl;
}
/*
In this program we are returning the pointer of a variable that is local to  the 'createInt' function. We know that c program stores the local variables in the stack memory and they get deleted after goes out of the scope. 
*/