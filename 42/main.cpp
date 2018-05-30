#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int un_triangle(int x){
    for (int i=1; i*(i+1) <= 2*x; i++){
        if ((i*(i+1)) == 2*x) return i;
    }
    return 0;
}

int main(){
    ifstream words;
    words.open ("C:\\Users\\Julia\\Documents\\euler\\42\\words.txt");
    words.ignore(1);

    string w[2000];

    int i=0;
    int longest=0;
    int longest_index;
    while (i < 2000){
        getline(words, w[i], '\"');
        if (w[i].size() > longest){
            longest=w[i].size();
            longest_index=i;
        }
        words.ignore(2);
        i++;
    }
    int counter=0;
    i=0;
    while (!w[i].empty()){
        int sum=0;
        for (int j=0; j < w[i].size(); j++) sum+=(int)(w[i][j])-64;
        if (un_triangle(sum) != 0) counter++;
        i++;
    }
    cout << counter << endl;
}
