#include<iostream>
//swapping using the pointer variables
void swap_1(int *a,int *b){
    *b = *b + *a;
    *a = *b - *a;
    *b = *b - *a;
}
//swapping using the reference variables 
void swap_2(int &a,int &b){
    b = b + a;
    a = b - a;
    b = b - a;
}
int main(){
    int x,y,x1,y1;
    //take the input
    std::cout<<"Enter x & y:"<<std::endl;
    std::cin>>x>>y;

    //duplicate the inputs for 2 functions
    x1 = x;
    y1 = y;

    //1st swapping
    swap_1(&x,&y);
    std::cout<<"Out 1:\nx :"<<x<<std::endl;
    std::cout<<"y :"<<y<<std::endl;

    //2nd swapping
    swap_2(x1,y1);
    std::cout<<"Out 2:\nx :"<<x<<std::endl;
    std::cout<<"y :"<<y<<std::endl;
}
