 #include <iostream>
using namespace std;

int main() {
      
    for(int i = 1; i<=9; i++){
       for(int j = 1; j<=9 - i; j++){
           cout << " " ;
       }
       for(int j = 1; j<= i; j++){
           cout << "* " ;
       }
       cout << endl;
    }
    for(int i = 8; i>=1; i--){
       for(int j = 8; j>=i - 8; j--){
           cout << " " ;
       }
       for(int j = i; j>= 1; j--){
           cout << "* " ;
       }
       cout << endl;
   }

    return 0;
}