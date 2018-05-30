#include <iostream>

using namespace std;

int main()
{
    int s=1000;
    for (int n=1; n<500; n++){
        int x=n*n+2000;
        int y=1;
        int m;
        while (y*y<x){
            y++;
        }
        if (y*y==x) m=y;
        m-=n;
        m/=2;
        if ((2*m*(m+n))==s){
            cout << ((m*m-n*n)*(2*m*n)*(m*m+n*n));
            return 0;
        }
    }
    return 0;
}
