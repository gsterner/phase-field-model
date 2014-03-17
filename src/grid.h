#include <vector>
using std::vector;

class Grid
{

 private:
  vector<vector<double> > data;
  int numberRows;
  int numberCols;
  Grid() {};
  int calcXIndex(int index);
  int calcYIndex(int index);
  int wrapIndex(int index, int dimensionLength);

 public:
  Grid(double *matrix_p, int rows, int cols);

  double at(int row, int col);
  void setAt(int row, int col, double value);

  void printMatrix();
  void copyMatrixToPointer(double *matrix_p);
  void copyPointerToMatrix(double *matrix_p, int rows, int cols);
};



