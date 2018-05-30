#include <iostream>

using namespace std;

int gcd (int a, int b){
    if (b == 0) return a;
    return gcd (b, a%b);
}


bool check (int a, int b, int n, int d){
    int ab=gcd(a, b);
    int nd=gcd(n, d);
    if (a/ab == n/nd && b/ab == d/nd) return true;
    else return false;
}

int main(){
	int n[2];
	int d[2];

	int nprod=1;
	int dprod=1;

	for (int i=99; i>9; i--){
        for (int j=10; j<i; j++){       // j/i
            n[0]=j/10;
            n[1]=j%10;
            d[0]=i/10;
            d[1]=i%10;
            if ((n[1] != 0) || (d[1] != 0)){
                if (n[0] == d[0] && check(n[1], d[1], j, i)){
                    nprod*=j;
                    dprod*=i;
                }
                if (n[1] == d[1] && check(n[0], d[0], j, i)){
                    nprod*=j;
                    dprod*=i;
                }
                if (n[0] == d[1] && check(n[1], d[0], j, i)) {
                    nprod*=j;
                    dprod*=i;
                }
                if (n[1] == d[0] && check(n[0], d[1], j, i)){
                    nprod*=j;
                    dprod*=i;
                }
            }
        }
	}
    int nd=gcd(nprod, dprod);
    dprod/=nd;
    cout << dprod << endl;

}
