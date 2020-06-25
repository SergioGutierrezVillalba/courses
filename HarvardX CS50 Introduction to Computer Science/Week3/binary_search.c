#include <stdio.h>
#include <stdbool.h>

int binarySearch(int array[], int start, int end, int elementSearched); 

int main()
{
    int array[] = {1,3,4,5,6,8,9};
    int index = binarySearch(array, 0, 7, 4);
    printf("The index wanted: %d", index);
}
/**
 *  Pre-conditions: 
 *      n > 0
*/
int binarySearch(int array[], int start, int end, int elementSearched) 
{
    if(start > end) 
        return -1;
        
    int middle = (start + end) / 2;
    
    if(array[middle] == elementSearched) 
        return middle;
    
    if(array[middle] > elementSearched) 
        return binarySearch(array, start, middle - 1, elementSearched);
    
    // must be array[middle] < elementSearched
    return binarySearch(array, middle + 1, end, elementSearched);
    
}


/**
 * Binary Search
 * 
 * This algorithm is based on 'Divide and conquer'.
 * 
 * Considering a sorted array, Binary Search divides the array recursively by the middle each step, 
 * looking in the left or in the right of an array given, depending on if the value searched is greater
 * or smaller than the middle element. 
 * 
 * The middle position is recalculated in every step.
 * 
 * Example:
 *  Consider a sorted array with this eleemnts: 1,3,4,5,6,8,9.
 * 
 *  Passing start = 0, end = 7 (size of the array) and looking for 4:
 * 
 *  - Check if the element is in the middle (= [start + end] / 2 = 7 / 2 = 3.5 -> Truncated due the type int -> middle = 3)
 *    if yes, return the middle index as the position search.
 * 
 *  - If not, if the middle element is bigger than the searched element, check if it's in the left, starting with 0 and ending in 3rd position.
 *  - If not, the middle element must be smaller than, so look for it at the right of the array, starting with 4th position and ending with 7th.
 * 
 *  Do this recursively until finding the desired element, if it's not there, return -1. 
 *    
 * 
 **/