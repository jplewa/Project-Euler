#include <iostream>

using namespace std;

bool pan_product(int a, int b){
    int p=a*b;
    int digits[10];
    for (int i=0; i<10; i++) digits[i]=0;
    while (a>0){
        digits[a%10]++;
        a/=10;
    }
    while (b>0){
        digits[b%10]++;
        b/=10;
    }
    while (p>0){
        digits[p%10]++;
        p/=10;
    }
    if (digits[0] != 0) return false;
    for (int i=1; i<10; i++){
        if (digits[i] != 1) return false;
    }
    return true;
}

struct node{
    int value;
    node* next;
};

typedef node node;

void add_node (node* L, int x){
    node* q=L;
    while (q->next != NULL && q->value != x) q=q->next;
    if (q->value != x){
        q->next=new node;
        q->next->value=x;
        q->next->next=NULL;
    }
}


int main(){
    node* L=new node;
    L->value=-1;
    L->next=NULL;

    for (int i=10; i<100; i++){
        for (int j=999; j>=100; j--){
            if (pan_product(i, j)){
                cout << i << " " << j << " " << i*j << endl;
                add_node(L, i*j);
            }
        }
    }
    for (int i=1; i<10; i++){
        for (int j=9999; j>=1000; j--){
            if (pan_product(i, j)){
                cout << i << " " << j << " " << i*j << endl;
                add_node(L, i*j);
            }
        }
    }

    cout << endl;

    int sum=0;
    while (L != NULL){
        if (L->value != -1){
            cout << L->value << endl;
            sum+=L->value;
        }
        L=L->next;
    }
    cout << endl << sum << endl;
}
