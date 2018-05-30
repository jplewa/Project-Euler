#include <iostream>

using namespace std;

int SumSq();
int SqSum();

int main()
{
    long long sumsq = SumSq();
    long long sqsum = SqSum();
    cout << sumsq-sqsum;
    return 0;
}

int SumSq(){
    long long sum=0;
    for (int i=1; i<=100; i++){
        sum+=i;
    }
    sum = sum*sum;
    return sum;
}

int SqSum(){
    long long sum=0;
    for (int i=1; i<=100; i++){
        sum+=i*i;
    }
    return sum;
}
