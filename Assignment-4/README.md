# Assignment 4
#### Q1. (1 × 8+2 points) Write declaration for the following: a pointer to a character, an array of 10 integers, a reference to an array of 10 integers, a pointer to an array of character strings, a pointer to a pointer to a character, a constant integer, a pointer to a constant integer, a constant pointer to an integer, an a constant pointer to a constant double. Initialize each one.
> #### Solution: [Problem 1](Q1_Declaration.c)

---

#### Q2. (3 Points) Explain the output of this program.

```cpp
#include <iostream>
   int main()
   {
       const char* str1 = "We love C++ programming\n";
       char str2[100];
       char *p = str2;/*name of an array is implicitly converted
                       to pointer to the first element.*/
       while(*p++ = *str1++){}
       std::cout << str2;
   }
```
Ans: In this program we are taking an pointer to constant char and soring the string "We love C++ programming" in the string then we ar declaring another string str2 with 100 characters bound.
We are declaring another pointer p that is pointing to str2 base location.

Then in a while loop we are incrementing the location of the p and str1 and assigning the orevious value of str1 in p and printing the whole sting stored in memory. The loop terminates when the loop encounters '\0'.

> #### Solution: [Problem 2](Q2_Explain.cpp)

---

#### Q3. (2+2 points) Explain the output and the errors, if any.

```cpp
#include <iostream>
   const char* createString(){
       return "Practice makes a man perfect";
   }
   int* createInt(){
       int x = 100;
return &x; }
   int main(){
       const char *str = createString();
       std::cout << "string = " << str << std::endl;
       int *ip = createInt();
       std::cout << "integer = " << *ip << std::endl;
}
```
Ans: In this program we are returning the pointer of a variable that is local to  the 'createInt' function. We know that c program stores the local variables in the stack memory and they get deleted after goes out of the scope. 
```cpp
int* createInt(){
    int x = 100;
    return &x;
}
```
> #### Solution: [Problem 3](Q3_Explain_Errors.cpp)

---

#### Q4. (3 points) The following program generates runtime error. Explain the reason(s) and rectify the program.
```cpp
int main() {
       char *str = "India vs Pakistan, Asia Cup 2023";
       str[7] = ’V’;
       double darr[] = {2.3, 4.5, 5.5};
       *(darr+3) = 6.5;
       extern float f;
       float g = f * 100.5;
       short int i = 89;
       void *v = &i;
       int *ip = static_cast<int*>(v);
       cout << "integer = " << *ip;
}
```

1. `str[7] = 'V'` : str was declared as a pinter  to string literal
2. `*(darr+3) = 6.5` : This line attempts to change the index 3 of darr but the bound of the array is 2
3. `extern float f` : The line declares an external float variable `f` but doesn't provide a defination in the code.
4. `int *ip = static_cast<int*>(v)` : This line uses `static_cast` to cast a `void*` to an `int*`. But originally the i was in `short

> #### Solution: [Problem 4](Q4_Error_explain_and_correct.cpp)

---

#### Q5. (1+1 points) Write a function that swaps (exchanges the values of) two integers. Use int* as the argument type. Write another swap function using int& as the argument type.

> #### Solution: [Problem_5](Q5_Swapping.cpp)

---

#### Q6. (3 points) Define a table of the names of months of an year and the number of days in each month. Print out this table. Do this twice: once using an array of char for the names and an array for the days and once using an array of structures, with the structure containing the name of the month and the number of days in it.

> #### Solution: [Problem 6](Q6_Months.cpp)
