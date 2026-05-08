#include "CDate.h"

// Constructor
CDate::CDate(int d, int m, int y) {
   ngay = d;
   thang = m;
   nam = y;
}

// kiểm tra năm nhuận
bool CDate::NamNhuan(int y) const {
   return (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0));
}

// số ngày trong tháng
int CDate::SoNgayTrongThang(int m, int y) const {

   int ngaythang[] =
   {0,31,28,31,30,31,30,31,31,30,31,30,31};

   if(m == 2 && NamNhuan(y))
       return 29;

   return ngaythang[m];
}

// đổi ngày thành tổng số ngày
long long CDate::DateToDays() const {

   long long days = 0;

   for(int y = 1; y < nam; y++) {
       days += NamNhuan(y) ? 366 : 365;
   }

   for(int m = 1; m < thang; m++) {
       days += SoNgayTrongThang(m, nam);
   }

   days += ngay;

   return days;
}

// đổi tổng ngày -> date
void CDate::DaysToDate(long long days) {

   nam = 1;

   while(true) {
       int songay = NamNhuan(nam) ? 366 : 365;

       if(days > songay) {
           days -= songay;
           nam++;
       }
       else break;
   }

   thang = 1;

   while(true) {

       int songay = SoNgayTrongThang(thang, nam);

       if(days > songay) {
           days -= songay;
           thang++;
       }
       else break;
   }

   ngay = (int)days;
}

// +
CDate CDate::operator+(int x) const {

   long long tong = DateToDays();

   CDate kq;
   kq.DaysToDate(tong + x);

   return kq;
}

// -
CDate CDate::operator-(int x) const {

   long long tong = DateToDays();

   CDate kq;
   kq.DaysToDate(tong - x);

   return kq;
}

// khoảng cách 2 ngày
long long CDate::operator-(const CDate& other) const {
   return DateToDays() - other.DateToDays();
}

// ++
CDate& CDate::operator++() {
   *this = *this + 1;
   return *this;
}

CDate CDate::operator++(int) {
   CDate temp = *this;
   ++(*this);
   return temp;
}

// --
CDate& CDate::operator--() {
   *this = *this - 1;
   return *this;
}

CDate CDate::operator--(int) {
   CDate temp = *this;
   --(*this);
   return temp;
}

// >>
istream& operator>>(istream& is, CDate& d) {

   cout << "Nhap ngay: ";
   is >> d.ngay;

   cout << "Nhap thang: ";
   is >> d.thang;

   cout << "Nhap nam: ";
   is >> d.nam;

   return is;
}

// <<
ostream& operator<<(ostream& os, const CDate& d) {

   if(d.ngay < 10) os << "0";
   os << d.ngay << "/";

   if(d.thang < 10) os << "0";
   os << d.thang << "/";

   os << d.nam;

   return os;
}
