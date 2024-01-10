#include <cstdio>
#include <vector>
#include "omp.h"
#include "unistd.h"

int main()
{
  int N = 1000000;
  int k = 0;

#pragma omp parallel num_threads(4)
  {
    int thid = omp_get_thread_num();
    int numth = omp_get_num_threads();
    int klocal = 0;

#pragma omp for reduction(+:k);
    for (int i = 0; i < N; i++) { 
      k = k + 1;
    }

//#pragma omp for
//    for (int i = 0; i < N; i++) { 
//      klocal = klocal + 1; 
//    }
//    printf("klocal = %d\n", klocal);
//
//#pragma omp atomic
//    k = k + klocal;
//#pragma omp critical
//    {
//      k = k + klocal;
//    }
  }

  printf("%d %d\n", k, N);
  return 0;
}
