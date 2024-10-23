#include <stdio.h>
#include <time.h>  // For clock()


int main() {
    int sum = 0;
    int i;
    
    // Capture the start time
    clock_t start_time = clock();

    // Loop to compute the sum
    for (i = 1; i <= 100; i++) {
        sum += i;
        // Print i value
        printf("i value: %d\n", i);
    }

    // Capture the end time
    clock_t end_time = clock();

    // Calculate the time taken
    double time_spent = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Print the final sum
    printf("Sum = %d\n", sum);

    // Print the computation time
    printf("Time taken = %f seconds\n", time_spent);

    return 0;
}
