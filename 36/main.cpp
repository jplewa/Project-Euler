#include <iostream>

using namespace std;

int digits (int x, int b){
    int d=0;
    while (x > 0){
        x/=b;
        d++;
    }
    return d;
}

int power (int a, int b){
    int r=1;
    while (b > 0){
        r*=a;
        b--;
    }
    return r;
}

bool pal (int x, int base){
    int d=power(base, (digits(x, base)-1));
    while (d > 1){
        if (x/d != x%base) return false;
        x%=d;
        x/=base;
        d/=base;
        d/=base;
    }
    return true;
}


int main(){
    int sum=0;
    for (int i=1; i<1000000; i++){
        if (pal(i, 10) && pal(i, 2)) sum+=i;
    }
    cout << sum << endl;
}
