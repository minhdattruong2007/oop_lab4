#ifndef CVECTOR_H
#define CVECTOR_H

#include <iostream>
#include <vector>
using namespace std;

class CVector {
private:
   vector<double> data;

public:
   // constructor
   CVector(int n = 0);

   // nhập xuất
   friend istream& operator>>(istream& is, CVector& v);
   friend ostream& operator<<(ostream& os, const CVector& v);

   // toán tử
   CVector operator+(const CVector& b) const;
   CVector operator-(const CVector& b) const;

   // nhân vô hướng
   double operator*(const CVector& b) const;

   // nhân vector với số
   CVector operator*(double k) const;

   // độ dài vector
   double DoDai() const;

   // số chiều
   int SoChieu() const;

   // truy cập phần tử
   double& operator[](int index);
   double operator[](int index) const;
};

#endif

