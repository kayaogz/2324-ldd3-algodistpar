// Compilation: g++ avx-exemple.cpp -o avx-exemple -mavx2

#include <cstdio>
#include "immintrin.h"

int main()
{
        printf("hello\n");

        float x[8] = {0, 1, 2, 3, 4, 5, 6, 7};
        float y[8] = {2, 2, 2, 2, 2, 2, 2, 2};

        float z[8];

        __m256 vecx, vecy, vecz;

        vecx = _mm256_loadu_ps(&x[0]);
        vecy = _mm256_loadu_ps(&y[0]);
        vecz = _mm256_add_ps(vecx, vecy);
//      vecz = _mm256_sub_ps(vecx, vecy);
//      vecz = _mm256_mul_ps(vecx, vecy);
//      vecz = _mm256_div_ps(vecx, vecy);
        _mm256_storeu_ps(&z[0], vecz);

        for (int i = 0; i < 8; i++) { printf("%f ", z[i]); }
        printf("\n");

        return 0;
}
