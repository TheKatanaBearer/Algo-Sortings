#include <iostream>

template<typename T>
void ReheapUp(T arr[], int first, int last) {

	int parent;

	if (last == 0) {
		return;
	}

	parent = (last - 1) / 2;

	if (arr[parent] > arr[last]) {
		return;
	}
	else {
		std::swap(arr[parent], arr[last]);
		ReheapUp(arr, first, parent);
	}
}

template<typename T>
void ReheapDown(T arr[], int first, int last) {

	int lc = (first * 2) + 1;
	int rc = (first * 2) + 2;
	int max = lc;

	if (lc > last) {
		return;
	}

	if (rc <= last && arr[rc] > arr[lc]) {
		max = rc;
	}

	if (arr[max] <= arr[first]) {
		return;
	}

	std::swap(arr[max], arr[first]);
	ReheapDown(arr, max, last);

}

template <typename T>
void Heap_Sort(T arr[], int size)
{

	// heapification
	for (int i = (size / 2 - 1); i >= 0; --i)
	{
		ReheapDown(arr, i, size - 1);
	}

	// Sorting
	for (int i = size - 1; i > 0; --i)
	{
		std::swap(arr[0], arr[i]);
		ReheapDown(arr, 0, i - 1);
	}
}