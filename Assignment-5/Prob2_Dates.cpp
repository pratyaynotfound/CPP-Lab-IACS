#include<iostream>
class Date{
private:
    int d,y,m;

    bool is_leapyear(int year) const;
    int days_in_month(int month,int year) const;
    bool is_valid_date(int day, int month, int year);

public:
    Date(int day, int month, int year);
    void add_day(int dd);
    void add_month(int mm);
    void add_year(int n);
    void show() const;
};

//constructor for Date Class
Date::Date(int day, int month, int year) : d(day), m(month), y(year){
    if(!is_valid_date(d,m,y)){
        std::cout<<"Invalid Date!"<<std::endl;
        d = m = y = 1; //set to default
    }
}
//function for cheaking if the date is valid
bool Date::is_valid_date(int day, int month, int year){
    if (month < 1 || month > 12 || day < 1 || day > days_in_month(month, year)) {
        return false;
    }
    return true;
}

//function for cheaking if it is a leapyear
bool Date::is_leapyear(int year) const{
    return ((year%4==0 && year%100!=0) || (year%400 == 0));
}

//function for getting the total days of a specific month
int Date::days_in_month(int month,int year) const{
    if (month == 2) {
        return is_leapyear(year) ? 29 : 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    else {
        return 31;
    }
}

//add <some days> days to the current date
void Date::add_day(int dd){
    d+=dd;
    //handeling the month transition
    while(d>days_in_month(m,y)){
        d = d - days_in_month(m,y);
        m++;
        if(m>12){
            y++;
            m = 1;
        }
    }
}

//add <some months> months to the current date
void Date::add_month(int mm){
    m+=mm;
    while(m>12){
        m = m - 12;
        add_year(1);
    }
    while(m<1){
        m = 12 + m;
        add_year(1);
    }
    if (d > days_in_month(m, y)) {
        d = days_in_month(m, y);
    }
}

//add <some years> years to the current date
void Date::add_year(int n){
    y += n;
    if (m == 2 && d == 29 && !is_leapyear(y)) {
        d = 28;
    }
}

//Show the current date
void Date::show() const{
    std::cout << "Date: " << d << "/" << m << "/" << y << std::endl;
}
int main(){
    try {
        int d,m,y;
        std::cout<<"Enter a date(DD/MM/YYYY):"<<std::endl;
        std::cin>>d>>m>>y;
        Date myDate(d, m, y);
        myDate.show();

        std::cout<<"Enter Operation: \n1. Add Days \n2. Add Months \n3. Add Year \n4. Show Date \n0. Exit"<<std::endl;
        int op;
        do{
            std::cin>>op;
            switch(op){
                case 1:
                    int add_d;
                    std::cout<<"Enter days to add:"<<std::endl;
                    std::cin>>add_d;
                    myDate.add_day(add_d);
                    myDate.show();
                    std::cout<<std::endl;
                    break;
                
                case 2:
                    int add_m;
                    std::cout<<"Enter months to add:"<<std::endl;
                    std::cin>>add_m;
                    myDate.add_month(add_m);
                    myDate.show();
                    std::cout<<std::endl;
                    break;

                case 3:
                    int add_y;
                    std::cout<<"Enter years to add:"<<std::endl;
                    std::cin>>add_y;
                    myDate.add_year(add_y);
                    myDate.show();
                    std::cout<<std::endl;
                    break;
                
                case 4:
                    myDate.show();
                    std::cout<<std::endl;
                    break;
            }
        }while(op!=0);

    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}