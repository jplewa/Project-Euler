#include <iostream>
#include <cmath>

using namespace std;

bool triangle (long long x){
    double n=(sqrt(8*((double) x)+1)-1)/2;
    double* tmp=new double;
    if (modf(n, tmp) == 0) return true;
    return false;
}

bool pentagonal (long long x){
    double n=(sqrt(24*((double) x)+1)+1)/6;
    double* tmp=new double;
    if (modf(n, tmp) == 0) return true;
    return false;
}

long long hexagonal_n (int x){
    return (x*(2*x-1));
}

int main(){
    int x=144;
    while (!pentagonal(hexagonal_n(x))) x++;
    cout << hexagonal_n(x) << endl;
}
