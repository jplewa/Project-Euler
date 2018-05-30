#include <iostream>
#include <math.h>

using namespace std;

int pierwsze();

int main()
{
    cout << pierwsze();
    return 0;
}


int pierwsze() {
    long long n = 3;
    long long kontr = 1;
    while (kontr<10001){
        bool podz = false;
        for (int i=sqrt(n); i>1 && podz==false; i--){
            if (n%i == 0){
                podz=true;
            }
        }
        if (podz==false){
            kontr++;
        }
        n++;
    }
return n-1;
}
