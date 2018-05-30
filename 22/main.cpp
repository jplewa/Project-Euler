#include <iostream>
#include <string>
#include <cctype>
#include <fstream>

using namespace std;

void mv(char a[20], char b[20]){
    for (int i=0; i<20; i++){
        a[i]=b[i];
    }
}

int main(){
    ifstream names;
    names.open ("C:\\Users\\Julia\\Documents\\euler\\22\\p022_names.txt");
    names.ignore(1);

    char name[6000][20];
    for (int i=0; i<20*6000; i++) name[i/6000][i%6000]=0;

    int counter=0;
    while (counter < 6000 && names.peek() != EOF){
        int chars=0;
        while (names.peek() != '\"'){
            name[counter][chars]=names.get();
            chars++;
        }
        names.ignore(3);
        counter++;
    }

//    for (int i=0; i<20; i++){
//        cout << name[0][i];
//    }
//    cout << endl << endl;

    for (int i=19; i>=0; i--){
        for (int j=1; j<counter; j++){
            char tmp[20];
            mv(tmp, name[j]);
            int k=j-1;
            while (k >= 0 && (int) name[k][i] > (int) tmp[i]){
                mv(name[k+1], name[k]);
                k=k-1;
            }
            mv(name[k+1],tmp);
        }
    }
    int scores[counter];
    for (int i=0; i<counter; i++){
        scores[i]=0;
        for (int j=0; j<20 && (int) name[i][j]!=0; j++){
            scores[i]+=(name[i][j]-64);
        }
    }
    long long sum=0;
    for (int i=0; i<counter; i++){
        sum+=((i+1)*scores[i]);
    }
    cout << sum;
    return 0;
}
