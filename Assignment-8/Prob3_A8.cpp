#include<iostream>
#include<vector>
#include<cassert>

template <class T>
class myvector:public std::vector<T>{
    public:
    using std::vector<T>::vector;
    T& operator[](unsigned int i);
    const T& operator[](unsigned int i) const;
};

template <class T>
T& myvector<T>::operator[](unsigned int i){
    assert(i < this->size());
    return std::vector<T>::operator[](i);
}
template <class T>
const T& myvector<T>::operator[](unsigned int i) const{
    assert(i < this->size());
    return std::vector<T>::operator[](i);
}
int main(){ 
    myvector<int> v {1,2,3,4,5};
    // std::cout<<v[5]<<std::endl;
    std::cout<<v[3]<<std::endl;
}