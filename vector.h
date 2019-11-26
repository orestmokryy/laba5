#include <iostream>
#define size 5
using namespace std;



class Vector {
private:
	int matrix[size];
public:
	friend void scanVector(Vector array[]);
	friend void outputVector(Vector array[]);
	friend void sortVector(Vector array[]);
	friend void mergeSort(int& array, int length);
	friend void calcVector(Vector array[]);
};


