#include<iostream>
#include<vector>
using namespace std;

//represent the number in binary format
void conv_bin(int x,vector<int>& bin_rep){
    for (int i = sizeof(x) * 8-1; i >= 0; --i) {
        int bit = (x >> i) & 1;
        bin_rep.push_back(bit);
    }
}

//check if the number is stored in 2's complement format
bool check_complement(int x, vector<int>& comp_str,vector<int>& bin_rep) {
    int carry = 1;
    for (int i = 0; i<sizeof(x) * 8; i++) {
        int sum = (bin_rep[i])-carry;
        comp_str.push_back(sum % 2);
        carry = sum / 2;
    }
    for(int j = 0;j<sizeof(x)*8;j++){
        if(j==0)
            continue;
        if(comp_str[j]!=bin_rep[j])
            return false;
    }
    return true;
}

int main(){
    int a;//declare a variable for storing the variable
    cout<<"Please enter a number:"<<endl;
    cin>>a;//take input

    //convert to binary format
    vector<int> bin_store;
    conv_bin(a,bin_store);
    cout<<"Stored in memory:"<<endl;
    for(int i:bin_store){
        cout<<i;
    }
    cout<<endl;

    //check if it is stroed in 2's complement format
    if(a<0){
        vector<int> complement_str;
        if(check_complement(a,complement_str,bin_store))
            cout<<"It is stored in 2's complement format."<<endl;
        else
            cout<<"Not stored in 2's complement format."<<endl;

    }
    return 0;
}