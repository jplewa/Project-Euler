#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
    int found=0;
    int number;
    for (int d=999; d>2; d--){
        if (found < d){
            int* cycle=(int*)malloc(d*sizeof(int));
            for (int i=0; i<d; i++) cycle[i]=0;
            int div=1;
            int position=0;
            while (div != 0 && cycle[div] == 0){
                cycle[div]=position;
                div*=10;
                div%=d;
                position++;
            }
            if ((position-cycle[div]) > found){
                found=position-cycle[div];
                number=d;
            }
        }
    }
    cout << found << endl << number;
}
