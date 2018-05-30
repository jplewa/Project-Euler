#include <iostream>

using namespace std;

int factorial (int x){
    if (x == 0) return 1;
    if (x == 1) return 1;
    else return (x*(factorial(x-1)));
}

int digit_factorial (int factorials[10], int x){
    int sum=0;
    while (x > 0){
        sum+=factorials[x%10];
        x/=10;
    }
    return sum;
}


int main(){
	int x=10;
	int sum=0;
	int factorials[10];
	for (int i=0; i<10; i++) factorials[i]=factorial(i);
	while (x < 2540161){
        if (digit_factorial(factorials, x) == x){
            cout << x << endl;
            sum+=x;
        }
        x++;
	}
	cout << "SUMA: " << sum << endl;
}
