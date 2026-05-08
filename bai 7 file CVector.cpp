#include "CVector.h"

CVector::CVector(int n) {
   data.resize(n, 0);
}

int CVector::Size() const {
   return data.size();
}

double& CVector::operator[](int i) {
   return data[i];
}

double CVector::operator[](int i) const {
   return data[i];
}

istream& operator>>(istream& is, CVector& v) {

   int n;

   cout << "Nhap so chieu: ";
   is >> n;

   v.data.resize(n);

   for(int i = 0; i < n; i++) {

       cout << "v[" << i << "] = ";
       is >> v.data[i];
   }

   return is;
}

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

