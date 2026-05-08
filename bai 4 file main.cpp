#include "CDate.h"
#include <iomanip>

int main() {

   CDate ngayGui, ngayRut;

   cout << "Ngay gui tien:\n";
   cin >> ngayGui;

   cout << "\nNgay rut tien:\n";
   cin >> ngayRut;

   double tienGoc;
   double laiSuat;

   cout << "\nNhap so tien gui: ";
   cin >> tienGoc;

   cout << "Nhap lai suat (%/nam): ";
   cin >> laiSuat;

   // số ngày gửi
   long long songay = ngayRut - ngayGui;

   // tính lãi đơn
   double tienLai =
       tienGoc * (laiSuat / 100.0) * songay / 365.0;

   double tongTien = tienGoc + tienLai;

   cout << fixed << setprecision(2);

   cout << "\nSo ngay gui: " << songay << " ngay\n";

   cout << "Tien lai: " << tienLai << endl;

   cout << "Tong nhan duoc: " << tongTien << endl;

   return 0;
}
