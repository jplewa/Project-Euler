#include <iostream>
#include <fstream>

using namespace std;

int upto (int n){
    n--;
    int m=1;
    m+=n;
    m*=n;
    m/=2;

    return m;
}

int findsum(int p[5050], int n){
   for (int i=n-1; i>=1; i--){
        for (int j=0; j<i; j++){
           p[upto(i)+j]+=max(p[upto(i)+j+i], p[upto(i)+j+i+1]);
        }
    }
    return p[0];
}

int main(){
    ifstream fsnumbers;
    fsnumbers.open ("C:\\Users\\Julia\\Documents\\euler\\67\\numbers.txt");

    int numbers[5050];

    int counter = 0;
    while (counter < 5050){
        fsnumbers >> numbers[counter];
        counter++;
    }
    cout << findsum(numbers, 100);
    return 0;
}
