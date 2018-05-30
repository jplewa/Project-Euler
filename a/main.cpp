#include <iostream>

using namespace std;

int main(){
    cout << "hello" << endl;
    int* primes = new int[10000000];
    primes[0]=0;
    primes[1]=0;
    for (int i=2; i<1000000; i++) primes[i]=1;
    int index=2;
    while (index < 500000){
        cout << index << endl;
        for (int i=2*index; i<1000000; i+=index) primes[i]=0;
        index++;
        while (primes[index] == 0 && index<1000000){
            index++;
        }
    }
    cout << "OKEJ" << endl;
}
