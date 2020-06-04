/*
 *
 * search.c
 * Author: Mahmoud Elmohr
 *
 */


#include "search.h"

/*
 * MIN
 * A macro to get the minimum of two elements
 */
#define MIN(x,y) ( ((x)<(y))? (x):(y) )


/*
 * Binary Search
 * Checks if the middle element in the array is the one being searched
 * If less than the middle then searches in the lower half of the array with the same way
 * If more than the middle then searches in the higher half of the array with the same way
 * Worst case O(log(n))		Average case O(log(n))		Best case O(1)			Space: O(1)
*/
int binary_search(int value, int arr[], int arr_size) {

	// Make sure the array size is not 0
	if (arr_size < 1) {
		return -1;
	}

	// Make sure the value to be searched doesn't exceed the boundaries
	if (value > arr[arr_size - 1] || value < arr[0]) {
		return -1;
	}

	int low = 0;
	int high = arr_size - 1;
	int mid;

	// Loop until low is greater than high (if this happens then the element is not in the array)
	while (low <= high) {
		mid = low + (high - low) / 2;	// Set the middle position
		if (value < arr[mid]) {
			high = mid - 1;				// If the element is less than the middle element, change the upper bound
		} else if (value > arr[mid]) {
			low = mid + 1;				// If the element is more than the middle element, change the lower bound
		} else {
			return mid;
		}
	}

	// If reached here then the element is not in the array
	return -1;
}



/*
 * Exponential Search
 * It first checks the proper search boundaries then performs binary search
 * Checking the boundaries takes O(log(i)) Where i is the index of the element in the array which is less than n
 * Binary search on the chosen subset (from i/2 to i) takes O(log(i)) as well
 * Worst case O(log(i))		Average case O(log(i))		Best case O(1)			Space: O(1)
*/
int exponential_search(int value, int arr[], int arr_size) {

	// Make sure the array size is not 0
	if (arr_size < 1) {
		return -1;
	}

	// Make sure the value to be searched doesn't exceed the boundaries
	if (value > arr[arr_size - 1] || value < arr[0]) {
		return -1;
	}

	int low = 0;
	int high = 1;
	int mid;

	// Determine the upper boundary exponentially
	while (value > arr[high] && high < arr_size - 1) {
		high *= 2;
	}

	low = high / 2;						// Lower boundary is half the upper boundary
	high = MIN(high + 1, arr_size);		// Accommodates where the upper boundary is larger than array size

	// Loop until low is greater than high (if this happens then the element is not in the array)
	while (low <= high) {
		mid = low + (high - low) / 2;	// Set the middle position
		if (value < arr[mid]) {
			high = mid - 1;				// If the element is less than the middle element, change the upper bound
		} else if (value > arr[mid]) {
			low = mid + 1;				// If the element is more than the middle element, change the lower bound
		} else {
			return mid;
		}
	}

	// If reached here then the element is not in the array
	return -1;

}


/*
 * Interpolation Search
 * Similar to binary search but doesn't use the middle position,
 * It uses interpolation of the to be searched value in accordance to the lowest and highest values in the array
 * Worst case O(n)		Average case O(log(log(n)))		Best case O(1)			Space: O(1)
*/
int interpolation_search(int value, int arr[], int arr_size) {

	// Make sure the array size is not 0
	if (arr_size < 1) {
		return -1;
	}

	// Make sure the value to be searched doesn't exceed the boundaries
	if (value > arr[arr_size - 1] || value < arr[0]) {
		return -1;
	}

	int low = 0;
	int high = arr_size - 1;
	int mid;

	// Loop until low is greater than high (if this happens then the element is not in the array)
	// Also make sure low is not equal high, otherwise interpolation will divide  0 by 0
	while (low <= high && low != high) {
		// set the position to be examined using interpolation
		mid = low + ((value - arr[low]) * (high - low) / (arr[high] - arr[low]));
		if (value < arr[mid]) {
			high = mid - 1;		// If the element is less than the middle element, change the upper bound
		} else if (value > arr[mid]) {
			low = mid + 1;		// If the element is more than the middle element, change the upper bound
		} else {
			return mid;
		}
	}


	if (value == arr[low]) {
		// Accommodates the case where low = high
		return low;
	} else {
		// If reached here then the element is not in the array
		return -1;
	}
}


