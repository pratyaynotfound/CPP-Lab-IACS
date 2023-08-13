#include<iostream>
using namespace std;

int main(){
    //declare a variable
    double y;
    
    //take input
    cout<<"Enter a number:"<<endl;
    cin>>y;
    
    //evaluate the expression
    double x = y-20*6/9;//original
    double x_changed = y-20.0*6/9;
    
    //print the outputs
    cout<<"Result:"<<x<<endl;
    cout<<"Changed Result:"<<x_changed<<endl;
    
    return 0;
}
