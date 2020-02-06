#ifndef NEURALNET_MATRIX_H
#define NEURALNET_MATRIX_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#define real_type double

typedef std::vector< std::vector<int> > VectorMatrix;

class Matrix {
public:
  Matrix(int h, int w);
  Matrix(VectorMatrix mx);
  ~Matrix();

  std::string toString();
  void set(int x, int y, int value);
  void setAll(int value);

  Matrix* multiply(double scalar);
  Matrix* multiply(Matrix *mx);

  bool isMultiplyPossible(Matrix *b);
private:
  uint32_t height, width;
  real_type** matrix;

};

#endif //NEURALNET_MATRIX_H
