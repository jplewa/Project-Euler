#include <iostream>

using namespace std;

bool pan (int x, int n){
    int digits[10];
    for (int i=0; i<10; i++) digits[i]=0;
    while (n > 0){
        int tmp=x*n;
        while (tmp > 0){
            if (digits[tmp%10] > 0) return false;
            digits[tmp%10]++;
            tmp/=10;
        }
        n--;
    }
    if (digits[0] != 0) return false;
    for (int i=1; i<10; i++){
        if (digits[i] != 1) return false;
    }
    return true;
}

int digits(int x){
    int counter=0;
    while (x > 0){
        counter++;
        x/=10;
    }
    return counter;
}

int nineDigCon (int x, int n){
    int counter=0;
    while (n > 0){
        counter+=(digits(n*x));
        n--;
        if (counter > 9) return 1;
    }
    if (counter < 9) return -1;
    return 0;
}

int larger (int &result, int x, int n){
    int i=1;
    int sum=0;
    while (i <= n){
        for (int j=0; j<digits(x*i); j++) sum*=10;
        sum+=(x*i);
        i++;
    }
    if (sum > result) result=sum;
}

int main(){
    int result=0;
    for (int i=1; i<10000; i++){
        int n=2;
        while (nineDigCon(i, n) == -1) n++;
        if (pan(i, n)) larger(result, i, n);
    }
    cout << result;
}
