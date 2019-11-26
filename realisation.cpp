#include "vector.h"

void scanVector(Vector array[]) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << "input [" << (i + 1) << "]" << "[" << (j + 1) << "]: ";
			cin >> array[i].matrix[j];
		}
	}
}

void outputVector(Vector array[]) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << "\t" << array[i].matrix[j];
		}
		cout << endl;
	}
}

void mergeSort(int& array, int len) {
	int* arr = &array;
	if (len < 2) {
		return;
	}

	int* leftPartOfArray = new int[len / 2];
	int* rightPartOfArray = new int[len - len / 2];

	for (int l = 0; l < len / 2; l++) {
		leftPartOfArray[l] = arr[l];
	}
	for (int h = 0; h < len - len / 2; h++) {
		rightPartOfArray[h] = arr[len / 2 + h];
	}

	mergeSort(*leftPartOfArray, len / 2);
	mergeSort(*rightPartOfArray, len - len / 2);


	int left = 0, right = 0;
	for (int i = 0; i < len; i++) {
		if (left >= len / 2) {
			arr[i] = rightPartOfArray[right];
			right++;
			continue;
		}
		if (right >= len - len / 2) {
			arr[i] = leftPartOfArray[left];
			left++;
			continue;
		}
		if (leftPartOfArray[left] < rightPartOfArray[right]) {
			arr[i] = leftPartOfArray[left];
			left++;
		}
		else {
			arr[i] = rightPartOfArray[right];
			right++;
		}
	}

	delete[] leftPartOfArray;
	delete[] rightPartOfArray;
}
void sortVector(Vector array[]) {
	for (int i = 0; i < size; i++) {
		int cols[size] = { 0 };
		for (int g = 0; g < size; g++) {
			cols[g] = array[g].matrix[i];
		}
		mergeSort(*cols, size);
		for (int g = 0; g < size; g++) {
			array[g].matrix[i] = cols[g];
		}
	}
}
void calcVector(Vector array[]) {
	int a = 1,b=0 ,f = 0, g = 1, i = 0;
	for (b = 1; b < size; b++) {
		for (i = 0; i < g; i++) {
			a = a * array[i].matrix[g];
		}
		f += a;
		cout << "No" << g << "=" << a << endl;
		a = 1; g = 0;
	}
	cout << "Avarage is : " << f / 5 << endl;
}
