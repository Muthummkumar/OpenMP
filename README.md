# Parellal programming with OpenMP

This repository showcases experimental code comparing serial and OpenMP-based parallel implementations.

It features two primary comparison programs:

**Sum Calculation:**  Demonstrates the simple sum of natural numbers in both serial (sum.c) and parallel (omp_sum.c) versions.

**Pi Estimation:** Implements Pi calculation using integral calculus in serial (pi.c) and parallel (parallel_pi.c) versions with OpenMP.

Additionally, the repository includes Kmp_blocktime.c, which explores various environment variables such as **GOMP_CPU_AFFINITY**, **KMP_AFFINITY**, **KMP_BLOCKTIME**, **OMP_WAIT_POLICY**, and **OMP_PROC_BIND**, providing insights into performance tuning and parallel execution behavior.