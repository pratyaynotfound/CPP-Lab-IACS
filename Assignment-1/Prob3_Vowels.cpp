#include<iostream>
using namespace std;

int main(){
    //make an array of the vowels
    char vowel1 = 'a';
    char vowel2 = 'e';
    char vowel3 = 'i';
    char vowel4 = 'o';
    char vowel5 = 'u';

    //check if valid or not
    cout<<vowel2 - vowel1<<endl;
    cout<<vowel5 - vowel2<<endl;
    
    //also check for capvowels
    char capvowel1 = 'A';
    char capvowel2 = 'E';
    
    cout<<capvowel2 - capvowel1<<endl;

    return 0;
}
