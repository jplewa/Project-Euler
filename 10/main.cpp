#include <iostream>

using namespace std;

bool prime (int n){
    if (n%2==0 || n%3==0) return false;
    if (n<9) return true;
    int i=5;
    while (i*i<=n){
        if (n%i==0) return false;
        if (n%(i+2)==0) return false;
        i+=6;
    }
    return true;
}
int main()
{
    long long sum = 5;
    for (int i=5; i<2000000; i+=2){
        if ((prime(i))) sum+=i;
    }
    cout << sum << endl;
    return 0;
}
