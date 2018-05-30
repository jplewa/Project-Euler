#include <iostream>

using namespace std;

int main(){
    int side=3;
    int sum=1;
    while (side <= 1001){
        sum+=(side*side*4);
        sum-=((side-1)*6);
        side+=2;
    }
    cout << sum;
}
