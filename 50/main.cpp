#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
    bool primes[1000000];
    for (int i=2; i<1000000; i++) primes[i]=true;
    primes[0]=0;
    primes[1]=0;
    int index=2;
    while (index < 1000000){
        for (int i=2*index; i<1000000; i+=index) primes[i]=false;
        do{
            index++;
        }
        while (!primes[index]);
    }
    int counter=0;
    for (int i=0; i < 1000000; i++){
        if (primes[i]){
            index=i;
            counter++;
        }
    }
    counter++;
    long long* sums=(long long*)(malloc(counter*sizeof(long long)));
    index=3;
    sums[0]=0;
    sums[1]=2;
    for (int i=2; i<counter; i++){
        while (!primes[index]) index+=2;
        sums[i]=index;
        index+=2;
    }
    for (int i=1; i<counter; i++) sums[i]+=sums[i-1];
    //for (int i=0; i<counter; i++) cout << sums[i] << endl;
    int m=0;
    int j, k;
    for (int i=0; i<counter-1; i++){
        int index=i;
        while (index+1 < counter && sums[index+1]-sums[i] < 1000000){
            index++;
            if (index-i > m && primes[sums[index]-sums[i]]){
                m=index-i;
                j=index;
                k=i;
            }
        }
    }
    cout << sums[j]-sums[k];
}
