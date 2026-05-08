#include "CMatrix.h"

int main() {

   CMatrix A, B;

   cout << "Nhap ma tran A:\n";
   cin >> A;

   cout << "\nNhap ma tran B:\n";
   cin >> B;

   try {

       cout << "\nA + B:\n";
       cout << A + B << endl;

       cout << "A - B:\n";
       cout << A - B << endl;

       cout << "A * B:\n";
       cout << A * B << endl;
   }
   catch(exception& e) {

       cout << e.what() << endl;
   }

   CVector v;

   cout << "\nNhap vector v:\n";
   cin >> v;

   try {

       cout << "\nA * v = ";

       cout << A * v << endl;
   }
   catch(exception& e) {

       cout << e.what() << endl;
   }

   return 0;
}

