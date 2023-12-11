#include <iostream>
using namespace std;

int main() {

    int a, b, HCF, LCM;
    cout << "Enter a " ;
    cin >> a;
    cout << "Enter b " ;
    cin >> b;
    
    for (int i=1; i<=b; i++){
        if(a%i == 0 && b%i == 0){
            HCF = i;
        }
    }
    LCM = a * b / HCF;
    
    cout << "HCF is " << HCF << endl;
    cout << "LCM is " << LCM << endl;

    return 0;
}