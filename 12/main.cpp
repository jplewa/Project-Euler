#include <iostream>

using namespace std;

int main()
{
    int n=2;
    int div;
    while (1){
        long long tn=0;
        for (int i=n; i>=1; i--){
            tn+=i;
        }
        div=2;
        for (long long i=2; i*i<=tn; i++){
            if (tn==i*i){
                div+=1;
            }
            else if (tn%i==0){
                div+=2;
            }
            if (div>500){
                cout << tn;
                return 0;
            }
        }
        n++;
    }
}
