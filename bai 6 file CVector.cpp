#include "CVector.h"
#include <cmath>
#include <iomanip>

CVector::CVector(int n) {
   data.resize(n, 0);
}

// >>
istream& operator>>(istream& is, CVector& v) {

   int n;

   cout << "Nhap so chieu: ";
   is >> n;

   v.data.resize(n);

   for(int i = 0; i < n; i++) {

       cout << "x[" << i << "] = ";
       is >> v.data[i];
   }

   return is;
}

// <<
ostream& operator<<(ostream& os, const CVector& v) {

   os << "(";

   for(int i = 0; i < v.data.size(); i++) {

       os << v.data[i];

       if(i != v.data.size() - 1)
           os << ", ";
   }

   os << ")";

   return os;
}

// +
CVector CVector::operator+(const CVector& b) const {

   if(data.size() != b.data.size()) {
       throw invalid_argument("Khac so chieu");
   }

   CVector kq(data.size());

   for(int i = 0; i < data.size(); i++) {

       kq.data[i] = data[i] + b.data[i];
   }

   return kq;
}

// -
CVector CVector::operator-(const CVector& b) const {

   if(data.size() != b.data.size()) {
       throw invalid_argument("Khac so chieu");
   }

   CVector kq(data.size());

   for(int i = 0; i < data.size(); i++) {

       kq.data[i] = data[i] - b.data[i];
   }

   return kq;
}

// nhân vô hướng
double CVector::operator*(const CVector& b) const {

   if(data.size() != b.data.size()) {
       throw invalid_argument("Khac so chieu");
   }

   double sum = 0;

   for(int i = 0; i < data.size(); i++) {

       sum += data[i] * b.data[i];
   }

   return sum;
}

// vector * số
CVector CVector::operator*(double k) const {

   CVector kq(data.size());

   for(int i = 0; i < data.size(); i++) {

       kq.data[i] = data[i] * k;
   }

   return kq;
}

// độ dài
double CVector::DoDai() const {

   double sum = 0;

   for(double x : data) {

       sum += x * x;
   }

   return sqrt(sum);
}

// số chiều
int CVector::SoChieu() const {
   return data.size();
}

// []
double& CVector::operator[](int index) {
   return data[index];
}

double CVector::operator[](int index) const {
   return data[index];
}

