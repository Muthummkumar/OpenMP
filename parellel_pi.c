#include <omp.h>  
#include <stdio.h>

static long num_steps = 10000000000;  
double step;

#define NUM_THREADS 2 // Define the number of threads to use

int main() {
    int i, nthreads; 
    double pi, sum[NUM_THREADS];  // Allocate sum array for each thread

    // Initialize sum array
    for (i = 0; i < NUM_THREADS; i++) {
        sum[i] = 0.0;
    }

    // Step size (interval width)
    step = 1.0 / (double) num_steps;

    // Set the number of threads to NUM_THREADS
    omp_set_num_threads(NUM_THREADS);

    // Get the start time (use double for wtime)
    double start_time = omp_get_wtime();

    int num;

    // Parallel region
    #pragma omp parallel
    {
        int i, id, nthrds_local;
        double x;

        // Get the thread ID
        id = omp_get_thread_num();

        // Get the total number of threads used in this parallel region
        nthrds_local = omp_get_num_threads();

        num = nthrds_local;
        // Make sure id does not exceed the number of available threads
        if (id < NUM_THREADS) {
            // Each thread computes a portion of the sum
            for (i = id; i < num_steps; i += nthrds_local) {
                x = (i + 0.5) * step;
                sum[id] += 4.0 / (1.0 + x * x);
            }
        }
    }

    // Combine the results from all threads
    for (i = 0, pi = 0.0; i < NUM_THREADS; i++) {
        pi += sum[i] * step;
    }

    // Get the end time and print the result
    double end_time = omp_get_wtime();

    printf("Approximation of Pi = %f\n", pi);
    printf("Time taken = %f seconds in thread %d\n", end_time - start_time,num);

    return 0;
}
