 #include <iostream>
#include <iomanip>
using namespace std;

int main()
{

    const int kernelRows = 3;
    const int kernelCols = 3;
    const int inputRows = 6;
    const int inputCols = 6;

    int kernel[kernelRows][kernelCols] = {
        {0, -1, 0},
        {-1, 5, -1},
        {0, -1, 0}};
    int inputMatrix[inputRows][inputCols] = {
        {45, 112, 203, 87, 15, 198},
        {154, 23, 91, 129, 76, 34},
        {200, 8, 175, 42, 63, 104},
        {92, 177, 58, 215, 33, 126},
        {71, 240, 103, 49, 189, 71},
        {14, 200, 33, 94, 178, 56}};
    int intermediateMatrix[inputRows + 2][inputCols + 2] = {};
    int outputMatrix[inputRows][inputCols] = {0};

    // Printing Input Matrix
    cout << "Input Matrix" << endl;
    for (int i = 0; i < inputRows; i++)
    {
        for (int j = 0; j < inputCols; j++)
        {
            cout << setw(3) << inputMatrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Intializing Intermediate Matrix: Adding zero borders (2 rows and cols having each entity of zero)
    for (int i = 0; i < (inputRows + 2); i++)
    {
        for (int j = 0; j < (inputCols + 2); j++)
        {
            if (i == 0 || i == 7 || j == 0 || j == 7)
            {
                intermediateMatrix[i][j] = 0;
            }
            else
            {
                intermediateMatrix[i][j] = inputMatrix[i - 1][j - 1];
            }
        }
    }
    // Printing Intermediate Matrix
    cout << "Intermediate Matrix" << endl;
    for (int i = 0; i < (inputRows + 2); i++)
    {
        for (int j = 0; j < (inputCols + 2); j++)
        {
            cout << setw(3) << intermediateMatrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Applying zero padding
    for (int i = 1; i < (inputRows + 1); i++) // Ignoring first and last both row and col.
    {
        for (int j = 1; j < (inputCols + 1); j++)
        {
            int sum = 0; // for each entity, sum starts from zero

            for (int k = 0; k < kernelRows; k++) // Calculation for each output entity
            {
                for (int l = 0; l < kernelCols; l++)
                {
                    sum += kernel[k][l] * intermediateMatrix[i + k - 1][j + l - 1]; // Multiplying each kernel entity with each entity of respective 3 by 3 submatrix of intermediateMatrix
                }
            }

            outputMatrix[i - 1][j - 1] = sum;
        }
    }

    // Printing Output Matrix
    cout << "After Calculation: " << endl;
    for (int i = 0; i < inputRows; i++)
    {
        for (int j = 0; j < inputCols; j++)
        {
            cout << left << setw(6) << outputMatrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}