#include <stdio.h>
#include <stdbool.h>

void printArray(int array[], int n);
void insertionSort(int array[], int n);

int main()
{
    int array[] = {5,2,1,3,6,4};
    insertionSort(array, 6);
    printArray(array, 6);
}

void insertionSort(int array[], int n) 
{ 
    int i, element, j; 
    for (i = 1; i < n; i++) { 
        element = array[i]; 
        j = i - 1; 
        for(; j >= 0 && array[j] > element; j--)
            array[j + 1] = array[j]; 
        array[j + 1] = element; 
    } 
} 
   
void printArray(int array[], int n) 
{ 
    for (int i = 0; i < n; i++) 
        printf("%d ", array[i]); 
}

/* 
    Insertion Sort 
    
    Insertion Sort works going element to element checking if that element is 
    sorted in its behind sorted array.
    
    Example:
    Consider the array with elements 5,2,1,3,6,4 in that order.
    
    Insertion Sort will check firstly if 5 is sorted. Is the first element so 
    it is.
    
    Secondly, it will check if 2 is sorted, but 5 is before 2, so it must swap 5
    with 2. -> 2 5 ... (... = unsorted part);
    
    Thirdly, it will check if 1 is sorted, but 2 and 5 are before, so it must swap
    5 and 2, putting 1 first.
    
        2 5 1 ....
        Swap 5 per 1 -> 2 1 5 ...
        Swap 2 per 1 -> 1 2 5 ...
        
    This code really does this:
        
        2 5 1 ...
        
        - i = 2
        
        - Save 1 in variable 'element', is the element that we are going to sort.
        
        - Swap until we find an element that is smaller than the element that we 
        are sorting or if during that search, we arrive to the beginning of the 
        array, place the element there (in that case our element should be the 
        first).
        
        - (j = 1) -> (5 > 1 && j >= 0 -> Swap) -> Swap 5 one position -> 2 5 5 ... 
        - (j = 0) -> (2 > 1 && j >= 0 -> Swap) -> Swap 2 one position -> 2 2 5 ...
        - (j = -1) -> Break because j is not = or > than 0.
        
        - Put element in j (=-1) + 1 -> j[0] = element; in this case. -> 1 2 5 ...
        
    So the conclusion is that Insertion Sort is sorting the array leaving behind 
    the i'th position, a sorted array.
    
    When it has to sort, if it's first position, is already sorted, if not, we are
    going to swap until getting the correct position according to the chosen 
    criteria.
    
*/