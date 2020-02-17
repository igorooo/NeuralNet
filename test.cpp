#include <iostream>
#include <vector>
#include "Matrix.h"

using namespace std;

class Test {
public:
  int a,b;
  Test() {
    a = 2;
    b = 3;
  };

  Test operator*(Test &obj) {
    Test* nobj = new Test();
    nobj->a = obj.a * this->a;
    nobj->b = obj.b * this->b;
    return *nobj;
  }

};


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

  h = (*m) * (*n);
  cout<<endl<<h->toString()<<endl<<endl;

  h->T();
  cout<<h->toString()<<endl;

}
