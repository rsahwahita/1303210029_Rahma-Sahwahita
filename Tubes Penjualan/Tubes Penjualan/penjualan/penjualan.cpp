#include "penjualan.h"

// Fungsi dan Prosedur untuk buat list toko dan juga list barang, serta elemennya
void createListToko(listToko &L){ //List toko = Single Linked List
    first(L) = nil; // First(L) di assign nil, karena list toko masih kosong
}
void createListBarang(listBarang &L) { //List barang = Double Linked List
    first(L) = nil; // First(L) di assign nil, karena list barang masih kosong
    last(L) = nil; // Last(L) di assign nil, karena list barang masih kosong
}
adrToko TokoBaru(infotypeToko x){
    adrToko P = new elemenToko; // Buat elemen baru
    info(P) = x; // Isi info dari elemen baru dengan x
    next(P) = nil; // Next dari elemen baru di assign nil, karena elemen baru masih belum memiliki next
    child(P) = nil; // Child dari elemen baru di assign nil, karena elemen baru masih belum memiliki child
    return P; // Return elemen baru
}
adrBarang BarangBaru(infotypeBarang x){
    adrBarang P = new elemenBarang; // Buat elemen baru
    info(P) = x; // Isi info dari elemen baru dengan x
    next(P) = nil; // Next dari elemen baru di assign nil, karena elemen baru masih belum memiliki next
    prev(P) = nil; // Prev dari elemen baru di assign nil, karena elemen baru masih belum memiliki prev
    return P; // Return elemen baru
}
adrRelasi RelasiBaru(adrBarang x){
    adrRelasi P = new elemenRelasi; // Buat elemen baru
    relasi(P) = x; // Isi Relasi dari elemen baru dengan x
    next(P) = nil; // Next dari elemen baru di assign nil, karena elemen baru masih belum memiliki next
    return P; // Return elemen baru
}

/*Permintaan Soal Tugas Besar MLL A Bagian 1. Penjualan*/
// a. Menambahkan data Toko ke dalam list Toko
void insertToko(listToko &L, adrToko P){
    if(first(L) == nil){ // Jika list toko masih kosong
        first(L) = P; // First(L) di assign P, karena P adalah elemen pertama
    } else { // Jika list toko sudah ada isinya
        adrToko Q = first(L); // Buat elemen Q yang berisi First(L)
        while(next(Q) != nil){ // Selama next dari Q tidak nil
            Q = next(Q); // Q di assign next dari Q
        }
        next(Q) = P; // Next dari Q di assign P, karena P adalah elemen terakhir
    }
} //insert Last
// b. Menambahkan data Barang ke dalam list Barang
void insertBarang(listBarang &L, adrBarang P){
    if(first(L) == nil){ // Jika list barang masih kosong
        first(L) = P; // First(L) di assign P, karena P adalah elemen pertama
        last(L) = P; // Last(L) di assign P, karena P adalah elemen terakhir
    } else { // Jika list barang sudah ada isinya
        adrBarang Q = last(L); // Buat elemen Q yang berisi Last(L)
        next(Q) = P; // Next dari Q di assign P, karena P adalah elemen terakhir
        prev(P) = Q; // Prev dari P di assign Q, karena Q adalah elemen sebelum P
        last(L) = P; // Last(L) di assign P, karena P adalah elemen terakhir
    }
} //insert Last
// c. Mencari data toko tertentu
adrToko findToko(listToko L, string namatoko){
    adrToko P = first(L); // P di assign First(L) terlebih dahulu
    while(P != nil && info(P).namatoko != namatoko){ // Jika P nil, maka returnnya sudah pasti nil, dan jika info dari P tidak sama dengan namatoko, maka P di assign next dari P hingga data terakhir
        P = next(P); // P di assign next dari P
    }
    return P; // Return P
}
adrBarang findBarang(listBarang L, string namabarang){
    adrBarang P = first(L); // P di assign First(L) terlebih dahulu
    while(P != nil && info(P).namabarang != namabarang){ // Jika P nil, maka returnnya sudah pasti nil, dan jika info dari P tidak sama dengan namabarang, maka P di assign next dari P hingga data terakhir
        P = next(P); // P di assign next dari P
    }
    return P; // Return P (bisa jadi nil atau P)
}
// d. Menambahkan relasi antara toko dan barang
void insertRelasi(adrToko &T, adrRelasi P){
    if(child(T) == nil){ // Jika child dari T masih kosong
        child(T) = P; // Child dari T di assign P, karena P adalah elemen pertama
    } else { // Jika child dari T sudah ada isinya
        adrRelasi Q = child(T); // Buat elemen Q yang berisi child dari T
        while(next(Q) != nil){ // Selama next dari Q tidak nil
            Q = next(Q); // Q di assign next dari Q
        }
        next(Q) = P; // Next dari Q di assign P, karena P adalah elemen terakhir
    }
} //insert Last
// e. Mencari data barang pada toko tertentu
adrRelasi findRelasi(adrToko T, string namabarang){
    adrRelasi P = child(T); // P di assign child dari T terlebih dahulu
    while(P != nil && info(relasi(P)).namabarang != namabarang){ // Jika P nil, maka returnnya sudah pasti nil, dan jika info dari relasi dari P tidak sama dengan namabarang, maka P di assign next dari P hingga data terakhir
        P = next(P); // P di assign next dari P
    }
    return P; // Return P (bisa jadi nil atau P)
}
// f. Menghapus data toko beserta relasinya
void deleteToko(listToko &L, adrToko &P){
    if(first(L) == P){ // Jika P adalah elemen pertama
        first(L) = next(P); // First(L) di assign next dari P
        next(P) = nil; // Next dari P di assign nil
    } else { // Jika P bukan elemen pertama (bisa elemen tengah atau elemen terakhir)
        adrToko Q = first(L); // Q di assign First(L) terlebih dahulu
        while(next(Q) != P){ // Selama next dari Q tidak sama dengan P, ini adalah kondisi untuk mencari elemen sebelum P, atau bisa disebut delete after, yaitu dihapus setelah elemen Q (data ke- P)
            Q = next(Q); // Q di assign next dari Q
        }
        next(Q) = next(P); // Next dari Q di assign next dari P, karena P akan dihapus
        next(P) = nil; // Next dari P di assign nil
    }
}
/* g. Menghapus data barang pada toko tertentu
    Disini, untuk memanggil fungsi delete barang, kita perlu mencari terlebih dahulu barang yang akan dihapus, bisa dengan memanggil fungsi findRelasi untuk menampung data barangnya (adr nya)
    lalu baru dihapus dengan memanggil fungsi deleteBarang, ini dipanggil di main nanti.
*/
void deleteBarang(adrToko &T, adrRelasi &P){ // disini T adalah toko yang akan dihapus barangnya, atau jika dilihat dengan Linked List, child(T) itu adalah first(L)
    if(child(T) == P){ // Jika P adalah elemen pertama
        child(T) = next(P); // Child dari T di assign next dari P
        next(P) = nil; // Next dari P di assign nil
    } else { // Jika P bukan elemen pertama (bisa elemen tengah atau elemen terakhir)
        adrRelasi Q = child(T); // Q di assign child dari T terlebih dahulu
        while(next(Q) != P){ // Selama next dari Q tidak sama dengan P, ini adalah kondisi untuk mencari elemen sebelum P, atau bisa disebut delete after, yaitu dihapus setelah elemen Q (data ke- P)
            Q = next(Q); // Q di assign next dari Q
        }
        next(Q) = next(P); // Next dari Q di assign next dari P, karena P akan dihapus
        next(P) = nil; // Next dari P di assign nil
    }
}
// h. Menampilkan seluruh data toko beserta barang yang dijualnya
void printToko(listToko L){
    adrToko P = first(L); // P di assign first(L) terlebih dahulu
    int i = 1;
    while(P != nil){ // Selama P tidak nil (tidak terakhir)
        cout << "Toko " << i << endl;
        cout << "Nama Toko : " << info(P).namatoko << endl;
        cout << "Alamat Toko : " << info(P).alamat << endl;
        cout << "Barang yang dijual : " << endl;
        adrRelasi Q = child(P); // Q di assign child dari P
        while(Q != nil){ // Selama Q tidak nil (tidak terakhir)
            cout << "Nama Barang : " << info(relasi(Q)).namabarang << endl;
            cout << "Harga Barang : " << info(relasi(Q)).harga << endl;
            cout << "Stok Barang : " << info(relasi(Q)).jumlahstok << endl;
            Q = next(Q); // Q di assign next dari Q untuk mencari data selanjutnya
        }
        cout << endl;
        P = next(P); // P di assign next dari P untuk mencari data selanjutnya
        i++; // i di increment untuk menampilkan nomor toko
    }
}
// i. Menghitung banyak barang yang dijual pada toko tertentu
int countBarang(adrToko T){
    int count = 0; // Buat variabel count untuk menghitung banyak barang
    adrRelasi P = child(T); // P di assign child dari T
    while(P != nil){ // Selama P tidak nil (tidak terakhir)
        count++; // count di increment (ditambah 1)
        P = next(P); // P di assign next dari P untuk mencari data selanjutnya
    }
    return count; // Return count
}
// j. Menampilkan toko yang memiliki barang paling banyak dan paling sedikit
void printMaxMinBarang(listToko L){
    adrToko P = first(L); // P di assign first(L) terlebih dahulu
    adrToko max = P; // Buat variabel max untuk menampung toko yang memiliki barang paling banyak
    adrToko min = P; // Buat variabel min untuk menampung toko yang memiliki barang paling sedikit
    while(P != nil){ // Selama P tidak nil (tidak terakhir)
        if(countBarang(P) > countBarang(max)){ // Jika count dari P lebih besar dari count dari max
            max = P; // max di assign P
        }
        if(countBarang(P) < countBarang(min)){ // Jika count dari P lebih kecil dari count dari min
            min = P; // min di assign P
        }
        P = next(P); // P di assign next dari P untuk mencari data selanjutnya
    }
    cout << " Toko dengan barang paling banyak : " << info(max).namatoko << endl;
    cout << " Toko dengan barang paling sedikit : " << info(min).namatoko << endl;
}

int Menu(){
    int pilihan = 0;
    cout << endl << "================= MENU =================" << endl;
    cout << "1. Tambah data Toko" << endl;
    cout << "2. Tambah data Barang" << endl;
    cout << "3. Mencari data Toko" << endl;
    cout << "4. Menambahkan data Barang pada Toko tertentu (Tambah Relasi)" << endl;
    cout << "5. Mencari data Barang pada Toko tertentu" << endl;
    cout << "6. Menghapus data toko tertentu dan seluruh barang yang dijualnya (dan relasinya)" << endl;
    cout << "7. Menghapus data barang tertentu pada toko tertentu " << endl;
    cout << "8. Menampilkan seluruh data toko beserta barang yang dijualnya" << endl;
    cout << "9. Menghitung banyak barang yang dijual pada toko tertentu" << endl;
    cout << "10. Menampilkan toko yang memiliki barang paling banyak dan paling sedikit" << endl;
    cout << "0. Keluar" << endl;
    cout << "Pilihan : ";
    cin >> pilihan;
    cout << endl;
    if(pilihan == 0){ // Jika pilihan 0, maka program akan keluar dan menampilkan pesan
        cout << "Terima kasih telah menggunakan program ini" << endl;
    }
    return pilihan;

}
