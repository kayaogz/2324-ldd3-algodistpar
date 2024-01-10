#include <cstdio>
#include "omp.h"
#include "unistd.h"

int calcul2()
{
  sleep(2);
  return 2;
}

int calcul3()
{
  sleep(3);
  return 3;
}

int calcul4()
{
  sleep(4);
  return 4;
}

int main()
{
  int deux, trois, quatre;
  int cinq, neuf;

#pragma omp parallel num_threads(5)
  {
    int thid = omp_get_thread_num();
    int numth = omp_get_num_threads();
//    printf("hello thid=%d\n", thid);
//    if (thid == 0)
//      deux = calcul2();
//    else if (thid == 1)
//      trois = calcul3();
//    else if (thid == 2)
//      quatre = calcul4();

#pragma omp sections
    {
#pragma omp section
      {
        printf("hello thid=%d\n", thid);
        deux = calcul2();
      }
#pragma omp section
      {
        printf("hello thid=%d\n", thid);
        trois = calcul3();
      }
#pragma omp section
      {
        printf("hello thid=%d\n", thid);
        quatre = calcul4();
      }
    }
  }

  int thid = omp_get_thread_num();
  printf("hello thid=%d\n", thid);

  neuf= deux + trois + quatre;

  printf("neuf = %d\n", neuf);

  return 0;
}
