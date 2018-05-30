#include <iostream>

using namespace std;

int factorial (int x){
    if (x==1) return 1;
    else return x*factorial(x-1);
}

int nth_x (bool t[10], int n){
    int m=0;
    for (int i=0; i<10; i++){
        if (t[i] && m==n){
            t[i]=false;
            return i;
        }
        else if (t[i]) m++;
    }
}


int main(){
    bool digits[10]={1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; // dostepne cyfry

    long long a=0;                                        // szukana permutacja
    int m=0;
    int goal=1000000;                               // szukana pozycja permutacji

    for (int i=10; i>0; i--){
        int r=factorial(i);                         // pula
        m=r;
        if (goal>0){
            int n=i-1;
            while (m>=goal && n>=0){
                m=r;
                m/=i;
                m*=n;
                n--;
            }
            a*=10;
            int x=nth_x(digits, n+1);
            a+=x;
            goal-=m;
        }
    }
    for (int i=0; i<10; i++){
        if (digits[i]) cout << i << endl;
    }
/**    for (int i=0; i<10; i++){
        if (numbers[i]){
            a*=10;
            a+=i;
            numbers[i]=false;
        }
    }
**/
    cout << a;
}
