#include <stdio.h>
#include <iostream>

void printInCpp()
{
  std::cout << "tjenare"; 
}

void copyPointerToVector(double *array_pointer, int array_size)
{

  for(int i=0; i < array_size; i++)
  {
    std::cout << array_pointer[i] <<  std::endl;
      
  }
 
}

extern "C"
{

  int g_func() {
    return 133;
  }

  void print_array(double *test_array, int array_size) 
  {
    int i;
    copyPointerToVector(test_array, array_size);
    for(i = 0; i < 10; i++)
      {
	printf("%f\n", test_array[i]);
      }
    return;
  }


}

