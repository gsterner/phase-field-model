#include <vector>
using std::vector;

class Grid
{

 private:
  vector<vector<double> > data;
  Grid() {};

 public:
  Grid(double *matrix_p, int rows, int cols);

  void printMatrix();

  void copyPointerToMatrix(double *matrix_p, int rows, int cols);
};



