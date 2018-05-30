#include <iostream>

using namespace std;

int main()
{
    int numbers[1001];
    for(int i=0; i<1001; i++) numbers[i]=0;

    numbers[1]=3;   // one
    numbers[2]=3;   // two
    numbers[3]=5;   // three
    numbers[4]=4;   // four
    numbers[5]=4;   // five
    numbers[6]=3;   // six
    numbers[7]=5;   // seven
    numbers[8]=5;   // eight
    numbers[9]=4;   // nine
    numbers[10]=3;  // ten
    numbers[11]=6;  // eleven
    numbers[12]=6;  // twelve
    numbers[13]=8;  // thirteen
    numbers[14]=8;
    numbers[15]=7;  // fifteen
    numbers[16]=7;  // sixteen
    numbers[17]=9;  // seventeen
    numbers[18]=8;  // eighteen
    numbers[19]=8;  // nineteen
    numbers[20]=6;  // twenty
    numbers[30]=6;  // thirty
    numbers[40]=5;  // forty
    numbers[50]=5;  // fifty
    numbers[60]=5;  // sixty
    numbers[70]=7;  // seventy
    numbers[80]=6;  // eighty
    numbers[90]=6;  // ninety
    numbers[100]=7; // one hundred
    numbers[1000]=11;

    for (int i=21; i<100; i++){
        if (numbers[i]==0){
            numbers[i]+=numbers[(i/10)*10];
            numbers[i]+=numbers[i%10];
        }
    }
    for (int i=101; i<1000; i++){
        if (i%100!=0) numbers[i]+=3;
        numbers[i]+=numbers[i/100];
        numbers[i]+=numbers[100];
        numbers[i]+=numbers[i%100];
    }

    numbers[100]+=3;

    int sum=0;
    for (int i=1; i<1001; i++) sum+=numbers[i];

    cout << sum << endl;
    return 0;
}
