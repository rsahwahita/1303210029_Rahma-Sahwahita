#ifndef PENJUALAN_H_INCLUDED
#define PENJUALAN_H_INCLUDED

#include <iostream>

using namespace std;
#define first(L) ((L).first)
#define last(L) ((L).last)
#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info
#define child(P) P->child
#define relasi(P) P->Relasi
#define nil NULL

struct infotypeToko{
    string namatoko;
    string alamat;
};
struct infotypeBarang{
    string namabarang;
    int harga;
    int jumlahstok;
};

typedef struct elemenToko *adrToko;
typedef struct elemenBarang *adrBarang;
typedef struct elemenRelasi *adrRelasi;

struct elemenToko{
    infotypeToko info;
    adrToko next;
    adrRelasi child;
};
struct elemenBarang{
    infotypeBarang info;
    adrBarang next;
    adrBarang prev;
};
struct elemenRelasi{
    adrBarang Relasi;
    adrRelasi next;
};

struct listToko{
    adrToko first;
};
struct listBarang{
    adrBarang first;
    adrBarang last;
};

// Fungsi dan Prosedur untuk buat list toko dan juga list barang, serta elemennya
void createListToko(listToko &L);
void createListBarang(listBarang &L);
adrToko TokoBaru(infotypeToko x);
adrBarang BarangBaru(infotypeBarang x);
adrRelasi RelasiBaru(adrBarang x);

// Permintaan Soal Tugas Besar
// a. Menambahkan data Toko ke dalam list Toko
void insertToko(listToko &L, adrToko P); //insert Last
// b. Menambahkan data Barang ke dalam list Barang
void insertBarang(listBarang &L, adrBarang P); //insert Last
// c. Mencari data toko tertentu
adrToko findToko(listToko L, string namatoko);
adrBarang findBarang(listBarang L, string namabarang);
// d. Menambahkan relasi antara toko dan barang
void insertRelasi(adrToko &T, adrRelasi P); //insert Last
// e. Mencari data barang pada toko tertentu
adrRelasi findRelasi(adrToko T, string namabarang);
// f. Menghapus data toko beserta relasinya
void deleteToko(listToko &L, adrToko &P);
// g. Menghapus data barang pada toko tertentu
void deleteBarang(adrToko &T, adrRelasi &P);
// h. Menampilkan seluruh data toko beserta barang yang dijualnya
void printToko(listToko L);
// i. Menghitung banyak barang yang dijual pada toko tertentu
int countBarang(adrToko T);
// j. Menampilkan toko yang memiliki barang paling banyak dan paling sedikit
void printMaxMinBarang(listToko L);

int Menu();
#endif // PENJUALAN_H_INCLUDED
