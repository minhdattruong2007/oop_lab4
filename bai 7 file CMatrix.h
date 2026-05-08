#ifndef CMATRIX_H
#define CMATRIX_H

#include <iostream>
#include <vector>
#include "CVector.h"

using namespace std;

class CMatrix {
private:
   vector<vector<double>> a;

   int dong;
   int cot;

public:
   CMatrix(int m = 0, int n = 0);

   // nhập xuất
   friend istream& operator>>(istream& is, CMatrix& mt);
   friend ostream& operator<<(ostream& os, const CMatrix& mt);

   // cộng trừ
   CMatrix operator+(const CMatrix& b) const;
   CMatrix operator-(const CMatrix& b) const;

   // nhân ma trận
   CMatrix operator*(const CMatrix& b) const;

   // nhân vector
   CVector operator*(const CVector& v) const;
};

#endif

