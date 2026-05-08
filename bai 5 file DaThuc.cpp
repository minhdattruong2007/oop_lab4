#include "DaThuc.h"
#include <cmath>

DaThuc::DaThuc() {
}

// xóa hệ số 0 dư
void DaThuc::RutGon() {

   while(hs.size() > 1 && hs.back() == 0) {
       hs.pop_back();
   }
}

// >>
istream& operator>>(istream& is, DaThuc& dt) {

   int bac;

   cout << "Nhap bac da thuc: ";
   is >> bac;

   dt.hs.resize(bac + 1);

   for(int i = bac; i >= 0; i--) {

       cout << "He so x^" << i << ": ";
       is >> dt.hs[i];
   }

   dt.RutGon();

   return is;
}

// <<
ostream& operator<<(ostream& os, const DaThuc& dt) {

   bool first = true;

   for(int i = dt.hs.size() - 1; i >= 0; i--) {

       double heso = dt.hs[i];

       if(heso == 0) continue;

       // dấu
       if(!first) {
           if(heso > 0) os << " + ";
           else os << " - ";
       }
       else {
           if(heso < 0) os << "-";
       }

       heso = abs(heso);

       // hệ số
       if(!(heso == 1 && i != 0))
           os << heso;

       // x
       if(i > 0) {
           os << "x";

           if(i > 1)
               os << "^" << i;
       }

       first = false;
   }

   if(first)
       os << "0";

   return os;
}

// +
DaThuc DaThuc::operator+(const DaThuc& b) const {

   DaThuc kq;

   int n = max(hs.size(), b.hs.size());

   kq.hs.resize(n, 0);

   for(int i = 0; i < n; i++) {

       if(i < hs.size())
           kq.hs[i] += hs[i];

       if(i < b.hs.size())
           kq.hs[i] += b.hs[i];
   }

   kq.RutGon();

   return kq;
}

// -
DaThuc DaThuc::operator-(const DaThuc& b) const {

   DaThuc kq;

   int n = max(hs.size(), b.hs.size());

   kq.hs.resize(n, 0);

   for(int i = 0; i < n; i++) {

       if(i < hs.size())
           kq.hs[i] += hs[i];

       if(i < b.hs.size())
           kq.hs[i] -= b.hs[i];
   }

   kq.RutGon();

   return kq;
}

// *
DaThuc DaThuc::operator*(const DaThuc& b) const {

   DaThuc kq;

   int n = hs.size();
   int m = b.hs.size();

   kq.hs.resize(n + m - 1, 0);

   for(int i = 0; i < n; i++) {
       for(int j = 0; j < m; j++) {

           kq.hs[i + j] += hs[i] * b.hs[j];
       }
   }

   kq.RutGon();

   return kq;
}

// tính giá trị
double DaThuc::GiaTri(double x) const {

   double sum = 0;

   for(int i = 0; i < hs.size(); i++) {

       sum += hs[i] * pow(x, i);
   }

   return sum;
}

