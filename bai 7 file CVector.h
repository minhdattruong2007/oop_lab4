#ifndef CVECTOR_H
#define CVECTOR_H

#include <iostream>
#include <vector>
using namespace std;

class CVector {
private:
   vector<double> data;

public:
   CVector(int n = 0);

   int Size() const;

   double& operator[](int i);
   double operator[](int i) const;

   friend istream& operator>>(istream& is, CVector& v);
   friend ostream& operator<<(ostream& os, const CVector& v);
};

#endif
