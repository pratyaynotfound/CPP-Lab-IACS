#include<iostream>
using namespace std;

int main(){
    double y;
    cout<<"Enter a number:"<<endl;
    cin>>y;
    double x = y-20*6/9;//original
    double x_changed = y-20.0*6/9;
    cout<<"Result:"<<x<<endl;
    cout<<"Changed Result:"<<x_changed<<endl;
    return 0;
}