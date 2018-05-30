#include <iostream>

#define M 10000000000

using namespace std;


int main(){
    long long result=0;
    for (int i=1; i<=1000; i++){
        long long x=1;
        for (int j=1; j<=i; j++){
            x*=i;
            if (x > M*10000) x%=M;
        }
        result+=x;
        result%=M;
    }
    cout << result << endl;
}
