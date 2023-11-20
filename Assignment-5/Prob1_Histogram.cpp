#include<iostream>
#include<vector>

class Histogram{
    int upper_bound;
    int lower_bound;
    int num_intv;
    std::vector<int> values;
    
    public:
    Histogram(int, int, int);
    
};

//constructor for histogram class
Histogram::Histogram(int upper, int lower, int num_intervals):upper_bound(upper), lower_bound(lower), num_intv(num_intervals){
    values.resize(num_intervals,0);
}

int main(){

    return 0;
}