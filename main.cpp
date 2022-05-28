// Online C++ compiler to run C++ program online
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Base abstract class
class Pegawai {
    public:
        // Contructor overloading
        Pegawai(int n, string nm) {
            nip = n;
            nama = nm;
            gajiPokok = 1000000;
            salesQty = 0;
            sales = 0;
        }
        
        Pegawai(int n, string nm, double g) {
            nip = n;
            nama = nm;
            gajiPokok = g;
            salesQty = 0;
            sales = 0;
        }
        
        Pegawai(int n, string nm, double g, int sq, double s) {
            nip = n;
            nama = nm;
            gajiPokok = g;
            salesQty = sq;
            sales = s;
        }
    
        // virtual function
        virtual double getGaji() = 0;
        virtual string getTipe() {};
        
        void setNip(int n) {
            nip = n;
        }
        
        int getNip() {
            return nip;
        }
   
        void setNama(string n) {
            nama = n;
        }
        
        string getNama() {
            return nama;
        }
        
        void setGajiPokok(double g) {
            gajiPokok = g;
        }

        double getGajiPokok() {
            return gajiPokok;
        }
   
        void setSalesQty(int s) {
            salesQty = s;
        }

        int getSalesQty() {
            return salesQty;
        }

        void setSales(double s) {
            sales = s;
        }

        double getSales() {
            return sales;
        }
        
    protected:
        int nip;
        string nama;
        double gajiPokok;
        int salesQty;
        double sales;
};

// Derived class
class PegawaiTetapNonSales: public Pegawai {
    // Inherit constructor
    using Pegawai::Pegawai;
    public:
        double getGaji() {
            return gajiPokok;
        }
        
        string getTipe() {
            return "Pegawai Tetap Non Sales";
        }
};

// Derived class
class PegawaiHonorerSales: public Pegawai {
    // Inherit constructor
    using Pegawai::Pegawai;
    public:
        double getGaji() {
            return 0.3*sales;
        }
        
        string getTipe() {
            return "Pegawai Honorer Sales";
        }
};

// Derived class
class PegawaiTetapSales: public Pegawai {
    // Inherit constructor
    using Pegawai::Pegawai;
    public:
        double getGaji() {
            return gajiPokok + (floor(salesQty/20)*(0.1*gajiPokok));
        }
        
        string getTipe() {
            return "Pegawai Tetap Sales";
        }
};

int main() {
    PegawaiTetapNonSales p1(1, "Dhimas");
    PegawaiHonorerSales p2(2, "Anugrah", 0, 1, 1000000);
    PegawaiTetapSales p3(3, "Dwi", 1000000, 21, 500000);
    
    cout << "| NIP | Nama | Tipe | Gaji Pokok | Sales Qty | Sales | Gaji |" << endl;
    cout << "| " << p1.getNip() << " | " << p1.getNama() << " | " << p1.getTipe() << " | " << fixed << p1.getGajiPokok() << " | " << p1.getSalesQty() << " | " << fixed << p1.getSales() << " | " << fixed << p1.getGaji() << " |" << endl;

    cout << "| " << p2.getNip() << " | " << p2.getNama() << " | " << p2.getTipe() << " | " << fixed << p2.getGajiPokok() << " | " << p2.getSalesQty() << " | " << fixed << p2.getSales() << " | " << fixed << p2.getGaji() << " |" << endl;

    cout << "| " << p3.getNip() << " | " << p3.getNama() << " | " << p3.getTipe() << " | " << fixed << p3.getGajiPokok() << " | " << p3.getSalesQty() << " | " << fixed << p3.getSales() << " | " << fixed << p3.getGaji() << " |" << endl;
    
    cout << "Total gaji yang harus diberikan: " << fixed << p1.getGaji() + p2.getGaji() + p3.getGaji();

    return 0;
}