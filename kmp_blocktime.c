#include <stdio.h>
#include <omp.h>
#include <unistd.h>  // For sleep function

int main() {
    omp_set_num_threads(4);  // Use 4 threads

    // First parallel region (do some work)
    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        printf("Thread %d is doing work...\n", thread_id);
        sleep(8);  // Simulate some work (e.g., a long computation)
    }

    // Simulate a pause between work phases
    printf("Main thread is sleeping for 5 seconds...\n");
    sleep(15);  // Main thread sleeps (no parallel work)

    // Second parallel region (do more work)
    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        printf("Thread %d is doing more work...\n", thread_id);
        sleep(8);  // Simulate more work
    }

    return 0;
}
