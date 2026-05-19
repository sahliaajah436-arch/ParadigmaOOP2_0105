#include <iostream>
using namespace std;

// Abstract Base Class
class RekeningBank {
protected:
    double saldo;

public:
    RekeningBank(double s) {
        saldo = s;
    }

    virtual void potongAdmin() = 0; // pure virtual function

    virtual void tampilSaldo() {
        cout << "Saldo saat ini: Rp " << saldo << endl;
    }

    virtual ~RekeningBank() {}
};

// Rekening Syariah
class RekeningSyariah : public RekeningBank {
public:
    RekeningSyariah(double s) : RekeningBank(s) {}

    void potongAdmin() override {
        cout << "Rekening Syariah bebas biaya admin." << endl;
    }
};

// Rekening Konvensional
class RekeningKonvensional : public RekeningBank {
public:
    RekeningKonvensional(double s) : RekeningBank(s) {}

    void potongAdmin() override {
        saldo -= 15000;
        cout << "Biaya admin Rp 15.000 berhasil dipotong." << endl;
    }
};

// Rekening Premium
class RekeningPremium : public RekeningBank {
public:
    RekeningPremium(double s) : RekeningBank(s) {}

    void potongAdmin() override {
        if (saldo > 10000000) {
            cout << "Saldo di atas Rp 10.000.000, bebas biaya admin." << endl;
        } else {
            saldo -= 50000;
            cout << "Biaya admin Rp 50.000 berhasil dipotong." << endl;
        }
    }
};

int main() {

    // Pointer base class
    RekeningBank* rekening1 = new RekeningSyariah(5000000);
    RekeningBank* rekening2 = new RekeningKonvensional(3000000);
    RekeningBank* rekening3 = new RekeningPremium(8000000);
    RekeningBank* rekening4 = new RekeningPremium(15000000);

    cout << "=== Rekening Syariah ===" << endl;
    rekening1->potongAdmin();
    rekening1->tampilSaldo();

    cout << "\n=== Rekening Konvensional ===" << endl;
    rekening2->potongAdmin();
    rekening2->tampilSaldo();

    cout << "\n=== Rekening Premium (Saldo 8 Juta) ===" << endl;
    rekening3->potongAdmin();
    rekening3->tampilSaldo();

    cout << "\n=== Rekening Premium (Saldo 15 Juta) ===" << endl;
    rekening4->potongAdmin();
    rekening4->tampilSaldo();

    // Hapus memori
    delete rekening1;
    delete rekening2;
    delete rekening3;
    delete rekening4;

    return 0;
}