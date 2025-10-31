#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void countingSort(vector<int>& arr) {
    int maxVal = *max_element(arr.begin(), arr.end());

    // Step 1: Create count array
    vector<int> count(maxVal + 1, 0);

    // Step 2: Count each element
    for (int num : arr)
        count[num]++;

    // Step 3: Write elements back in sorted order
    int index = 0;
    for (int i = 0; i <= maxVal; i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }
}

int main() {
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};

    cout << "Original array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    countingSort(arr);

    cout << "Sorted array:   ";
    for (int num : arr) cout << num << " ";
    cout << endl;
}
