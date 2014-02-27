#include <vector>
using std::vector;

class Grid
{

 private:
  int abc;
  vector<vector<double> > data;

 public:
  void set_abc(int i) {abc = i;};
  int get_abc(){return abc;};
  void printMatrix(vector<double> *matrix, int width, int height);

  void copyPointerToVector(double *array_pointer, int array_size);

  void copyPointerToMatrix(double *matrix_p, int rows, int cols);
};



