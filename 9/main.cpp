#include <iostream>

using namespace std;

int main()
{
    int s=1000;
    int k;
    int l;
    for (int i=3; i<(s-3)/3; i++){
        for (int j=i+1; j<(s-i)/2; j++){
            k=i*i+j*j;
            l=j+1;
            while (l<i+j){
                if (l*l==k){
                    if (i+j+l==s){
                        cout << i*j*l;
                        return 0;
                    }
                    else break;
                }
                else l++;
            }
        }
    }
    return 0;
}
