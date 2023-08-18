#include<iostream>
using namespace std;
int main(){
    long double x;
    unsigned int k;
    //take inputs
    cout<<"Please enter a floating point number:"<<endl;
    cin>>x;
    cout<<"Enter a positive k: "<<endl;
    cin>>k;

    //rounding off
    x = (long int)(x*k+0.5);
    x= x/k;
    printf("Rounded off to the %d th place: %Lf",k,x);
    return 0;
}