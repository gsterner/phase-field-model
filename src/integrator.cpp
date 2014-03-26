#include "grid.h"
#include "physics.h"
#include "integrator.h"

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

	      temp_grid.setAt(i, j, modelAStep(grid.at(i,j),
					       grid.at(i - 1,j),
					       grid.at(i + 1,j),
					       grid.at(i,j - 1),
					       grid.at(i,j + 1),
					       delta_t, delta_x));
	    }
	}
      grid = temp_grid;
    }
  grid.copyMatrixToPointer(matrix_p); 
}
