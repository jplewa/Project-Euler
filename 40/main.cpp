#include <iostream>

using namespace std;

int power (int a, int b){
    if (b == 0) return 1;
    else{
        int c=a;
        while (b > 1){
            c*=a;
            b--;
        }
        return c;
    }
}

int main(){
    int digits[9]={0, 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};
    int i=0;
    int d=0;
    int x=1;
    int df=1;
    int product=1;

    while (df < 8){
        if (digits[i+1] <= x) i++;
        d+=i;
        if (d >= digits[df]){
            product*=((x/(power(10, (d-digits[df]))))%10);
            df++;
        }
        x++;
    }
    cout << product;
}
