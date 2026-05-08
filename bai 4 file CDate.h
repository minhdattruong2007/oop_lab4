#ifndef CDATE_H
#define CDATE_H

#include <iostream>
using namespace std;

class CDate {
private:
   int ngay;
   int thang;
   int nam;

   bool NamNhuan(int y) const;
   int SoNgayTrongThang(int m, int y) const;

   long long DateToDays() const;
   void DaysToDate(long long days);

public:
   CDate(int d = 1, int m = 1, int y = 2000);

   // + -
   CDate operator+(int x) const;
   CDate operator-(int x) const;

   // khoảng cách 2 ngày
   long long operator-(const CDate& other) const;

   // ++ --
   CDate& operator++();
   CDate operator++(int);

   CDate& operator--();
   CDate operator--(int);

   // nhập xuất
   friend istream& operator>>(istream& is, CDate& d);
   friend ostream& operator<<(ostream& os, const CDate& d);
};

#endif

