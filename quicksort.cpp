#include<iostream>
using namespace std;

int pivot(int arr[], int low, int high) {
	int pi = arr[low];
	int i = low, j = high;
	while (true) {
		while ((i <= high) && (arr[i] <= pi)) i++;
		while (arr[j] > pi) j--;
		if (i > j) break;
		else {
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	arr[low] = arr[j];
	arr[j] = pi;
	return j;
}


void quickSort(int arr[], int low, int high) {
	int pi = 0;
	if (high > low)
	{
		pi = pivot(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
		for (int i = low;i <= high;i++) { cout << arr[i] << " "; }
		cout << endl;
	}
	return;
}

int main() {
	int n;
	cin >> n;

	int* arr = new int[n];
	for (int i = 0;i < n;i++) { cin >> arr[i]; }
	quickSort(arr, 0, n - 1);
	for (int i = 0;i < n;i++) { cout << arr[i] << " "; }
	cout << endl;
}