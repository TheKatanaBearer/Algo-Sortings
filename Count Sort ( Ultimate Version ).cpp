#include <iostream>
#include <limits.h>
using namespace std;

void print_array(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int maximum(int* A, int n)
{
    int max = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (max < A[i])
        {
            max = A[i];
        }
    }

    return max;
}

void count_sort(int* A, int n)
{
    int max = maximum(A, n);
    int i, j;
    int* count = new int[max + 1];

    // initialize every element to zero
    for (i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        count[A[i]]++;
    }

    i = 0; // for count array
    j = 0; // for orignal array

    while (i <= max) // where max is the size of count array
    {
        if (count[i] > 0)
        {
            A[j] = i;
            count[i]--;
            j++;
        }
        else
        {
            i++;
        }
    }
    delete[] count;
}

int main()
{
    int arr[] = { 8, 7, 6, 5, 4, 4, 3, 2, 2, 1 };
    cout << "Array Before Sort:\n";
    print_array(arr, 10);
    cout << "Count Sort Running...\n";
    count_sort(arr, 10);
    cout << "Array After Sort:\n";
    print_array(arr, 10);
    return 0;
}