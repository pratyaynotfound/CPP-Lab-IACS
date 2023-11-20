#include<iostream>
using namespace std;
class interval{
    public:
    int upper, lower;

    interval();
    interval(int up_lt, int lo_lt);

    interval operator++(int);
    interval& operator++();
    interval& operator--();
    interval operator--(int);
    interval operator+(interval const&);

};
interval::interval(int up_lt, int lo_lt):upper(up_lt),lower(lo_lt){};
interval::interval(){
    upper = 0;
    lower = 0;
};

interval& interval::operator++(){
    (*this).upper = (*this).upper+1;
    (*this).lower = (*this).lower+1;
    return *this;
}

interval interval::operator++(int){
    interval temp = *this;
    ++(*this);
    return temp;
}
interval& interval::operator--(){
    (*this).upper = (*this).upper-1;
    (*this).lower = (*this).lower-1;
    return *this;
}
interval interval::operator--(int){
    interval temp = *this;
    --(*this);
    return temp;
}

interval interval::operator+(interval const& obj){
    interval res;
    res.upper = upper + obj.upper;
    res.lower = lower + obj.lower;

    return res;
}

ostream& operator<<(ostream &os, const interval & intv){
    os << "[" << intv.upper << "," << intv.lower << "]";
    return os;
};

int main(){
    interval x(3,6);
    cout<<x<<endl;
    interval y = x--,z = --x;
    cout<<y<<"\n"<<z<<endl;

    interval res = y+z;
    std::cout<<res<<std::endl;
    return 0;
}