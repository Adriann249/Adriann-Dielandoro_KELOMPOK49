#include <iostream>
#include <string>

using namespace std;

string getWatermark() {
    return "================================================\n"
           "   SISTEM PEMESANAN WARUNG MAKAN - KELOMPOK 49\n"
           "================================================";
}

double hitungTotalBayar(double hargaPerPorsi, int jumlahPesan) {
    double total = hargaPerPorsi * jumlahPesan;

    if (jumlahPesan >= 3) {
        return total * 0.95;
    }
    return total;
}

class WarungMakan {
private:
    string daftarMenu[3] = {"Nasi Goreng Spesial", "Mie Goreng Jawa", "Ayam Bakar Madu"};
    double daftarHarga[3] = {25000, 20000, 30000};
    int stokPorsi[3] = {20, 15, 10};

public:
    void tampilkanMenu() {
        cout << "\n--- DAFTAR MENU WARUNG ---" << endl;
        for (int i = 0; i < 3; i++) {
            cout << i + 1 << ". " << daftarMenu[i] << " - Rp" << daftarHarga[i] << " (Sisa: " << stokPorsi[i] << " porsi)" << endl;
        }
    }

    void pesanMakanan(int indeksMenu, int jumlahPesan) {
        int indeks = indeksMenu - 1;

        if (indeks < 0 || indeks >= 3) {
            cout << "Gagal: Pilihan menu tidak valid!" << endl;
        } else if (jumlahPesan > stokPorsi[indeks]) {
            cout << "Gagal: Sisa porsi " << daftarMenu[indeks] << " tidak mencukupi. Sisa: " << stokPorsi[indeks] << endl;
        } else {
            stokPorsi[indeks] -= jumlahPesan;

            double tagihan = hitungTotalBayar(daftarHarga[indeks], jumlahPesan);

            cout << "Sukses: " << jumlahPesan << " porsi " << daftarMenu[indeks] << " sedang disiapkan." << endl;
            cout << "Total Tagihan (termasuk diskon jika ada): Rp" << tagihan << endl;
        }
    }
};

int main() {
    cout << getWatermark() << endl << endl;

    WarungMakan warung;
    int pilihan = 0;

    while (pilihan != 3) {
        cout << "\n=== MENU UTAMA ===" << endl;
        cout << "1. Tampilkan Daftar Menu" << endl;
        cout << "2. Pesan Makanan" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilihan Anda (1-3): ";
        cin >> pilihan;

        if (pilihan == 1) {
            warung.tampilkanMenu();
        } else if (pilihan == 2) {
            int menuPilihan, porsi;
            cout << "\nMasukkan nomor menu (1-3): ";
            cin >> menuPilihan;
            cout << "Masukkan jumlah porsi: ";
            cin >> porsi;

            if (porsi > 0) {
                warung.pesanMakanan(menuPilihan, porsi);
            } else {
                cout << "Input tidak valid! Pesanan minimal 1 porsi." << endl;
            }
        } else if (pilihan == 3) {
            cout << "\nTerima kasih, selamat menikmati hidangan Anda!" << endl;
        } else {
            cout << "\nPilihan tidak dikenali, silakan coba lagi!" << endl;
        }
    }

    return 0;
}
