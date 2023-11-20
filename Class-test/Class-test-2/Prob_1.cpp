#include<iostream>
using namespace std;

class myvector{
    int *p;
    unsigned int size;
    bool shallow;
public:
    myvector();
    myvector(unsigned int);
    myvector(myvector& , bool);
    int* get_ptr() const;
    constexpr unsigned int get_size() const;
    bool is_shallow() const;
    void update(unsigned int, int);
    constexpr int get(unsigned int) const;
    void print() const;
    void push_back(int);
    // ~myvector();
};
//default constructor
myvector::myvector():p(nullptr), size(0), shallow(false){};
//parameterisd constructor
myvector::myvector(unsigned int n):p(new int[n]), size(n), shallow(false){
    for(int i = 0; i < size; i++){
        p[i] = 0;
    }
}
//shallow copy
myvector::myvector(myvector& v, bool isshallow):size(v.size),shallow(isshallow){
    if(!shallow){
        p = v.p;
    }
    else{
        p = new int[size];
        for(unsigned int i = 0;i<size;i++){
            p[i] = v.p[i];
        }
    }
}
//get the base pointer of the vector
int* myvector::get_ptr() const{
    return p;
}
//get the size
constexpr unsigned int myvector::get_size() const{
    return size;
}
//check if shallow
bool myvector::is_shallow() const{
    return shallow;
}
//update value
void myvector::update(unsigned int i, int val){
    if(i < size)
        p[i] = val;
}
//return the element of specific index
constexpr int myvector::get(unsigned int i) const{
    return p[i];
}
//print the vector
void myvector::print() const{
    for(int i = 0;i<size;i++){
        std::cout<<p[i]<<" ";
    }
    std::cout<<std::endl;
}
// push back
void myvector::push_back(int val){
    int *q = new int[size+1];
    for(int i = 0;i<size;i++){
        q[i] = p[i];
    }
    q[size] = val;
    if(!is_shallow()){
        delete[] p;
    }
    p = q;
    size++;
    shallow = false;
}
// myvector::~myvector() {
//     if (!shallow) {
//         // delete[] p;
//     }
// }

int main(){
    myvector x(7); // Initialize vector 'x' with a size of 7 elements
    // Populate vector 'x' with values
    for (unsigned int i = 0; i < 7; i++) {
        x.update(i, 10 + 5 * i); // Set elements to a series of values
    }

    // v is a shallow copy of x, so they share the same underlying array
    myvector v(x); // Default is shallow copy
    v.update(1, 100); // Updating v[1] also updates x[1] because of the shared array
    v.print(); // Should print the updated vector 'v'
    x.print(); // Should print the same changes as in 'v'

    // y is a deep copy of x, so it has its own separate underlying array
    myvector y(x, false); // Explicitly requesting a deep copy
    y.update(1, 200); // Updating y[1] does not affect x[1]
    y.print(); // Should print the updated vector 'y'
    x.print(); // Should print the original vector 'x' without changes

    y.push_back(500); // Append a new element to 'y'
    y.print(); // Should print 'y' with the new element added

    return 0;
}