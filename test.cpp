#include <iostream>
#include <vector>
#include "Matrix.h"

using namespace std;


int main() {
  Matrix* matrix = new Matrix(10,10);
  matrix->setAll(2);
  cout<<matrix->toString()<<std::endl;
  Matrix* mx = matrix->multiply(2);
  cout<<mx->toString()<<endl;

  VectorMatrix tab = {{1,2,3},{4,5,6}};

  Matrix* m = new Matrix({{3,2,1,5},{9,1,3,0}});
  Matrix* n = new Matrix({{2,9,0},{1,3,5},{2,4,7},{8,1,5}});
  Matrix* h = m->multiply(n);
  cout<<h->toString()<<endl;

}
