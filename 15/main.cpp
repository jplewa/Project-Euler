#include <iostream>

using namespace std;

#define n 21

//long long grid(long long c, int w, int k,long long g [n][n]){
    //if (g[w][k]!=0) return g[w][k];
    //else{
        //c=c+grid(c, w-1, k, g)+grid(c, w, k-1, g);
    //}
    //return c;
//}

int main()
{
    long long g[n][n];

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (i==0 || j==0) g[i][j]=1;
            else g[i][j]=0;
        }
    }
    for (int i=1; i<n; i++){
        for  (int j=1; j<=i; j++){
            g[i][j]=g[i][j-1]+g[i-1][j];
            g[j][i]=g[i][j];
        }
    }
    cout << g[n-1][n-1];

    return 0;
}
