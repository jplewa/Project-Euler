#include <iostream>
#include <stdlib.h>

using namespace std;

int power (int a, int b){
    int a2=a;
    while (b>1){
        a2*=a;
        b--;
        if (a2 > 100) return 101;
    }
    return a2;
}

bool is_some_power (int x){
    for (int i=2; i<11 && i*i<=x; i++){
        int y=1;
        while (y < x) y*=i;
        if (y == x) return true;
    }
    return false;
}

int next (int x){
    do x++;
    while (is_some_power(x));
    return x;
}

int highest_power (int x){
    int y=1;
    int power=0;
    while (y<101){
        y*=x;
        power++;
    }
    return power-1;
}

int main(){
    int counter=0;
    int x=2;
    while (x<101){
        int n=highest_power(x);
        if (n>1){
            n*=100;
            n+=1;
            bool* powers=(bool*)(malloc(n*sizeof(bool)));
            for (int i=0; i<n; i++) powers[i]=false;
            for (int i=2; i<101; i++){
                if (powers[i] == false){
                    powers[i]=true;
                    counter++;
                }
                if (power(x,i)<101){
                    int p=2;
                    while (p<101){
                        if (powers[i*p] == false){
                            counter++;
                            powers[i*p]=true;
                        }
                        p++;
                    }
                }
            }
        }
        else counter+=99;
        x=next(x);
    }
    cout << counter << endl;
}
