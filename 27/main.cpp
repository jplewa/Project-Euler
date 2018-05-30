#include <iostream>

using namespace std;

bool prime (int x){
    if (x < 2) return false;
    if (x%2 == 0) return false;
    for (int i=3; i*i<=x; i+=2){
        if (x%i == 0) return false;
    }
    return true;
}

int quadratics (int a, int b){
    //cout << "a: " << a << " b: " << b << endl;
    int counter=0;
    int n=0;
    while (prime(n*n + a*n + b)){
      //  cout << n*n + a*n + b << " ";
        counter++;
        n++;
    }
    //cout << endl;
    return counter;
}

int main(){
    int maxfound=0;
    int max_a;
    int max_b;
    for (int b=0; b<=1000; b++){
        for (int a=0; a<1000; a++){
            if (a==0){
                if (quadratics(a, b) > maxfound){
                    maxfound=quadratics(a, b);
                    max_a=a;
                    max_b=b;
                }
                if (quadratics(a, -b) > maxfound){
                    maxfound=quadratics(-a, b);
                    max_a=a;
                    max_b=-b;
                }
            }
            else if (b==0){
                if (quadratics(a, b) > maxfound){
                    maxfound=quadratics(a, b);
                    max_a=a;
                    max_b=b;
                }
                if (quadratics(-a, b) > maxfound){
                    maxfound=quadratics(-a, b);
                    max_a=-a;
                    max_b=b;
                }
            }
            else {
                if (quadratics(a, b) > maxfound){
                    maxfound=quadratics(a, b);
                    max_a=a;
                    max_b=b;
                }
                if (quadratics(-a, b) > maxfound){
                    maxfound=quadratics(-a, b);
                    max_a=-a;
                    max_b=b;
                }
                if (quadratics(a, -b) > maxfound){
                    maxfound=quadratics(a, -b);
                    max_a=a;
                    max_b=-b;
                }
                if (quadratics(-a, -b) > maxfound){
                    maxfound=quadratics(-a, -b);
                    max_a=-a;
                    max_b=-b;
                }
            }
        }
    }
    cout << maxfound << endl << max_a << endl << max_b << endl << max_a*max_b;
}
