#include <iostream>
#include <cmath>

using namespace std;

long long pent (int n){
    return (long long)(((3*n)-1)*n)/2;
}

int un_pent (long long x){
    double xx=(double) x;
    double i=((1+(sqrt((24*xx)+1)))/6);
    if (modf(i, &xx) == 0) return (int) i;
    else return 0;
}

int main(){
    bool notFound=true;
    int i=2;
    while (notFound){
        for (int j=i-1; j>0; j--){
            int d=un_pent(pent(i)-pent(j));
            if (d != 0){
                int s=un_pent(pent(i)+pent(j));
                if (s != 0){
                    cout << pent(i)-pent(j) << endl;
                    notFound=false;
                }
            }
        }
        i++;
    }

}
