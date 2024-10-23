/*

here we are running a block of code prellely
with the number of threads we have mentioned in the environment

*/
#include <omp.h>
#include <stdio.h>

int main()
{
    printf("INI.\n");

#pragma omp parallel
    {
        int t_ID = omp_get_thread_num();
        printf("hello parallel world!, thread_ID (%d)\n",t_ID);
    }

    printf("END.\n");
    return 0;
}