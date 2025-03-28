#include<algorithm>
using namespace std;

//bubble sort

void bubble_sort(int ar[], int n) {
	int flag;

	for (int i = 0; i < n - 1; i++) {
		flag = 0;
		for (int j = 0; j < n - 1 - i; j++) {
			if (ar[j] > ar[j + 1]) {
				swap(ar[j], ar[j + 1]);
				flag = 1;
			}
		}

		if (flag == 0) {
			break;
		}
	}
}