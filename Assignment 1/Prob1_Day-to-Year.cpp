#include<iostream>
using namespace std;

int main(){
    int x;//declare variable
    //taking input
    cout<<"Please Enter a year:"<<endl;
    cin>>x;
    //calculate and print the output
    cout<<x/365<<" year "<<(x%365)/7<<" weeks "<<(x%365)%7<<" days ";
    return 0;
}