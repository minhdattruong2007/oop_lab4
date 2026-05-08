#include "PhanSo.h"

// Constructor
PhanSo::PhanSo(int tu, int mau) {
   iTu = tu;
   iMau = mau;

   if(iMau == 0)
       iMau = 1;

   RutGon();
}

// UCLN
int PhanSo::gcd(int a, int b) {
   while(b != 0) {
       int r = a % b;
       a = b;
       b = r;
   }
   return abs(a);
}

// Rút gọn
void PhanSo::RutGon() {
   int g = gcd(iTu, iMau);

   iTu /= g;
   iMau /= g;

   // Chuẩn hóa mẫu dương
   if(iMau < 0) {
       iTu = -iTu;
       iMau = -iMau;
   }
}

// +
PhanSo PhanSo::operator+(const PhanSo& b) const {
   return PhanSo(
       iTu * b.iMau + b.iTu * iMau,
       iMau * b.iMau
   );
}

// -
PhanSo PhanSo::operator-(const PhanSo& b) const {
   return PhanSo(
       iTu * b.iMau - b.iTu * iMau,
       iMau * b.iMau
   );
}

// *
PhanSo PhanSo::operator*(const PhanSo& b) const {
   return PhanSo(
       iTu * b.iTu,
       iMau * b.iMau
   );
}

// /
PhanSo PhanSo::operator/(const PhanSo& b) const {
   return PhanSo(
       iTu * b.iMau,
       iMau * b.iTu
   );
}

// ==
bool PhanSo::operator==(const PhanSo& b) const {
   return (iTu == b.iTu && iMau == b.iMau);
}

// >
bool PhanSo::operator>(const PhanSo& b) const {
   return iTu * b.iMau > b.iTu * iMau;
}

// <
bool PhanSo::operator<(const PhanSo& b) const {
   return iTu * b.iMau < b.iTu * iMau;
}

// >>
istream& operator>>(istream& is, PhanSo& ps) {
   cout << "Nhap tu so: ";
   is >> ps.iTu;

   do {
       cout << "Nhap mau so: ";
       is >> ps.iMau;

       if(ps.iMau == 0)
           cout << "Mau so phai khac 0!\n";

   } while(ps.iMau == 0);

   ps.RutGon();

   return is;
}

// <<
ostream& operator<<(ostream& os, const PhanSo& ps) {
   os << ps.iTu << "/" << ps.iMau;
   return os;
}
