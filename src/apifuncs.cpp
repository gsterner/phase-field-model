#include <stdio.h>
#include <iostream>
#include "grid.h"
#include "physics.h"
using std::cout;
//using Grid::Grid;

void modelAIntegration(double *matrix_p, int rows, int cols, double delta_x, double delta_t, int time_steps)
{
  Grid grid = Grid(matrix_p, rows, cols);
  Grid temp_grid = Grid(matrix_p, rows, cols);

  for(int t = 0; t < time_steps; t++)
    {
      for(int i = 0; i < rows; i++)
	{
	  for(int j = 0; j < cols; j++)
	    {
	      //cout << " bef--> "<< grid.at(i,j) << std::endl;
	      temp_grid.setAt(i, j, modelAStep(grid.at(i,j),
					       grid.at(i - 1,j),
					       grid.at(i + 1,j),
					       grid.at(i,j - 1),
					       grid.at(i,j + 1),
					       delta_t, delta_x));
	      //cout << " after-> "<< grid.at(i,j) << std::endl;
	      //cout << std::endl;

	    }
	}
      grid = temp_grid;
    }
  grid.copyMatrixToPointer(matrix_p); 
}

void printInData(double *matrix_p, int rows, int cols, double delta_x, double delta_t, int time_steps)
{
  Grid grid = Grid(matrix_p, rows, cols);
  cout << "-------------" << std::endl;
  grid.printMatrix();
  cout << "-------------" << std::endl;
  cout << "delta_x " << delta_x << std::endl;
  cout << "delta_t " << delta_t << std::endl;
  cout << "time_steps " << time_steps << std::endl;

}

void copyPointerToMatrixCpp(double *matrix_p, int rows, int cols)
{
  Grid grid = Grid(matrix_p, rows, cols);
  cout << "-------------" << std::endl;
  grid.printMatrix();
  cout << "-------------" << std::endl;
  grid.setAt(0,0,0.3333);
  grid.printMatrix();
  cout << "-------------" << std::endl;
  grid.copyMatrixToPointer(matrix_p);
  // cout << "laplace " << laplace(0.3,0.1,0.1,0.1,0.1) << std::endl;
}


extern "C"
{

  int g_func() {
    return 133;
  }

  void print_array(double *test_array, int array_size) 
  {
    int i;
    //Grid grid = Grid(); 
    //grid.copyPointerToVector(test_array, array_size);
    for(i = 0; i < 10; i++)
      {
	printf("%f\n", test_array[i]);
      }
    return;
  }

  void print_matrix(double *matrix_p, int rows, int cols)
  {   
    copyPointerToMatrixCpp(matrix_p, rows, cols);
  }

  void model_a_integration(double *matrix_p, 
			   int rows, 
			   int cols, 
			   double delta_x,
			   double delta_t,
			   int time_steps)
  {
    //printInData(matrix_p, rows, cols, delta_x, delta_t, time_steps);
    modelAIntegration(matrix_p, rows, cols, delta_x, delta_t, time_steps);
  }

}

