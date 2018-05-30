#include <iostream>

using namespace std;

int power (int a, int b){
    int a2=a;
    while (b>1){
        a2*=a;
        b--;
    }
    return a2;
}

int sum_of_digits (int x){
    int y=x;
    int sum=0;
    while (y>0){
        sum+=(power((y%10),5));
        y/=10;
    }
    return sum;
}

int main(){
    int sum=0;
    for (int i=10; i<1000000; i++){
        if (sum_of_digits(i) == i) sum+=i;
    }
    cout << sum;
}
