#include<iostream>
using namespace std;
int main(){
    float x ;
    unsigned int k;
    //take inputs
    cout<<"Please enter a floating point number:"<<endl;
    cin>>x;

    cout<<"Enter a positive k: "<<endl;
    cin>>k;

    //rounding off
    x = (int)(x*k+0.5);
    x = x/k;
    cout<<"Rounded off to the"<<k<<"th place: "<<x<<endl;
    return 0;
}