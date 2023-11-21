#include<iostream>
#include<list>
using namespace std;
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& vect){
    os<<"{";
    for(const auto& it: vect){
        os<< it;
        if(it != vect.back()){
            os<<", ";
        }
    }
    os<<"}";
    return os;
}
ostream& operator<<(ostream& os, const list<bool>& list){
    os<<"{";
    for(const auto& it: list){
        if(it)
            os<< "true";
        else
            os<< "false";
        if(it != list.back()){
            os<<", ";
        }
    }
    os<<"}";
    return os;
}

class base {
    int x;
    vector<double> v;
    public:
    base(int y, vector<double> z): x{y}, v{z}{};
    int getx(){
        return x;
    }
    vector<double> getv(){
        return v;
    }
};

class derived : public base{
    list<bool> l;
    public:
    derived(int y, vector<double> z): base(y,z),l({}){};
    derived(int y, vector<double> z, list<bool> el): base(y,z),l(el){};
    void print();
};
void derived::print(){
    vector<double> v = getv();
    cout<<"{"<<getx()<<", "<<getv()<<", "<<l<<"}"<<endl;
}

int main(){
    derived d{10,{1.5, 2.5, 3.5}, {true, false}};
    d.print();
}
