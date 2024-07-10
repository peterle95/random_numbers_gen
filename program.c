#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

/*The Fisher-Yates shuffle algorithm, also known as the Knuth shuffle, 
is used in this code to efficiently generate unique random numbers. 

Here's how it's implemented:

1. The loop runs count times, where count is the number of unique random numbers we want to generate.
2. if (range == 0) break; is a safety check to prevent accessing out-of-bounds array elements if we've used all available numbers.
3. int index = rand() % range; generates a random index within the current range.
4. printf("%d", numbers[index]); prints the randomly selected number.
5. numbers[index] = numbers[--range]; is the key part of the Fisher-Yates shuffle:
    It decreases range by 1 (with --range)
    It then replaces the selected number with the last number in the current range
6. The space is printed between numbers, except after the last number.
*/

void generateUniqueRandomNumbers(int count, int min, int max) {
    int range = max - min + 1;
    int *numbers = malloc(range * sizeof(int));
    
    if (numbers == NULL) 
    {
        printf("Memory allocation failed\n");
        return;
    }

    for (int i = 0; i < range; i++) 
    {
        numbers[i] = min + i;
    }

    for (int i = 0; i < count; i++) 
    {
        if (range == 0) 
            break;
        int index = rand() % range;
        printf("%d", numbers[index]);
        numbers[index] = numbers[--range];
        if (i < count - 1) 
            printf(" ");
    }
    printf("\n");
    free(numbers);
}

int main() 
{
    int count, min, max;
    
    printf("Enter the number of unique random numbers to generate: ");
    scanf("%d", &count);
    
    printf("Enter the minimum value of the range: ");
    scanf("%d", &min);
    
    printf("Enter the maximum value of the range: ");
    scanf("%d", &max);
    
    if (min > max) {
        printf("Error: Minimum value cannot be greater than maximum value\n");
        return 1;
    }
    
    srand(time(NULL));
    generateUniqueRandomNumbers(count, min, max);
    
    return 0;
}