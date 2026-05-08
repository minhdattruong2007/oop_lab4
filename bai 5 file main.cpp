#include "DaThuc.h"

int main() {

   DaThuc a, b;

   cout << "Nhap da thuc A:\n";
   cin >> a;

   cout << "\nNhap da thuc B:\n";
   cin >> b;

   cout << "\nDa thuc A: " << a << endl;
   cout << "Da thuc B: " << b << endl;

   cout << "\nA + B = " << a + b << endl;

   cout << "A - B = " << a - b << endl;

   cout << "A * B = " << a * b << endl;

   double x;

   cout << "\nNhap x: ";
   cin >> x;

   cout << "A(" << x << ") = "
        << a.GiaTri(x) << endl;

   return 0;
}
 

