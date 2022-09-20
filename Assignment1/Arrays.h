#pragma once

int find(int n, int* arr, int size);
// accepts value, array, and array length
// returns index of first occurence of value

int replace(int index, int n, int* arr);
// accepts index, value, array
// replaces value at index with given value and returns the old value

void add(int n, int*& arr, int size);	// pass pointer by reference in order to reassign it
// accepts value, array, and array length
// adds value to the end of the array

void remove(int index, int*& arr, int size);	// pass pointer by reference
// accepts index, array, and array length
// removes element at index location