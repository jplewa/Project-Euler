#include <iostream>

using namespace std;

bool right (int a, int b, int c){
    if (a*a + b*b == c*c){
        cout << a << " " << b << " " << c << endl;
        return true;
    }
    else return false;
}


int triangles(int p){
    int counter=0;
    for (int i=p/2; i > 0; i--){
        for (int j=i; j+i > p-i-j; j--){
            if (right(i, j, p-i-j)) counter++;
        }
    }
    return counter;
}

int main(){
    int maxFound=0;
    int maxFound_i;
    for (int i=1000; i>0; i--){
        cout << i << ":" << endl;
        int x=triangles(i);
        if (x > maxFound){
            maxFound=x;
            maxFound_i=i;
        }
        cout << endl;
    }
    cout << maxFound_i;
}
