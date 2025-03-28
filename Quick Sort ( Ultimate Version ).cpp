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

void input_array(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Input Element [" << i + 1 << "]: ";
        cin >> arr[i];
    }
}

void swap(int& a, int& b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}

int partition(int* arr, int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    do
    {
        while (arr[i] <= pivot)
        {
            i++;
        }

        while (arr[j] >= pivot)
        {
            j--;
        }

        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    } while (i < j);

    swap(arr[low], arr[j]);

    return j;
}

void quick_sort(int* arr, int low, int high)
{
    if (low < high)
    {
        int partition_index = partition(arr, low, high);
        quick_sort(arr, low, partition_index - 1);
        quick_sort(arr, partition_index + 1, high);
    }
}

int main()
{
    int arr[] = { 23, 1, 45, 12, 78, 34, 56, 9, 3, 67 };
    cout << "Array Before Sort:\n";
    print_array(arr, 10);
    cout << "Quick Sort Running...\n";
    quick_sort(arr, 0, 9);
    print_array(arr, 10);
    return 0;
}