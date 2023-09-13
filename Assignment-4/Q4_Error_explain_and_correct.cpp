#include<iostream>
extern float f; //declare the external float variable
int main() {
    //char *str = "India vs Pakistan, Asia Cup 2023";   
    char str[] = "India vs Pakistan, Asia Cup 2023";    //changed the declaration of `str` from a pointer to an array  to allow modification
    str[7] = 'V';
    double darr[] = {2.3, 4.5, 5.5};
    *(darr+2) = 6.5; //3 was out of bound 2 was the bound of the array 

    //extern float f; //float f not available
    float f;
    float g = f * 100.5; 

    short int i = 89;
    void *v = &i;
    short int *ip = static_cast<short int*>(v); //casting to short int 
    std::cout << "integer = " << *ip;
}
/*
1. `str[7] = 'V'`: str was declared as a pinter  to string literal
2. `*(darr+3) = 6.5: This line attempts to change the index 3 of darr but the bound of the array is 2
3. `extern float f`: The line declares an external float variable `f` but doesn't provide a defination in the code.
4. `int *ip = static_cast<int*>(v)`: This line uses `static_cast` to cast a `void*` to an `int*`. But originally the i was in `short int` format so we have to cast the v(void*) to `short int*` for getting the correct results.
*/
