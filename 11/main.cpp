#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int grid [20][20];
    int* result;
    for (int i=0; i<400; i++){
        cin >> grid[i/20][i%20];
    }

    long long product1=0;
    long long product2=0;
    long long product3=0;
    long long product4=0;
    long long maxproduct=0;


    for (int i=0; i<20; i++){
        for (int j=0; j<17; j++){
            product1=grid[i][j]*grid[i][j+1]*grid[i][j+2]*grid[i][j+3];
            product2=grid[j][i]*grid[j+1][i]*grid[j+2][i]*grid[j+3][i];
            if (i<17) product3=grid[i][j]*grid[i+1][j+1]*grid[i+2][j+2]*grid[i+3][j+3];
            if (i<17) product4=grid[i][19-j]*grid[i+1][18-j]*grid[i+2][17-j]*grid[i+3][16-j];
            if (product1>maxproduct) maxproduct=product1;
            if (product2>maxproduct) maxproduct=product2;
            if (product3>maxproduct) maxproduct=product3;
            if (product4>maxproduct) maxproduct=product4;
        }
    }
    cout << maxproduct << endl;
    return 0;
}
