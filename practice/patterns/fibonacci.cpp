#include <iostream>
using namespace std;
int main() {
    int a = 0, b = 1, next = 0, n;
    cout << "Enter value of n " ;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cout << next << " ";
        next = a + b;
        a = b;
        b = next;
    }
    return 0;
}