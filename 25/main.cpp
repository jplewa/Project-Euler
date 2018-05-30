#include <iostream>

using namespace std;

void add_arr (int a[1000], int b[1000]){
    for (int i=999; i>=0; i--){
        a[i]+=b[i];
        int j=i;
        while (a[j]>9 && j>0){
            a[j-1]+=(a[j]/10);
            a[j]%=10;
            j--;
        }
    }
}

void fib_seq (int fib1[1000], int fib2[1000], int n){
    if (fib1[0] != 0) cout << n;
    else{
        add_arr(fib2, fib1);
        fib_seq(fib2, fib1, n+1);
    }
}

int main(){
    int fib1[1000], fib2[1000];
    for (int i=0; i<999; i++){
        fib1[i]=0;
        fib2[i]=0;
    }
    fib1[999]=1;
    fib2[999]=1;

    fib_seq(fib1, fib2, 2);
}
