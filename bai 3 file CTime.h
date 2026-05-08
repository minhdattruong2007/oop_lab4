#ifndef CTIME_H
#define CTIME_H

#include <iostream>
using namespace std;

class CTime {
private:
   int gio;
   int phut;
   int giay;

   void ChuanHoa();

public:
   CTime(int h = 0, int m = 0, int s = 0);

   // + -
   CTime operator+(int x) const;
   CTime operator-(int x) const;

   // ++ --
   CTime& operator++();      // prefix
   CTime operator++(int);    // postfix

   CTime& operator--();
   CTime operator--(int);

   // nhập xuất
   friend istream& operator>>(istream& is, CTime& t);
   friend ostream& operator<<(ostream& os, const CTime& t);
};

#endif

