#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    char number [1001];
    char* result;
    cout << "Podaj liczbe: " << endl;
    result=fgets (number, 1000, stdin);
    if (result==NULL) printf ("\nblad odczytu\n");


    long long product=1;
    for (int i=0; i<13; i++){
        product*=(number[i]-48);
    }
    long long max_product=product;
    for (int i=13; i<1000; i++){
        if ((number[i-13])>48) product/=((number[i-13])-48);
        else{
            product=1;
            for (int j=i-12; j<i; j++){
                product*=(number[j]-48);
            }
        }
        product*=((number[i])-48);
        if (product>max_product) max_product=product;
    }
    cout << "Najwiekszy iloczyn to: " << max_product << endl;

}
