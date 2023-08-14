#include<iostream>
using namespace std;

int main(){
    //declare an array of 5 characters
    char vowels[5];
    //take input
    cout<<"Enter vowels(lower case):"<<endl;
    for(int i = 0;i<5;i++){
        cin>>vowels[i];
    }
    //check if valid or not
    cout<<vowels[1] - vowels[0]<<endl;
    cout<<vowels[4] - vowels[1]<<endl;
    
    //also check for capvowels
    char capvowel1 = 'A';
    char capvowel2 = 'E';
    
    cout<<"Result(cap):"<<capvowel2 - capvowel1<<endl;

    return 0;
}