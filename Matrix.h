#ifndef NEURALNET_MATRIX_H
#define NEURALNET_MATRIX_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#define real_type double

typedef std::vector< std::vector<real_type> > VectorMatrix;

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
  Matrix* transpoze();
  void T(); // transpoze in-place


  bool isMultiplyPossible(Matrix *b);

  Matrix* operator*(Matrix &mx); //matrix multiplication
private:
  uint32_t height, width;
  real_type** matrix;

};

#endif //NEURALNET_MATRIX_H
