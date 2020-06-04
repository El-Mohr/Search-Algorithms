# Search-Algorithms
A collection of different search algorithms implemented in C

## Implemented algorithms:

- Binary Search
- Exponential Search
- Interpolation Search

All functions return an int with the index of the element being searched if found in the array, if not fount a -1 is returned.
The functions arguments are: an int of the value to be searched, an array of int, and the array size.

## Performance analysis of the implemented functions:

- binary_search:		        Worst case O(log(n))		Average case O(log(n))		    Best case O(1)			Space: O(1)
- exponential_search: 	    Worst case O(log(i))		Average case O(log(i))		    Best case O(1)			Space: O(1)
- interpolation_search: 		Worst case O(n)		      Average case O(log(log(n)))		Best case O(1)			Space: O(1)
