#include <iostream>
#include <string>

using namespace std;

int main()
{

    // Dimensions of the array
    int x = 3, y = 4, z = 5, counter = 0;

    // declare array
    // number of *'s on left side correspond to number of dimensions (3)
    // number of *'s on right side number of *'s of left side -1 (2)

    int*** a = new int**[x];

    // add second dimension
    // works by setting values of first array each to be pointers to another array
    for (int i = 0; i < x; i++)
    {
        a[i] = new int*[y];

        // Add third dimension
        // do the same as before but now must use both dimensions to create 3rd dimension
        // hence why this loop is within the 2D array's declaration array
        for (int j = 0; j < y; j++)
        {
            a[i][j] = new int[z];
        }
    }

    // Fill the 3D array with incremental values to track placement
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                counter++;
                a[i][j][k] = counter;
            }
        }
    }

    // print out the values of the array
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                cout << a[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl << endl;
    }

    // delete the arrays by unwinding the sets of pointers to the different dimensions
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++) {
            // delete the pointers to the 3rd dimension from the second array
            delete[] a[i][j];
        }
        // delete the pointers to the 2nd dimension from the first array
        delete[] a[i];
    }
    // delete the first array
    delete[] a;

    return 0;
}
