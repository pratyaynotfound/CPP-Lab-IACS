#include<iostream>
#include<vector>
#include<list>

class base {
    int x;
    std::vector<double> v;
public:
    base(int y,std::vector<double> z):x{y}, v{z}{};
    int getx(void){
        return x;
    }
    std::vector<double> getv(void){
        return v;
    }
};
class derived : public base {
    std::list<bool> l;
public:
    derived(int y, std::vector<double> z):base(y,z){};
    derived(int y, std::vector<double> z, std::list<bool> el):base(y,z), l(el){};
    void print();
};
void derived::print(){
    // std::cout<<"{"<<getx()<<","<<getv()<<","<<l<<"}";
    std::vector<double> vc = getv();
    std::cout<<vc;
}

template <typename T> 
std::ostream& operator<<(std::ostream &os, const std::vector<T> &v){
    os<< "{";
    for(auto const &getV: getv()){
        os<< it<<",";
    }
    os<<"}";
    return os;
};
std::ostream& operator<<(std::ostream &os, const std::list<bool> &t){
    os<< "{";
    for(auto it: t){
        it?os<<"true,":os<<"false,";
    }
    os<<"}";
    return os;
};

int main(){
    derived d{10,{1.5,2.5,3.5},{true,false}};
    d.print();
}
