#include <iostream>

using namespace std;

int main()
{
    int number [350];
    for (int i=0; i<349; i++) number[i]=0;
    number[349]=1;
    for (int i=1; i<=1000; i++){
        int j=349;
        while (j>=(349-((i*10)/33))){
            number[j]*=2;
            j--;
        }
        for (int k=349; k>=j; k--){
            number[k-1]+=number[k]/10;
            number[k]=number[k]%10;
        }
    }
    long long sum=0;
    for (int i=349; i>=0; i--){
        sum+=number[i];
    }
    cout << sum;
    return 0;
}
