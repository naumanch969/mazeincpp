#include <iostream>
using namespace std;

int binarySearch(int a[], int key, int min, int max)
{
    if (min > max)
        return 0;

    int mid = (min + max) / 2;

    if (a[mid] > key)
    {
        binarySearch(a, key, min, mid - 1);
    }
    else if (a[mid] < key)
    {
        binarySearch(a, key, mid + 1, max);
    }
    else
    {
        cout << "index " << mid;
        return mid;
    }
}

int main()
{

    int a[5] = {1, 2, 3, 4, 5};
    int key = 5;
    cout << key << " is at index " << binarySearch(a, key, 0, size(a)) << " of array.";

    return 0;
}