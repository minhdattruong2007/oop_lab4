#ifndef SOPHUC_H
#define SOPHUC_H

#include <iostream>
using namespace std;

class SoPhuc {
private:
   double iThuc;
   double iAo;

public:
   // Constructor duy nhất
   SoPhuc(double thuc = 0, double ao = 0);

   // Nạp chồng toán tử
   SoPhuc operator+(const SoPhuc& b) const;
   SoPhuc operator-(const SoPhuc& b) const;
   SoPhuc operator*(const SoPhuc& b) const;
   SoPhuc operator/(const SoPhuc& b) const;

   bool operator==(const SoPhuc& b) const;
   bool operator!=(const SoPhuc& b) const;

   // Friend để nhập xuất
   friend istream& operator>>(istream& is, SoPhuc& sp);
   friend ostream& operator<<(ostream& os, const SoPhuc& sp);
};

#endif

