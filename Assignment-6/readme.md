# Assignment 6

## Q1: Consider the following structure defination:
```cpp
struct X{
    X(int) {};
}
```
Which of the following are erroneous C++ statements and why?
```bash
a: X x0;
b: X x1 {1};
c: X x2 {};
d: X x3(1);
```
### Ans: 
> - a: X x0;
> - c: X x2 {};
> - It seems to be creating an instance of x and initializing it with an empty list, but ```struct X``` doesnot have a constructor that takes no arguments, but it does have a coonstructor that takes integer arguments. Since there is no constructor that matches the empty initializer list, this statement is erroneous.
> - And the first one is erroneous because in the presence of user-defined constructor the compiler generated constructor gets deleted. So there is no constructor that accepts an instance of x that has no constructor arguments.

## Q2: Consider the following structure defination:
```cpp
struct S{
    S(const char*) {};
    S(double*){};
}
```
Which of the following C++ statements(s) will result in an ambiguous overload resolution and why?
```bash
a: S s1 {"hello"};
b: S s1 {new double(1.5)};
c: S s1 {nullptr};
d: S s1 {(char*)nullptr};
```
### Ans: 
> 1. c: S s1 {nullptr};
> 2. d: S s1 {(char*)nullptr};
> - For (1) we can say that ```nullptr``` can be treated as any type. So this results an ambiguity. And for (2) it is also the same as the ```nullptr``` can be casted as any type though it is casted to ```(char*)```. So this also results to an ambiguity.
## Q3: Explain the output of the program. Find an error.
```cpp
#include<iostream>
using namespace std;
struct foo{
    foo(){
        cout<<"foo()\n";
    }
    ~foo(){
        cout<<"~foo()\n";
    }
    int i {5};
};
struct obj{
    const foo& getFoo(){
        return my_foo;
    };
    foo my_foo;
};
int main(){
    obj *o = new obj();
    const foo& val = o->getFoo();
    cout<<"val.i="<<val.i<<std::endl;
    delete o;
    cout<<"val.i="<<val.i<<std::endl;
}
```
> Ans:
> - There are some errors:
> 1. The ```#include<iostream>``` is not present.
> 2. ```using naespace std``` is not present.
```zsh
pratyaysarkar@Pratyays-MacBook-Air CPP % cd "/Users/pratyaysarkar/Library/CloudStorage/OneDrive-Personal/CPP/Tests/" && g++ 1.cpp -o 1 && "/Users/pratyaysarkar/Library/CloudStorage/OneDrive-Personal/CP
P/Tests/"1
foo()
val.i=5
~foo()
val.i=0
pratyaysarkar@Pratyays-MacBook-Air Tests % 
```
> Explain: In the main fucntion we create one instance of obj that is ```o```, then we call the member function and get one instance of ```foo``` that is stored inside ```val```, at this time the constructor of ```foo``` is called automatically and prints ```foo()``` in the console then we print the value of i in val by ```cout<<"val.i="<<val.i<<std::endl;``` then the object o is deleted. At this time the distructor of ```foo``` gets called automatically and ```~foo()``` is printed in the console, then again we try to print the value of i in ```val``` but it becomes a dangling pointer now as the foo object is deleted, so it prints 0 in the console.
## Q4: Explain the output of the program.
```cpp
#include<iostream>
using namespace std;
struct X{
    X(){
        cout<<"default constructor\n";
    };
    X(X&& x){
        cout<<"move constructor\n";
    };
    X(const X&x){
        cout<<"copy constructor\n";
    };
    X& operator = (const X&){
        cout<<"copy assignment\n";
        return *this;
    };
    ~X(){
        cout<<"Destructor\n";
    };
};
X foo(X x){
    return x;
}
int main(){
    X obj;
    obj = foo(obj);
}
```
> Output: 
> ```bash
> default constructor
> copy constructor
> move constructor
> copy assignment
> Destructor
> Destructor
> Destructor
> ```
> In the main function we create a object of X by ```X obj``` at this time the constructor is invoked and ```default constructor``` gets printed automatically. Then we copy obj in x by function call (```foo(obj)```) at this time copy constructor is invoked and we get ```copy constructor``` in console. Then the reference of temporary x in ```foo``` is returned in the main and move constructor is invoked and ```move constructor``` gets printed in the console. Then by the ```obj = foo(obj)``` the copy assignment constructor is invoked and ```copy assignment``` gets printed. At last we get 3 ```Dustructor``` because of 3 objects getting out of scope that are-
> 1. obj (in main).
> 2. x (returned).
> 3. temporary x in foo.

## Q5: Explain the output of the program.
```c++
#include<iostream>
using namespace std;
class X{
    public:
    X(){
        cout<<"constructor of X\n";
    };
    ~X(){
        cout<<"destructor of X\n";
    };
};
X& foo(){
    X *obj = new X[3];
    return obj[0];
}
int main(){
    X x = foo();
}
```
