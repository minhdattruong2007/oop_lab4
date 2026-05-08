#include "CTime.h"

CTime::CTime(int h, int m, int s) {
   gio = h;
   phut = m;
   giay = s;

   ChuanHoa();
}

// chuẩn hóa thời gian
void CTime::ChuanHoa() {
   int tong = gio * 3600 + phut * 60 + giay;

   // quay vòng 24h
   tong = ((tong % 86400) + 86400) % 86400;

   gio = tong / 3600;
   tong %= 3600;

   phut = tong / 60;
   giay = tong % 60;
}

// +
CTime CTime::operator+(int x) const {
   CTime temp(gio, phut, giay);
   temp.giay += x;
   temp.ChuanHoa();
   return temp;
}

// -
CTime CTime::operator-(int x) const {
   CTime temp(gio, phut, giay);
   temp.giay -= x;
   temp.ChuanHoa();
   return temp;
}

// ++ prefix
CTime& CTime::operator++() {
   giay++;
   ChuanHoa();
   return *this;
}

// ++ postfix
CTime CTime::operator++(int) {
   CTime temp = *this;
   ++(*this);
   return temp;
}

// -- prefix
CTime& CTime::operator--() {
   giay--;
   ChuanHoa();
   return *this;
}

// -- postfix
CTime CTime::operator--(int) {
   CTime temp = *this;
   --(*this);
   return temp;
}

// >>
istream& operator>>(istream& is, CTime& t) {
   cout << "Nhap gio: ";
   is >> t.gio;

   cout << "Nhap phut: ";
   is >> t.phut;

   cout << "Nhap giay: ";
   is >> t.giay;

   t.ChuanHoa();

   return is;
}

// <<
ostream& operator<<(ostream& os, const CTime& t) {

   if(t.gio < 10) os << "0";
   os << t.gio << ":";

   if(t.phut < 10) os << "0";
   os << t.phut << ":";

   if(t.giay < 10) os << "0";
   os << t.giay;

   return os;
}

