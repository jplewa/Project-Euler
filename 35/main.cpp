#include <iostream>

using namespace std;

int digits (int x){
    int d=0;
    while (x > 0){
        x/=10;
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


int rotate_n (int primes[1000000], int n, bool still_ok){
    int t=power(10, (digits(n)-1));
    int m=n;
    int x=0;
    do{
        m=((m%t)*10)+m/t;
        x++;
        if (primes[m] == 0) still_ok=false;
        primes[m]=-1;
    }
    while (m != n);
    if (still_ok == true) return x;
    else return 0;
}

int main(){
    int* primes = new int[1000000];
    primes[1]=0;
    for (int i=2; i<1000000; i++) primes[i]=1;
    int index=2;
    while (index*index < 1000000){
        for (int i=2*index; i<1000000; i+=index) primes[i]=0;
        index++;
        while (primes[index] == 0 && index<1000000){
            index++;
        }
    }
    int counter=0;
    for (int i=2; i<1000000; i++){
        if (primes[i] == 1) counter+=(rotate_n(primes, i, true));
    }
    cout << counter << endl;
}
