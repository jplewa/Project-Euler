#include <iostream>

using namespace std;

bool isPrime (int x){
    if (x == 0 || x == 1) return false;
    if (x%2 == 0) return false;
    for (int i=3; i*i<=x; i+=2){
        if (x%i == 0) return false;
    }
    return true;
}

bool leftTruncatable (int x){
    if (!isPrime(x)) return false;
    int mod=10;
    while (x%mod != x){
        if (!isPrime(x%mod)) return false;
        mod*=10;
    }
    return true;
}

void generator(int number, int &counter, int &sum){
    if (counter != 11){
        if (isPrime(number*10+1)) generator(number*10+1, counter, sum);
        if (number == 0) generator (2, counter, sum);
        if (isPrime(number*10+3) || number == 0) generator(number*10+3, counter, sum);
        if (isPrime(number*10+5) || number == 0) generator(number*10+5, counter, sum);
        if (isPrime(number*10+7) || number == 0) generator(number*10+7, counter, sum);
        if (isPrime(number*10+9)) generator(number*10+9, counter, sum);

        if (leftTruncatable(number) && number > 10 ){
            cout << number << endl;
            counter++;
            sum+=number;
        }
    }
}




int main(){
    int counter=0;
    int sum=0;
    generator(0, counter, sum);
    cout << endl << "SUMA: " << sum << endl;
}
