#include "Arrays.h"
#include <iostream>
#include <string>

using namespace std;


int find(int n, int* arr, int size) {
	for (int i = 0; i < size; i++)
		if (arr[i] == n) return i;
	return -1;
}

int replace(int index, int n, int* arr) {
	if (index < 0) {
		throw invalid_argument("Index not in range");
	}

	int x = arr[index];
	arr[index] = n;
	return x;
}

void add(int n, int*& arr, int size) {
	int* oldArr = arr;		// point at given array

	arr = new int[size + 1];	// create new array with one extra element

	for (int i = 0; i < size; i++)	// copy contents from old array to new array
		arr[i] = oldArr[i];

	arr[size] = n;	// add last element

	delete[] oldArr; // deallocate old array
}

void remove(int index, int*& arr, int size) {
	if (index < 0 || index >= size)
		throw invalid_argument("Index " + to_string(index) + " not in range 0.." + to_string(size));

	int* oldArr = arr;	// point at given array 

	arr = new int[size - 1];	// create new array with one less element

	int arrPos = 0;	// counter for new array

	for (int i = 0; i < size; i++) {
		if (i == index) continue;	// do not copy target index
		arr[arrPos++] = oldArr[i];	// only increment arrPos when element has been copied
	}

	delete[] oldArr;	// deallocate old array
}