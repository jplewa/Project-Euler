#include <iostream>
#include <cstdlib>

using namespace std;

bool doubles (long long x){
    if (x <= 10) return false;
    bool* digits=(bool*)(malloc(10*sizeof(bool)));
    for (int i=0; i<10; i++) digits[i]=false;
    while (x > 0){
        if (digits[x%10] == true) return true;
        else digits[x%10]=true;
        x/=10;
    }
    return false;
}

int last_three (long long p){
    int sum=0;
    for (int i=0; i<3; i++){
        int a=p%10;
        for (int j=0; j<i; j++) a*=10;
        sum+=a;
        p/=10;
    }
    return sum;
}

void permutations (int n, long long perm, long long &sum){
    if (n < 4){
        for (int i=0; i<10; i++){
            if (n != 0 || i != 0){
                if (!doubles(perm*10+i)) permutations(n+1, perm*10+i, sum);
            }
        }
    }
    if (n == 4 && perm%2 == 0){
        for (int i=0; i<10; i++){
            if (!doubles(perm*10+i)) permutations(n+1, perm*10+i, sum);
        }
    }
    if (n == 5 && last_three(perm)%3 == 0){
        for (int i=0; i<10; i++){
            if (!doubles(perm*10+i)) permutations(n+1, perm*10+i, sum);
        }
    }
    if (n == 6 && last_three(perm)%5 == 0){
        for (int i=0; i<10; i++){
            if (!doubles(perm*10+i)) permutations(n+1, perm*10+i, sum);
        }
    }
    if (n == 7 && last_three(perm)%7 == 0){
        for (int i=0; i<10; i++){
            if (!doubles(perm*10+i)) permutations(n+1, perm*10+i, sum);
        }
    }
    if (n == 8 && last_three(perm)%11 == 0){
        for (int i=0; i<10; i++){
            if (!doubles(perm*10+i)) permutations(n+1, perm*10+i, sum);
        }
    }
    if (n == 9 && last_three(perm)%13 == 0){
        for (int i=0; i<10; i++){
            if (!doubles(perm*10+i)) permutations(n+1, perm*10+i, sum);
        }
    }
    if (n == 10 && last_three(perm)%17 == 0){
        cout << perm << endl;
        sum+=perm;
    }
}

int main(){
    long long sum=0;
    permutations(0, 0, sum);
    cout << endl << sum << endl;
}
