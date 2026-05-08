#include "SoPhuc.h"

// Constructor
SoPhuc::SoPhuc(double thuc, double ao) {
   iThuc = thuc;
   iAo = ao;
}

// +
SoPhuc SoPhuc::operator+(const SoPhuc& b) const {
   return SoPhuc(
       iThuc + b.iThuc,
       iAo + b.iAo
   );
}

// -
SoPhuc SoPhuc::operator-(const SoPhuc& b) const {
   return SoPhuc(
       iThuc - b.iThuc,
       iAo - b.iAo
   );
}

// *
SoPhuc SoPhuc::operator*(const SoPhuc& b) const {
   return SoPhuc(
       iThuc * b.iThuc - iAo * b.iAo,
       iThuc * b.iAo + iAo * b.iThuc
   );
}

// /
SoPhuc SoPhuc::operator/(const SoPhuc& b) const {
   double mau = b.iThuc * b.iThuc + b.iAo * b.iAo;

   return SoPhuc(
       (iThuc * b.iThuc + iAo * b.iAo) / mau,
       (iAo * b.iThuc - iThuc * b.iAo) / mau
   );
}

// ==
bool SoPhuc::operator==(const SoPhuc& b) const {
   return (iThuc == b.iThuc && iAo == b.iAo);
}

// !=
bool SoPhuc::operator!=(const SoPhuc& b) const {
   return !(*this == b);
}

// >>
istream& operator>>(istream& is, SoPhuc& sp) {
   cout << "Nhap phan thuc: ";
   is >> sp.iThuc;

   cout << "Nhap phan ao: ";
   is >> sp.iAo;

   return is;
}

// <<
ostream& operator<<(ostream& os, const SoPhuc& sp) {
   os << sp.iThuc;

   if (sp.iAo >= 0)
       os << " + " << sp.iAo << "i";
   else
       os << " - " << -sp.iAo << "i";

   return os;
}

