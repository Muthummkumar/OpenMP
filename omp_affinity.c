#define _GNU_SOURCE  // Enable GNU-specific features
#include <stdio.h>
#include <omp.h>
#include <unistd.h>
#include <sched.h>  // Required for sched_getcpu()

int main() {
    // Set number of threads to 2
    omp_set_num_threads(2);

    #pragma omp parallel
    {
        // Get thread ID
        int thread_id = omp_get_thread_num();
        
        // Get total number of threads
        int num_threads = omp_get_num_threads();
        
        // Get the CPU core where the current thread is running
        int cpu_core = sched_getcpu();

        // Print thread ID and CPU affinity info
        printf("Hello from thread %d out of %d threads, running on core %d\n", 
                thread_id, num_threads, cpu_core);

        // Sleep to allow us to see that threads are staying on specific cores
        usleep(100000); // 100 ms
    }

    return 0;
}
