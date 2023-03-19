#include "penjualan.h"

int main(){
    // Kamus
    listToko LT;
    listBarang LB;
    infotypeToko Toko;
    infotypeBarang Barang;
    adrToko T;
    adrBarang B;
    adrRelasi R;
    string namaToko, alamatToko, namaBarang;
    int hargaBarang, jumlahStokBarang, jumlahBarang;
    // Algoritma
    createListToko(LT);
    createListBarang(LB);
    cout << "Aplikasi Penjualan" << endl;
    cout << "Disusun oleh:" << endl;
    cout << "1. Rahma Sahwahita - 1303210029" << endl;
    cout << "2. Indah Dwi Cahayu - 1303210153" << endl;
    cout << "====================================" << endl;
    int pilihanmenu = Menu(); // Pemilihan menu
    while (pilihanmenu != 0){ // Selama pilihan menu tidak 0, maka akan terus berjalan, jika 0 maka program akan berhenti
        switch(pilihanmenu){ // Menggunakan switch case untuk memilih menu, jika 1 maka akan masuk ke menu 1, dst
            case 1:
                cout << "Masukkan Nama Toko: ";
                cin >> namaToko;
                cout << "Masukkan Alamat Toko: ";
                cin >> alamatToko;
                Toko.namatoko = namaToko; // Memasukkan nama toko ke dalam struct Toko (ditampung ke structnya)
                Toko.alamat = alamatToko; // Memasukkan alamat toko ke dalam struct Toko (ditampung ke structnya)
                T = TokoBaru(Toko); // Membuat elemen baru dengan memanggil fungsi TokoBaru
                insertToko(LT, T); // Memasukkan elemen baru ke dalam list Toko
                break;
            case 2:
                cout << "Masukkan Nama Barang: ";
                cin >> namaBarang;
                cout << "Masukkan Harga Barang: ";
                cin >> hargaBarang;
                cout << "Masukkan Jumlah Stok Barang: ";
                cin >> jumlahStokBarang;
                Barang.namabarang = namaBarang; // Memasukkan nama barang ke dalam struct Barang (ditampung ke structnya)
                Barang.harga = hargaBarang; // Memasukkan harga barang ke dalam struct Barang (ditampung ke structnya)
                Barang.jumlahstok = jumlahStokBarang; // Memasukkan jumlah stok barang ke dalam struct Barang (ditampung ke structnya)
                B = BarangBaru(Barang); // Membuat elemen baru dengan memanggil fungsi BarangBaru
                insertBarang(LB, B); // Memasukkan elemen baru ke dalam list Barang
                break;
            case 3:
                cout << "Masukkan nama toko: ";
                cin >> namaToko;
                T = findToko(LT, namaToko); // Mencari toko dengan nama yang diinputkan
                if (T != nil){ // Jika toko ditemukan, maka akan menampilkan nama toko dan alamat toko
                    cout << "Toko dengan nama " << namaToko << " ditemukan" << " berlokasi di " << info(T).alamat << endl;
                } else { // Jika toko tidak ditemukan, maka akan menampilkan pesan toko tidak ditemukan
                    cout << "Toko dengan nama " << namaToko << " tidak ditemukan" << endl;
                }
                break;
            case 4:
                cout << "Masukkan nama toko: ";
                cin >> namaToko;
                T = findToko(LT, namaToko); // Mencari toko dengan nama yang diinputkan
                if (T != nil){ // Jika toko ditemukan, maka lanjut ke proses selanjutnya, yaitu mencari barang
                    cout << "Masukkan nama barang: ";
                    cin >> namaBarang;
                    B = findBarang(LB, namaBarang); // Mencari barang dengan nama yang diinputkan
                    if (B != nil){ // Jika barang ditemukan, maka akan menambahkan relasi
                        R = RelasiBaru(B); // Membuat elemen baru dengan memanggil fungsi RelasiBaru
                        insertRelasi(T, R); // Memasukkan elemen baru ke dalam list Relasi
                        cout << "Relasi berhasil ditambahkan" << endl;
                    } else { // Jika barang tidak ditemukan, maka akan menampilkan pesan barang tidak ditemukan
                        cout << "Barang dengan nama " << namaBarang << " tidak ditemukan, tidak bisa menambahkan relasi" << endl;
                    }
                }else { // Jika toko tidak ditemukan, maka akan menampilkan pesan toko tidak ditemukan
                    cout << "Toko dengan nama " << namaToko << " tidak ditemukan, tidak bisa menambahkan relasi" << endl;
                }
                break;
            case 5:
                cout << "Masukkan nama toko: ";
                cin >> namaToko;
                T = findToko(LT, namaToko); // Mencari toko dengan nama yang diinputkan
                if (T != nil){ // Jika toko ditemukan, maka lanjut ke proses selanjutnya, yaitu mencari barang
                    cout << "Masukkan nama barang yang ingin dicari: ";
                    cin >> namaBarang;
                    R = findRelasi(T, namaBarang); // Mencari barang dengan nama yang diinputkan
                    if (R != nil){ // Jika barang ditemukan, maka akan menampilkan nama barang, harga barang, dan jumlah stok barang
                        cout << "Barang dengan nama " << namaBarang << " ditemukan" << " dengan harga " << info(relasi(R)).harga << " dan jumlah stok " << info(relasi(R)).jumlahstok << endl;
                    } else{ // Jika barang tidak ditemukan, maka akan menampilkan pesan barang tidak ditemukan
                        cout << "Barang dengan nama " << namaBarang << " tidak ditemukan" << endl;
                    }
                } else { // Jika toko tidak ditemukan, maka akan menampilkan pesan toko tidak ditemukan
                    cout << "Toko dengan nama " << namaToko << " tidak ditemukan" << endl;
                }
                break;
            case 6:
                cout << "Masukkan nama toko yang ingin dihapus: ";
                cin >> namaToko;
                T = findToko(LT, namaToko); // Mencari toko dengan nama yang diinputkan
                if (T != nil){ // Jika toko ditemukan, maka akan menghapus toko
                    deleteToko(LT, T); // Menghapus toko dengan memanggil fungsi deleteToko
                    cout << "Toko dengan nama " << namaToko << " berhasil dihapus" << endl;
                } else {
                    cout << "Toko dengan nama " << namaToko << " tidak ditemukan" << endl;
                }
                break;
            case 7:
                cout << "Masukkan nama toko yang barangnya ingin dihapus: ";
                cin >> namaToko;
                T = findToko(LT, namaToko); // Mencari toko dengan nama yang diinputkan
                if (T != nil){ // Jika toko ditemukan, maka lanjut ke proses selanjutnya, yaitu mencari barang
                    cout << "Masukkan nama barang yang ingin dihapus di toko " << namaToko << ": ";
                    cin >> namaBarang;
                    R = findRelasi(T, namaBarang); // Mencari barang dengan nama yang diinputkan
                    if (R != nil){ // Jika barang ditemukan, maka akan menghapus barang
                        deleteBarang(T, R); // Menghapus barang dengan memanggil fungsi deleteBarang
                        cout << "Barang dengan nama " << namaBarang << " berhasil dihapus dari toko " << namaToko << endl;
                    } else{ // Jika barang tidak ditemukan, maka akan menampilkan pesan barang tidak ditemukan
                        cout << "Barang tidak ditemukan, tidak bisa dihapus" << endl;
                    }
                } else { // Jika toko tidak ditemukan, maka akan menampilkan pesan toko tidak ditemukan
                    cout << "Toko dengan nama " << namaToko << " tidak ditemukan" << endl;
                }
                break;
            case 8:
                printToko(LT); // Menampilkan semua toko yang ada
                break;
            case 9:
                cout << "Masukkan nama toko yang ingin dihitung barangnya: ";
                cin >> namaToko;
                T = findToko(LT, namaToko); // Mencari toko dengan nama yang diinputkan
                if (T != nil){ // Jika toko ditemukan, maka akan menghitung jumlah barang yang ada di toko tersebut
                    jumlahBarang = countBarang(T); // Menghitung jumlah barang dengan memanggil fungsi countBarang
                    cout << "Jumlah barang di toko " << namaToko << " adalah sebanyak " << jumlahBarang << endl;
                } else { // Jika toko tidak ditemukan, maka akan menampilkan pesan toko tidak ditemukan
                    cout << "Toko dengan nama " << namaToko << " tidak ditemukan" << endl;
                }
                break;
            case 10:
                printMaxMinBarang(LT);
                break;
            default: // Untuk pilihan selain 1-10, maka akan menampilkan pesan pilihan tidak ada
                cout << "Pilihan tidak ada" << endl;
                break;
        }
        pilihanmenu = Menu();
    }
    return 0;
}
