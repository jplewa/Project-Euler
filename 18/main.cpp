#include <iostream>
#include <fstream>

using namespace std;

int upto (int n){
    n--;
    int sum=0;
    while (n>0){
        sum+=n;
        n--;
    }
    return sum;
}

void findsum(int p[120], int row, int index, int n, int sum, int* m){
    if (n==14){
        if ((sum+p[index])>(*m)) (*m)=sum+p[index];
    }
    else{
        findsum(p, row+1, index+row, n+1, sum+p[index], m);
        findsum(p, row+1, index+row+1, n+1, sum+p[index], m);
    }
}

int main(){
    ifstream fsnumbers;
    fsnumbers.open ("C:\\Users\\Julia\\Documents\\euler\\18\\numbers.txt");

    int numbers[120];

    int counter = 0;
    while (counter < 120){
        fsnumbers >> numbers[counter];
        counter++;
    }
    int n=0;
    findsum(numbers, 1, 0, 0, 0, &n);
    cout << n;

}
