/*
 *
 * test.c
 * Author: Mahmoud Elmohr
 *
 */


#include "search.h"
#include <stdio.h>


int main() {

	int array[] = {1, 3,  5, 7, 9};
	//int array[] = { 1, 3 };
	//int array[] = { 1};


	int n = sizeof(array) / sizeof(array[0]);

	int value = 5;

	int index = binary_search(value, array, n);
	//int index = exponential_search(value, array, n);
	//int index = interpolation_search(value, array, n);

	if (index > -1) {
		printf("Value %i is found at index %i\n", value, index);
	} else {
		printf("Value %i is not found", value);
	}

	return 0;
}
