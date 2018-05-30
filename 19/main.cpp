#include <iostream>

using namespace std;

bool leap(int y){
    if (y%400==0) return true;
    else if (y%100==0) return false;
    else if (y%4==0) return true;
    else return false;
}

int main(){
    int months[12]={31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int day=1;
    int year=1901;
    int n=0;

    while (year<2001){
        for (int i=0; i<12; i++){
            if (months[i]!=0) day+=months[i];
            else if (leap(year)) day+=29;
            else day+=28;

            if (day%7==5) n++;
        }
        year++;
    }
    cout << n;
    return 0;
}
