#include<iostream>
#include<vector>
using namespace std;

//represent the number in binary format
void conv_bin(int x,vector<int>* bin_rep){
    for (int i = sizeof(x) * 8 - 1; i >= 0; --i) {
        int bit = (x >> i) & 1;
        (*bin_rep).push_back(bit);
    }
}

//check if the number is stored in 2's complement format
bool check_2scomplement(int x,vector<int> original){
    vector<int> complement;
    int carry = 1;
    for (int i = sizeof(x) * 8 - 1; i >= 0; --i) {
        int bit = ((x >> i) & 1)|1;
        int sum = bit+carry;
        complement[i] = sum % 2;
        carry = sum / 2;
        complement.push_back(sum);
    }
    bool flag = true;
    for(int i:complement){
        if(!(original[i]^complement[i]))
            flag = false;
    }
    return flag;
}

int main(){
    int a;//declare a variable for storing the variable
    cout<<"Please enter a number:"<<endl;
    cin>>a;//take input

    vector<int> arr;//initialize a vector for storing the binary representation 
    conv_bin(a,&arr);//convert the number to binary

    //print the binary representation in the console
    for(int i : arr){
        cout<<i;
    }
    cout<<endl;

    //check whether it is stored in 2's complement format 
    if(check_2scomplement)
        cout<<"Yes, it is stored in 2's complement format!"<<endl;
    else
        cout<<"No, it is not stored in 2's complement format!"<<endl;

    return 0;
}