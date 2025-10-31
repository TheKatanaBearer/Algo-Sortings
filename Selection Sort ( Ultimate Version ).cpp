
#include<algorithm>

//selection sort 



// (wrong code)

void wrong_select_sort(int ar[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (ar[i] > ar[j]) {
				std::swap(ar[i], ar[j]);
			}
		}
	}
}



// (correct code)

void correct_select_sort(int ar[], int n) {

	for (int i = 0; i < n - 1; i++) {
		int min_idx = i;

		for (int j = i + 1; j < n; j++) {
			if (ar[j] < ar[min_idx]) {
				min_idx = j;

			}
		}

		if (ar[i] > ar[min_idx]) {
			std::swap(ar[i], ar[min_idx]);
		}
	}
}