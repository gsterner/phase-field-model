#include <stdio.h>
#include <iostream>
#include <vector>
#include "grid.h"
using std::vector;

//-------------------------
Grid::Grid(double *matrix_p, int rows, int cols)
{
  numberRows = rows;
  numberCols = cols;

  data = vector<vector<double> >(rows, vector<double>(cols));
  
  for(int i=0; i < rows; i++)
  {
    int start = i * cols;
    int end = (i+1) * cols;
    vector<double>  row(matrix_p + start , matrix_p + end );
    data.at(i) = row;   
  }
}

//-------------------------
double Grid::at(int row, int col)
{
  return data.at(calcXIndex(row)).at(calcYIndex(col));
}

//-------------------------
void Grid::setAt(int row, int col, double value)
{
  data.at(calcXIndex(row)).at(calcYIndex(col)) = value; 
}

//-------------------------
void Grid::printMatrix()
{
  for(std::vector<vector<double> >::iterator it_rows = data.begin(); it_rows != data.end(); ++it_rows)
  {
    for(std::vector<double>::iterator it_elem = it_rows->begin(); it_elem != it_rows->end(); ++it_elem)
    {  
      std::cout << *it_elem << " ";
    }
    std::cout << std::endl;
  } 

}
//-------------------------
void Grid::copyMatrixToPointer(double *matrix_p)
{
  int elementCounter = 0;
  for(std::vector<vector<double> >::iterator it_rows = data.begin(); it_rows != data.end(); ++it_rows)
  {
    for(std::vector<double>::iterator it_elem = it_rows->begin(); it_elem != it_rows->end(); ++it_elem)
    {  
      matrix_p[elementCounter] = *it_elem;
      elementCounter++;
    }
  } 

}

//-------------------------
int Grid::calcXIndex(int index)
{
  return wrapIndex(index, numberRows);
}

//-------------------------
int Grid::calcYIndex(int index)
{
  return wrapIndex(index, numberCols);
}

//-------------------------
int Grid::wrapIndex(int index, int dimensionLength)
{
  if(-1 < index && index < dimensionLength)
    {
      return index;
    }
  else if(index < 0)
    {
      return dimensionLength + index;
    }
  else
    {
      return index - dimensionLength;
    }        
}

void copyPointerToVector(double *array_pointer, int array_size)
{
  vector<double> data(array_pointer, array_pointer + sizeof(double)*array_size);

  for(int i=0; i < array_size; i++)
  {
    std::cout << data.at(i) <<"yeah" <<  std::endl;
      
  }
 
}

void Grid::copyPointerToMatrix(double *matrix_p, int rows, int cols)
{

  data = vector<vector<double> >(rows, vector<double>(cols));
  
  for(int i=0; i < rows; i++)
  {
    int start = i * cols;
    int end = (i+1) * cols;
    vector<double>  row(matrix_p + start , matrix_p + end );
    data.at(i) = row;   
  }
  ////////////////////
  //Print matrix
  for(int i=0; i < rows; i++)
  {
    for(int j=0; j < cols; j++)
    {  
      std::cout << data.at(i).at(j) << " ";
    }
    std::cout << std::endl;
  } 
  ///////////////////
}



