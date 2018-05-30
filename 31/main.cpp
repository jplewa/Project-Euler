#include <iostream>

using namespace std;

int main(){
    int coins[8]={1, 2, 5, 10, 20, 50, 100, 200};
    int money[201];
    for (int i=1; i<201; i++) money[i]=0;
    money[0]=1;
    for (int i=0; i<8; i++){
        for (int j=coins[i]; j<201; j++){
            if (j >= coins[i]) money[j]+=money[j-coins[i]];
        }
    }
    cout << money[200];
}
