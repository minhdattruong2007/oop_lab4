#ifndef DATHUC_H
#define DATHUC_H

#include <iostream>
#include <vector>
using namespace std;

class DaThuc {
private:
   vector<double> hs; // hệ số

   void RutGon();

public:
   DaThuc();

   // nhập xuất
   friend istream& operator>>(istream& is, DaThuc& dt);
   friend ostream& operator<<(ostream& os, const DaThuc& dt);

   // toán tử
   DaThuc operator+(const DaThuc& b) const;
   DaThuc operator-(const DaThuc& b) const;
   DaThuc operator*(const DaThuc& b) const;

   // tính giá trị
   double GiaTri(double x) const;
};

#endif

