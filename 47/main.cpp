#include <iostream>

using namespace std;


int prime_factors(bool primes[1000], long long x){
    int counter=0;
    int i;
    for (i=2; i<x && i<1000; i++){
        if (primes[i] && x%i == 0) counter++;
    }
    return counter;
}

bool next_three (bool primes [1000], long long x){
    if (prime_factors(primes, x+1) == 4 && prime_factors(primes, x+2) == 4 && prime_factors(primes, x+3) == 4) return true;
    return false;
}

int main(){
    bool primes[1000];
    for (int i=2; i<1000; i++) primes[i]=true;
    primes[0]=0;
    primes[1]=0;
    int index=2;
    while (index < 1000){
        for (int i=2*index; i<1000; i+=index) primes[i]=false;
        do{
            index++;
        }
        while (!primes[index]);
    }
    bool found=false;
    for (long long i=210; i<5000000 && !found; i++){
        if (prime_factors(primes, i) == 4){
            if (next_three(primes, i)){
                cout << i << " " << i+1 << " " << i+2 << " " << i+3 << endl;
                found=true;
            }
        }
    }
}
