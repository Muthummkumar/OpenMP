
#include <stdio.h>
#include <omp.h>


static long num_steps = 100000;
double step;


int main ()
{
	  int i;

	  double x, pi, sum = 0.0;

	  double start_time, run_time;

	  step = 1.0/(double) num_steps;
        	 
	  start_time = omp_get_wtime();

	  for (i=1;i<= num_steps; i++){
		  x = (i-0.5)*step;
		  sum = sum + 4.0/(1.0+x*x);
	  }


	  pi = step * sum;
      double end_time = omp_get_wtime();
	  run_time = end_time - start_time;
	  printf("\n pi with %ld steps is %lf in %lf seconds\n ",num_steps,pi,run_time);
      return 0;

}	  

