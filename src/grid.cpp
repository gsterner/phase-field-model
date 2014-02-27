#include <stdio.h>
#include <iostream>
#include <vector>
#include "grid.h"
using std::vector;



void printMatrix(vector<double> *matrix, int width, int height)
{
  //Needs to be rewritten for vector of vectors implementation
  std::cout << "wifth" << width << std::endl;   
  std::cout << "height" << height << std::endl; 
  for(int i=0; i < width; i++)
  {
    for(int j=0; j < height; j++)
    {
      std::cout << matrix->at(i+j);
    }  
    std::cout << std::endl;
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

void copyPointerToMatrix(double *matrix_p, int rows, int cols)
{

  vector<vector<double> > data(rows, vector<double>(cols));
  
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


