#include <iostream>

// Function to find the location of the smallest element in the array
int locationOfSmallest(int array[], int s, int e)
{
    int j = s;
    for (int i = s; i < e; i++)
    {
        if (array[i] < array[j])
        {
            j = i;
        }
    }
    return j;
}

// Function to swap elements in the array
void swap(int array[], int i, int j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

// Function to perform selection sort on the array
void selectionSort(int array[], int length)
{
    int i = 0;
    while (i < length - 1)
    {
        int j = locationOfSmallest(array, i, length);
        swap(array, i, j);
        i++;
    }
}

int main()
{
    // Declare and initialize an array
    int myArray[] = {3, 1, 2};
    int length = sizeof(myArray) / sizeof(myArray[0]);

    // Print the original array
    std::cout << "Original Array: ";
    for (int i = 0; i < length; i++)
    {
        std::cout << myArray[i] << " ";
    }
    std::cout << std::endl;

    // Call the selectionSort function, passing the array and its length
    selectionSort(myArray, length);

    // Print the sorted array
    std::cout << "Sorted Array: ";
    for (int i = 0; i < length; i++)
    {
        std::cout << myArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
