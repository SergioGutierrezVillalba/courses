#include <stdio.h>
#include <stdbool.h>

bool valid_triangle(int side1, int side2, int side3);

int main()
{
    printf("Valid Triangle: %d", valid_triangle(0, 4, 5));
    printf("Valid Triangle: %d", valid_triangle(3, 4, 5));
}

bool valid_triangle(int side1, int side2, int side3) {
    if(side1 <= 0 || side2 <= 0 || side3 <= 0) {
        // if any side is 0 or negative
        return false;
    }
    
    int side1Result = side1 - (side2 + side3);
    int side2Result = side2 - (side1 + side3);
    int side3Result = side3 - (side1 + side2);
    
    if(side1Result >= 0 || side2Result >= 0 || side3Result >= 0) {
        // any pair of sides must be greater than the third
        return false;
    } 
    
    return true;
}