#include <stdio.h>
#include <stdbool.h>

int linearSearch(int array[], int n, int elementSearched); 

int main()
{
    int array[] = {5,2,1,3,6,4};
    int index = linearSearch(array, 6, 6);
    printf("The index wanted: %d", index);
}

int linearSearch(int array[], int n, int elementSearched) 
{
    bool found = false;
    int i = 0;
    
    while(!found && i < n)
    {
        if(elementSearched == array[i]) 
        {
            found = true;
        } else 
        {
            i++;
        }
        
    }
    
    return i;
}

/**
 * 
 * LinearSearch 
 * 
 * 
 * This algorithm is quite simple, we iterate until we find the element wanted
 * 
 * When it's found, we return the index where it is.
 * 
 * 
 **/
