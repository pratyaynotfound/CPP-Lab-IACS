#include<iostream>

class Base{
    public:
    virtual void iam() const {
        std::cout<<"Base"<<std::endl;
    }
};
class D1 : public Base{
    public:
    void iam() const override {
        std::cout << "I am d1.\n";
    }
};
class D2 : public Base{
    public:
    void iam() const override {
        std::cout<< "I am d2.\n";
    }
};
void print(Base *ptr){
    ptr->iam();
}
int main(){
    Base b1;
    D1 d1;
    D2 d2;
    print(&b1);
    print(&d1);
    print(&d2);

}