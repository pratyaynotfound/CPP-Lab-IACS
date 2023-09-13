#include<iostream>
//create a month structure
struct month{
    std::string mname;
    int days;
};
int main(){
    int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};   //table of the days
    std::string months[12] = {"jan","feb","mar","apr","may","june","july","aug","sept","oct","nov","dec"};  //table of the month names

    //printing the array output
    std::cout<<"Out1(arrays):\nMonth\tDays"<<std::endl;
    for(int i = 0;i<12;i++){
        std::cout<<months[i]<<"\t"<<days[i]<<std::endl;
    }

    std::cout<<"#############################"<<std::endl;
    //storing the names and days inside a structure 
    month month_names[12];
    for(int i = 0;i<12;i++){
        month_names[i].mname = months[i];
        month_names[i].days = days[i];
    }
    //printing the month names and days
    std::cout<<"Out2(structures):\nMonth\tDays"<<std::endl;
    for(int i = 0;i<12;i++){
        std::cout<<month_names[i].mname<<"\t"<<month_names[i].days<<std::endl;
    }
}
