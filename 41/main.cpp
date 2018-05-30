#include <iostream>
#include <cstdlib>

using namespace std;

bool prime(int x){
    if (x < 2) return false;
    if (x == 2 || x == 3) return true;
    if (x%2 == 0 || x%3 == 0) return false;
    for (int i=5; i*i <= x; i+=2){
        if (x%i == 0) return false;
    }
    return true;
}

bool doubles (int x){
    if (x == 0) return false;
    bool* digits=(bool*)(malloc(10*sizeof(bool)));
    for (int i=0; i<10; i++) digits[i]=false;
    while (x > 0){
        if (digits[x%10] == true) return true;
        else digits[x%10]=true;
        x/=10;
    }
    return false;
}

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

void largestPP (int n, int m, int perm, int &mx){
    if (m == n){
        if (prime(perm) && perm > mx) mx=perm;
    }
    else if ((perm+1)*power(10, n-m) > mx){
        for (int i=n; i>0; i--){
            if (!(doubles(perm*10+i))) largestPP(n, m+1, perm*10+i, mx);
        }
    }
}

int main(){
    int n=0;
    largestPP(7, 0, 0, n);
    largestPP(4, 0, 0, n);
    cout << n;
}
