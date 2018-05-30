#include <iostream>
#include <cstdlib>

using namespace std;

bool correct (int d[4], int a){
    while (a > 0){
        bool okay=false;
        for (int i=0; i<4 && !okay; i++){
            if (d[i] == a%10){
                d[i]*=-1;
                okay=true;
            }
        }
        if (!okay){
            for (int i=0; i<4; i++){
                if (d[i] < 0) d[i]*=-1;
            }
            return false;
        }
        a/=10;
    }
    for (int i=0; i<4; i++){
        if (d[i] < 0) d[i]*=-1;
    }
    return true;
}



bool check (bool primes[10000], int d[4], int n, int a, int &b, int x){
    if (n == 4){
        if (a != x && a < 10000 && primes[a]){
            if (2*a-x <= 0) return false;
            else if (2*a-x < 10000 && 2*a-x > 1000 && primes[2*a-x] && correct(d, 2*a-x)){
                b=a;
                return true;
            }
            else return false;
        }
        else return false;
    }
    else if (n < 4){
        for (int i=0; i<4; i++){
            //if (correct(d, a*10+d[i])) cout << a*10+d[i] << " " << n+1 << endl;
            if (correct(d, a*10+d[i]) && check(primes, d, n+1, a*10+d[i], b, x)) return true;
        }
        return false;
    }
}

int main(){
    bool primes[10000];
    for (int i=2; i<10000; i++) primes[i]=true;
    primes[0]=0;
    primes[1]=0;
    int index=2;
    while (index < 10000){
        for (int i=2*index; i<10000; i+=index) primes[i]=false;
        do{
            index++;
        }
        while (!primes[index]);
    }
    for (int i=1489; i<10000; i++){
        if (primes[i]){
            int j=i;
            int d[4];
            for (int i=3; i>=0; i--){
                d[i]=j%10;
                j/=10;
            }
            int b=0;
            int c=0;
            if (check(primes, d, 0, 0, b, i)){
                cout << i << " " << b << " " << 2*b-i << endl;
                break;
            }
        }
    }
}
