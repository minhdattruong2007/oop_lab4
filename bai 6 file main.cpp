#include "CVector.h"
#include <iomanip>

int main() {

   CVector a, b;

   cout << "Nhap vector A:\n";
   cin >> a;

   cout << "\nNhap vector B:\n";
   cin >> b;

   cout << "\nVector A = " << a << endl;
   cout << "Vector B = " << b << endl;

   try {

       cout << "\nA + B = " << a + b << endl;

       cout << "A - B = " << a - b << endl;

       cout << "A . B = " << a * b << endl;

   }
   catch(exception& e) {

       cout << e.what() << endl;
   }

   cout << "\n2 * A = " << a * 2 << endl;

   cout << "Do dai A = "
        << fixed << setprecision(2)
        << a.DoDai() << endl;

   cout << "\nPhan tu A[0] = " << a[0] << endl;

   return 0;
}

