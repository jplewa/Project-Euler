#include <iostream>

using namespace std;

int main(){
    int number[160];
    for (int i=0; i<159; i++) number[i]=0;
    number[159]=1;
    for (int i=2; i<=100; i++){
        for (int j=159; j>=0; j--){
            number[j]*=i;
        }
        for (int j=159; j>0; j--){
            if (number[j]>9){
                number[j-1]+=(number[j]/10);
                number[j]%=10;
            }
        }
    }
    int sum=0;
    for (int i=0; i<160; i++){
            cout << number[i];
            sum+=number[i];
    }
    cout << endl << endl;
    cout << sum;
}
