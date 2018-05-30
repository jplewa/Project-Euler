#include <iostream>

using namespace std;

long long odd(long long n){
    return 3*n+1;
}

long long even(long long n){
    return n/2;
}

int main()
{
    int max_c=0;
    long long max_c_i;

    for (long long i=2; i<1000000; i++){
        long long j=i;
        int c=0;
        while (j!=1){
            c++;
            if (j%2==0) j=even(j);
            else j=odd(j);
        }
        if (c>max_c){
            max_c=c;
            max_c_i=i;
        }
    }
    cout << max_c_i << endl;
    return 0;
}
