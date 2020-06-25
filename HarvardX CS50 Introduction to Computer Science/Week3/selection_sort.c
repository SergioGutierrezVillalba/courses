#include <stdio.h>
#include <stdbool.h>

void printArray(int array[], int n);
void selectionSort(int array [], int n);
void testSelectionSort(void);

int main()
{
   testSelectionSort(); 
}

/*
    Pre-conditions:
        n > 0
*/
void selectionSort(int array [], int n) 
{
    int min;
    int minPos = 0;
    int sortedPos = 0;
    
    for(int i = 0; i < n; i++, sortedPos++) 
    {
        min = array[i];
        minPos = i;
        
        // Find the min in the unsorted side
        for(int j = sortedPos; j < n; j++)
            if(array[j] < min) 
            {
                min = array[j];
                minPos = j;
            }
        
        
        // Swap min with the first element of the unsorted side
        array[minPos] = array[i];
        array[i] = min;
        
    }
    
}

void printArray(int array[], int n) 
{ 
    for (int i = 0; i < n; i++) 
        printf("%d ", array[i]); 
    printf("\n");
}

void testSelectionSort(void) 
{
    printf("Random Case: ");
    int randomCase[] = {5,2,1,8,6,4,7,3,9,10};
    printArray(randomCase, 10);
    selectionSort(randomCase, 10);
    printArray(randomCase, 10);
    
    printf("Worst Case: ");
    int worstCase[] = {10,9,8,7,6,5,4,3,2,1};
    printArray(worstCase, 10);
    selectionSort(worstCase, 10);
    printArray(worstCase, 10);
    
    printf("Best Case: ");
    int bestCase[] = {1,2,3,4,5,6,7,8,9,10};
    printArray(bestCase, 10);
    selectionSort(bestCase, 10);
    printArray(bestCase, 10);
}

/**
* Selection Sort
* 
* This algorithm works getting the min element of the array an putting it before the unsorted array
* while reducing the size of the unsorted array.
* 
* Example:
* 
* Consider an array like this: 5,2,1,8,6,4,7,3,9,10
* 
* Selection Sort will search for the min, the number 1 in this case, and will swap it for the beginning 
* of the unsorted side. ( | is the mark for making easier to see the distinction between sorted and 
* unsorted sides, elements at the left of | will be the sorted side, right are unsorted ones).
* 
* Get 1 (the min of unsorted side) -> Swap for the beginning of the unsorted side -> 1 | 2 5 8 6 4 7 3 9 10
* Get 2 (the min of unsorted side) -> Swap for the beginning of the unsorted side -> 1 2 | 5 8 6 4 7 3 9 10
* Get 3 (the min of unsorted side) -> Swap for the beginning of the unsorted side -> 1 2 3 | 8 6 4 7 5 9 10
* Get 4 (the min of unsorted side) -> Swap for the beginning of the unsorted side -> 1 2 3 4 | 6 8 7 5 9 10
* Get 5 (the min of unsorted side) -> Swap for the beginning of the unsorted side -> 1 2 3 4 5 | 8 7 6 9 10
* And so on until arriving to the last element.
* 
*/