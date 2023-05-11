#include <stdio.h>
#include <omp.h>
int main()
{
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int b[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int c[10];
#pragma omp parallel num_threads(5)
    for (int i = 0; i < 0; i++)
    {
        c[i] = a[i] + b[i];
    }
    printf("Threads are set using directive clause\n");
    return 0;
}