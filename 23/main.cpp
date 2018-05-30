#include <iostream>

using namespace std;

int sumofproper (int n){
    int sum=1;
    int i=2;
    for (; i*i<n; i++){
        if (n%i == 0){
            sum+=i;
            sum+=(n/i);
        }
    }
    if (i*i == n) sum+=i;
    return sum;
}

bool abundant (int n){
    if (sumofproper(n) > n) return true;
    else return false;
}

int main(){
    int ab[28124];
    for (int i=0; i<28124; i++) ab[i]=0;
    int counter=0;

    for (int i=1; i<28124; i++){
        if (abundant(i)){
            ab[counter]=i;
            counter++;
        }
    }

    bool sum_ab[28124];
    for (int i=0; i<28124; i++) sum_ab[i]=false;
    for (int i=0; i<counter; i++){
        for (int j=i; j<counter; j++){
            if (ab[i]+ab[j]<28124) sum_ab[ab[i]+ab[j]]=true;
        }
    }
    long long sum=0;
    for (int i=1; i<28124; i++){
        if (!sum_ab[i]) sum+=i;
    }
    cout << sum;
}
