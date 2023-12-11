#include <iostream>
using namespace std;

int main()
{

    int a[5] = {3, 2, 33, 62, 21};

    // Printing Non-sorted array
    for (int i = 0; i < size(a); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    // Insertion Sort
    for (int j = 1; j <= size(a); j++)
    {

        int i = 0;
        while (a[j] > a[i])
        {
            i++;
        }

        int m = a[j];

        for (int k = 0; k <= j - i - 1; k++)
        {
            a[j - k] = a[j - k - 1];
        }

        a[i] = m;
    }

    // Printing Sorted Array
    for (int i = 0; i < size(a); i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}