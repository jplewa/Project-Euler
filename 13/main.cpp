#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n[100][50];
    char buffer[101];
    for (int i=0; i<100; i++){
        scanf("%100s", buffer);
        for (int j=0; j<50; j++){
            n[i][j]=buffer[j]-48;
        }
    }
    int sum[52];
    for (int i=0; i<52; i++){
        sum[i]=0;
    }
    for (int i=49; i>=0; i--){
        int x=0;
        for (int j=0; j<100; j++){
            x+=n[j][i];
        }
        int index=i;
        while (x>0){
            sum[index+2]+=x%10;
            x/=10;
            if (sum[index+2]>9){
                x+=sum[index+2]/10;
                sum[index+2]=(sum[index+2])%10;
            }
            index--;
        }
    }
    cout << endl;
    for (int i=0; i<10; i++){
        cout << sum[i];
    }
    return 0;
}
