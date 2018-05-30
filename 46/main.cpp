#include <iostream>

using namespace std;

bool prime(int x){
    if (x < 2) return false;
    if (x == 2 || x == 3) return true;
    if (x%3 == 0 || x%2 == 0) return false;
    for (int i=5; i*i<=x; i+=2){
        if (x%i == 0) return false;
    }
    return true;
}

bool double_square (int x){
    if (x == 0 || x == 1) return 0;
    if (x%2 == 1) return 0;
    x/=2;
    int i=1;
    while (i*i < x) i++;
    if (i*i == x) return 1;
    else return 0;
}

int main(){
	bool found=false;
	int number=35;
	while (!found){
        number+=2;
        if (!(prime(number))){
            //cout << number << ": ";
            bool goal=false;
            for (int p=3; p<number; p+=2){
                if (prime(p) && double_square(number-p) != 0){
                    //cout << p << "+2*" << double_square(number-p) << "*" << double_square(number-p) << endl;
                    goal=true;
                }
            }
            if (!goal) found=true;
        }
    }
    cout << number;
}
