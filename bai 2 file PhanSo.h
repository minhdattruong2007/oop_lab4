#ifndef PHANSO_H
#define PHANSO_H

#include <iostream>
using namespace std;

class PhanSo {
private:
   int iTu;
   int iMau;

   int gcd(int a, int b);
   void RutGon();

public:
   // Constructor
   PhanSo(int tu = 0, int mau = 1);

   // Nạp chồng toán tử
   PhanSo operator+(const PhanSo& b) const;
   PhanSo operator-(const PhanSo& b) const;
   PhanSo operator*(const PhanSo& b) const;
   PhanSo operator/(const PhanSo& b) const;

   bool operator==(const PhanSo& b) const;
   bool operator>(const PhanSo& b) const;
   bool operator<(const PhanSo& b) const;

   // Nhập xuất
   friend istream& operator>>(istream& is, PhanSo& ps);
   friend ostream& operator<<(ostream& os, const PhanSo& ps);
};

#endif

