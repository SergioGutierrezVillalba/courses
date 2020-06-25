#include <stdio.h>
#include <stdbool.h>

void printArray(int array[], int n);
void bubbleSort(int array [], int n);
void testBubbleSort(void);

int main()
{
   testBubbleSort(); 
}

/*
    Pre-conditions:
        n > 0
*/
void bubbleSort(int array [], int n) 
{
    int counter = 0;
    bool finished = false;
    int lastElement;
    
    int sortedSize = 0;
    
    while(!finished) {
        
        lastElement = array[0];
        
        for(int i = 1; i < n - sortedSize; i++) 
        {
            if(lastElement > array[i]) 
            {
                // Swap
                array[i - 1] = array[i];
                array[i] = lastElement;
                counter++;
                
                if(n - sortedSize - 1 == i) 
                    // if element is in its final sorted position
                    // add 1 to iterate one less time the next round
                    sortedSize++;
                
            } 
            else
                // Advance
                lastElement = array[i];
            
        }
        
        if(counter == 0) 
            finished = true;
        
        counter = 0;
    }
    
    
}

void printArray(int array[], int n) 
{ 
    for (int i = 0; i < n; i++) 
        printf("%d ", array[i]); 
    printf("\n");
}

void testBubbleSort(void) 
{
    printf("Random Case: ");
    int randomCase[] = {5,2,1,8,6,4,7,3,9,10};
    printArray(randomCase, 10);
    bubbleSort(randomCase, 10);
    printArray(randomCase, 10);
    
    printf("Worst Case: ");
    int worstCase[] = {10,9,8,7,6,5,4,3,2,1};
    printArray(worstCase, 10);
    bubbleSort(worstCase, 10);
    printArray(worstCase, 10);
    
    printf("Best Case: ");
    int bestCase[] = {1,2,3,4,5,6,7,8,9,10};
    printArray(bestCase, 10);
    bubbleSort(bestCase, 10);
    printArray(bestCase, 10);
}

/**
 * 
 * Bubble Sort
 * 
 * This algorithm sorts elements based on 'bubbling', this is swapping elements
 * from left to right depending on if every pair of elements checked are sorted
 * according to the criteria wanted or not. 
 * 
 * A sorted array is being created at the right so this code in every iteration
 * only checks until the position of the last unsorted element, leaving sorted 
 * elements at the end.
 * 
 * Example:
 * 
 *  Consider the random case: 5,2,1,8,6,4,7,3,9,10
 * 
 *  Criteria: Ascending order
 * 
 *  So this algorithm does:
 * 
 *  Get 5 -> is 5 > 2 -> Yes -> Swap -> 2,5,1,8,6,4,7,3,9,10
 *  Continue with 5 -> is 5 > 1 -> Yes -> Swap -> 2,1,5,8,6,4,7,3,9,10
 *  Continue with 5 -> is 5 > 8 -> No
 *  Get 8 -> is 8 > 6 -> Yes -> Swap -> 2,1,5,6,8,4,7,3,9,10
 *  Continue with 8 -> is 8 > 4 -> Yes -> Swap -> 2,1,5,6,4,8,7,3,9,10
 *  Continue with 8 -> is 8 > 7 -> Yes -> Swap -> 2,1,5,6,4,7,8,3,9,10
 *  Continue with 8 -> is 8 > 3 -> Yes -> Swap -> 2,1,5,6,4,7,3,8,9,10
 *  Continue with 8 -> is 8 > 9 -> No
 *  Get 9 -> is 9 > 10 -> No
 *  End of the loop.
 * 
 *  Repeat this process until counter of swaps is 0 (that 
 *  means that every element of the array is sorted).
 * 
 *  Note: If an element swaps every time even at the end, it means that 
 *  is the bigger and since that moment is in its final, correct position
 *  so this program will iterate next time -1 times due to this. 
 * 
 *  Is inefficient to iterate over the complete array every time if you 
 *  have the right side already sorted and this side is increasing its 
 *  size on each step.
 *  
 *  
 * 
 **/