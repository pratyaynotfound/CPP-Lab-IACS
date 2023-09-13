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
/*In this program we are taking an pointer to constant char and soring the string "We love C++ programming" in the string then we ar declaring another string str2 with 100 characters bound.
We are declaring another pointer p that is pointing to str2 base location.

Then in a while loop we are incrementing the location of the p and str1 and assigning the orevious value of str1 in p and printing the whole sting stored in memory. The loop terminates when the loop encounters '\0'*/