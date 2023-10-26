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
> - c: X x2 {}
> - It seems to be creating an instance of x and initializing it with an empty list, but ```struct X``` doesnot have a constructor that takes no arguments, but it does have a coonstructor that takes integer arguments. Since there is no constructor that matches the empty initializer list, this statement is erroneous.

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
struct foo{
    foo(){
        cout<<"foo()\n;"
    }
    ~foo(){
        cout<<"~foo()\n;"
    }
    int i{5};
}
struct obj{
    const foo& getFoo(){
        return my_foo;
    };
    foo my_foo;
}
int main(){
    obj *o = new obj();
    const foo& val = o->getfoo();
    cout<<"val.i="<<val.i<<std::endl;
    delete 0;
    cout<<"val.i="<<val.i<<std::endl;
}
```
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
    constexpr X& operator = (const X&){
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