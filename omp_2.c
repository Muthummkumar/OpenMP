/*

definig a thread inside a program ...
*/
#include <omp.h>
#include <stdio.h>

int main()
{
    printf("INI.\n");

    omp_set_num_threads(7);

    #pragma omp parallel
    {
        int t_ID = omp_get_thread_num();
        printf("hello parallel world!, thread_ID (%d)\n",t_ID);
    }

    printf("END.\n");
    return 0;
}

//OMP_NUM_THREADS, GOMP_CPU_AFFINITY, KMP_AFFINITY