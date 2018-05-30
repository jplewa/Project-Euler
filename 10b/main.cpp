#include <iostream>

using namespace std;

int main()
{   bool prime[2000000];
    for (int i=2; i<2000000; i++) prime[i]=true;
    for (int i=4; i<2000000; i+=2) prime[i]=false;
    for (int i=3; i*i<=2000000; i+=2){
        if (prime[i]){
            for (int j=i*i; j<2000000; j+=2*i){
               prime[j]=false;
            }
        }
    }
    long long sum=2;
    for (int i=3; i<2000000; i+=2){
        if (prime[i]) sum+=i;
    }
    cout << sum << endl;
    return 0;
}
