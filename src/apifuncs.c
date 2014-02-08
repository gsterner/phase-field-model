#include <stdio.h>

int g_func() {
    return 133;
}

void print_array(double *test_array) 
{
    int i;
    for(i = 0; i < 10; i++)
    {
      printf("%f\n", test_array[i]);
    }
    return;
}


