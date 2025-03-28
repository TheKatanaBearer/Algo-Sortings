//insertion sort

void insertion_sort(int ar[], int n) {
	int x;
	int j;

	for (int i = 1; i < n; i++) {
		j = i - 1;
		x = ar[i];

		while (j > -1 && ar[j] > x) {
			ar[j + 1] = ar[j];
			j--;
		}

		ar[j + 1] = x;
	}
}