#include "CMatrix.h"

CMatrix::CMatrix(int m, int n) {

   dong = m;
   cot = n;

   a.resize(m, vector<double>(n, 0));
}

// >>
istream& operator>>(istream& is, CMatrix& mt) {

   cout << "Nhap so dong: ";
   is >> mt.dong;

   cout << "Nhap so cot: ";
   is >> mt.cot;

   mt.a.resize(mt.dong,
       vector<double>(mt.cot));

   for(int i = 0; i < mt.dong; i++) {

       for(int j = 0; j < mt.cot; j++) {

           cout << "a[" << i << "]["
                << j << "] = ";

           is >> mt.a[i][j];
       }
   }

   return is;
}

// <<
ostream& operator<<(ostream& os,
                   const CMatrix& mt) {

   for(int i = 0; i < mt.dong; i++) {

       for(int j = 0; j < mt.cot; j++) {

           os << mt.a[i][j] << "\t";
       }

       os << endl;
   }

   return os;
}

// +
CMatrix CMatrix::operator+(
   const CMatrix& b) const {

   if(dong != b.dong ||
      cot != b.cot) {

       throw invalid_argument(
           "Khong cung kich thuoc");
   }

   CMatrix kq(dong, cot);

   for(int i = 0; i < dong; i++) {

       for(int j = 0; j < cot; j++) {

           kq.a[i][j] =
               a[i][j] + b.a[i][j];
       }
   }

   return kq;
}

// -
CMatrix CMatrix::operator-(
   const CMatrix& b) const {

   if(dong != b.dong ||
      cot != b.cot) {

       throw invalid_argument(
           "Khong cung kich thuoc");
   }

   CMatrix kq(dong, cot);

   for(int i = 0; i < dong; i++) {

       for(int j = 0; j < cot; j++) {

           kq.a[i][j] =
               a[i][j] - b.a[i][j];
       }
   }

   return kq;
}

// nhân ma trận
CMatrix CMatrix::operator*(
   const CMatrix& b) const {

   if(cot != b.dong) {

       throw invalid_argument(
           "Khong nhan duoc");
   }

   CMatrix kq(dong, b.cot);

   for(int i = 0; i < dong; i++) {

       for(int j = 0; j < b.cot; j++) {

           for(int k = 0; k < cot; k++) {

               kq.a[i][j] +=
                   a[i][k] * b.a[k][j];
           }
       }
   }

   return kq;
}

// nhân matrix * vector
CVector CMatrix::operator*(
   const CVector& v) const {

   if(cot != v.Size()) {

       throw invalid_argument(
           "Khong nhan duoc");
   }

   CVector kq(dong);

   for(int i = 0; i < dong; i++) {

       double sum = 0;

       for(int j = 0; j < cot; j++) {

           sum += a[i][j] * v[j];
       }

       kq[i] = sum;
   }

   return kq;
}

