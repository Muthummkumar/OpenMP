#include <stdio.h>
#include <omp.h>

int main() {
    int i, sum = 0;
    int thread_sum[8] = {0};  // Initialize the thread_sum array to 0

    // Set the number of threads to 4
    omp_set_num_threads(8);

    // Start the timer
    double start_time = omp_get_wtime();

    // Parallel region
    #pragma omp parallel
    {
        // Get thread ID
        int ID = omp_get_thread_num();
        thread_sum[ID] = 0;

        // Distribute the loop iterations among threads
        #pragma omp for
        for (i = 1; i <= 100; i++) {
            thread_sum[ID] += 1;  // Each thread increments its local sum

            // Print i and thread ID
            printf("i value: %d, Thread ID: %d\n", i, ID);
        }
    }

    // Combine the local sums from each thread
    #pragma omp barrier
    for (i = 0; i < 8; i++) { 
        sum += thread_sum[i];
    }

    // End the timer
    double end_time = omp_get_wtime();

    // Print the final sum
    printf("Sum = %d\n", sum);

    // Print the elapsed time
    printf("Time taken = %f seconds\n", end_time - start_time);

    return 0;
}
