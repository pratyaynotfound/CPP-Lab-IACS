#include<iostream>
using namespace std;

int main(){
    double x;//declare a variable
    //take the input
    cout<<"Please enter a real number:"<<endl;
    cin>>x;
    //calculate and print the result in console
    cout<<"Result:"<<x+(1/(x+(1/(x+1/x))))<<endl;
    return 0;
}