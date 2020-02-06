#include "Matrix.h"

Matrix::Matrix(int h, int w) {
  this->height = h;
  this->width = w;
  this->matrix = new real_type*[h];
  for(int i = 0; i < h; i++) {
    this->matrix[i] = new real_type[w];
  }
}

Matrix::Matrix(VectorMatrix mx) {
  int h = mx.size();
  int w = mx[0].size();
  this->height = h;
  this->width = w;

  this->matrix = new real_type*[h];
  for(int i = 0; i < h; i++) {
    this->matrix[i] = new real_type[w];
  }

  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      this->matrix[i][j] = mx[i][j];
    }
  }
}

Matrix::~Matrix() {
  delete[] matrix;
}

std::string Matrix::toString() {
  std::string str = "";
  std::ostringstream os;
  for(int i = 0; i < this->height; i++) {
    for(int j = 0; j < this->width; j++) {
      os.str("");
      os.clear();
      os << this->matrix[i][j];
      str += os.str();
      str.push_back((j < this->width -1) ? ' ' : '\0');
    }
    str.push_back((i < this->height -1) ? '\n' : '\0');
  }
  return str;
}

void Matrix::set(int x, int y, int value) {
  this->matrix[x][y] = value;
}

void Matrix::setAll(int value) {
  for(int i = 0; i < this->height; i++) {
    for(int j = 0; j < this->width; j++) {
      this->matrix[i][j] = value;
    }
  }
}

bool Matrix::isMultiplyPossible(Matrix *b) {
  return (this->width == b->height) ? true : false;
}

Matrix* Matrix::multiply(double scalar) {
  Matrix *nmatrix = this;
  for(int i = 0; i < this->height; i++) {
    for(int j = 0; j < this->width; j++) {
      nmatrix->matrix[i][j] = nmatrix->matrix[i][j] * scalar;
    }
  }
  return nmatrix;
}

Matrix* Matrix::multiply(Matrix *mx) {

  if(!isMultiplyPossible(mx)) {
    return nullptr;
  }

  int nh = this->height, nw = mx->width, awidth = this->width;

  Matrix* nmatrix = new Matrix(nh, nw);
  nmatrix->setAll(0);
  for(int bw = 0; bw < nw; bw++) {
    for(int ah = 0; ah < nh; ah++) {
      for(int aw = 0; aw < awidth; aw++) {
        nmatrix->matrix[ah][bw] += this->matrix[ah][aw] * mx->matrix[aw][bw];
      }
    }
  }
  return nmatrix;
}
