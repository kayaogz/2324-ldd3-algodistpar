#include <cstdio>
#include <vector>
#include "omp.h"
#include "unistd.h"

int main()
{
  int N = 10;
  std::vector<int> A(N);

  for (int i = 0; i < N; i++) { A[i] = i; }

#pragma omp parallel num_threads(11)
  {
    int thid = omp_get_thread_num();
    int numth = omp_get_num_threads();

#pragma omp for
    for (int i = 0; i < N; i++) { 
      printf("hello i=%d thid=%d\n", i, thid);
      A[i] = i;
    }

//#pragma omp sections
//    {
//#pragma omp section
//      {
//        printf("hello thid=%d\n", thid);
//        for (int i = 0; i < N / 2; i++) { A[i] = i; }
//      }
//#pragma omp section
//      {
//        printf("hello thid=%d\n", thid);
//        for (int i = N / 2; i < N; i++) { A[i] = i; }
//      }
//    }
  }

  for (int i = 0; i < N; i++) { printf("%d ", A[i]); }
  printf("\n");

  return 0;
}
