#include <stdio.h>
#include <omp.h>
#include <sched.h>

int main() {
    // Set the number of threads
    omp_set_num_threads(10000);

    // Parallel region where threads will be assigned specific cores
    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        int cpu_core = sched_getcpu();  // Get the CPU core this thread is running on

        // Print which thread is running on which CPU core
        printf("Thread %d is running on CPU core %d\n", thread_id, cpu_core);
    }

    return 0;
}
