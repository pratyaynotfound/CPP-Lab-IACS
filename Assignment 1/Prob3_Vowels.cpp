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
    // yes this are valid statements and the output of 1st statement is 4 because ascii value of 'e' is 101 and for 'a' it is 97 and 101-97=4
    //and for the 2nd statement ascii value of 'u' is 117 and for 'e' it is 101 and 117-101=16 is the output.

    char capvowel1 = 'A';
    char capvowel2 = 'E';
    
    cout<<capvowel2 - capvowel1<<endl;
    //yes they have the same answer because again ascii 'A' is 65 and 'E' is 69 and again 69-65=4.
    return 0;
}