#include <iostream>

using namespace std;

int spd (int n){
    int sum=1;
    for (int i=2; i*i<=n; i++){
        if (n%i == 0){
            sum+=i;
            sum+=(n/i);
        }
        if (n == i*i) sum-=i;
    }
    return sum;
}

int main(){
    int n[10000];
    for (int i=2; i<10000; i++){
        n[i]=spd(i);
    }
    long long sum=0;
    n[0]=-1;
    n[1]=-1;
    for (int i=2; i<10000; i++){
        if (n[i] != -1 && n[i] < 10000 && n[i]!=i){
            int x=n[i];
            if (n[x] == i){
                cout << i << " " << n[i] << endl;
                sum+=i;
                sum+=n[i];
                n[i]=-1;
                n[x]=-1;
            }
        }
    }
    cout << sum << endl;
}
