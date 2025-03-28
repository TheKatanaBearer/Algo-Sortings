#include <iostream>
using namespace std;

void print_array(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(int* A, int mid, int low, int high)
{
    int i = low, j = mid + 1, k = 0;

    int* B = new int[high - low + 1];

    while (i <= mid && j <= high)
    {
        if (A[i] <= A[j])
        {
            B[k] = A[i];
            i++, k++;
        }
        else
        {
            B[k] = A[j];
            k++, j++;
        }
    }

    // Check for any remaining elements
    while (i <= mid)
    {
        B[k] = A[i];
        i++, k++;
    }

    while (j <= high)
    {
        B[k] = A[j];
        j++, k++;
    }

    // Now Copying the elements back to orignal array
    for (int f = 0; f < k; f++)
    {
        A[low + f] = B[f];
    }

    delete[] B;
}





void merge_sort(int* A, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        merge_sort(A, low, mid);
        merge_sort(A, mid + 1, high);
        merge(A, mid, low, high);
    }
}
int main()
{
    int arr[] = { 8,7,6,5,4,4,3,2,2,1 };
    cout << "Array Before Sort:\n";
    print_array(arr, 10);
    cout << "Merge Sort Running...\n";
    merge_sort(arr, 0, 9);
    cout << "Array After Sort:\n";
    print_array(arr, 10);
    return 0;
}