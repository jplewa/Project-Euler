#include <iostream>

using namespace std;

int main()
{   long long result=1;
    for (int i=1; i<=20; i++){
        result*=(20+i);
        result/=i;
    }
    cout << result;
}
