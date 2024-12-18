#include <iostream>
#include "Tubes.h"
using namespace std;
void createListKategori(list_kategori &L){
    //f.s first dan last dari list kategori terisi NULL
    first(L) = NULL;
    last(L) = NULL;
}
void createListBarang(list_barang &L){
    // f.s first dari list barang terisi NULL
    first(L) = NULL;
}
int selectMainMenu(){
    //f.s menampilkan menu
    cout <<"========== MENU =============" << endl;
    cout <<"1. Menambahkan Kategori    " << endl;
    cout <<"2. Menambahkan Barang   " << endl;
    cout <<"3. Menampilkan Kategori" << endl;
    cout <<"4. Menampilkan Barang" << endl;
    cout <<"5. Mencari Barang" << endl;
    cout <<"6. Mencari Kategori" << endl;
    cout <<"7. Menghitung Barang Dalam Kategori" << endl;
    cout <<"8. Menghapus Barang Dalam Kategori" << endl;\
    cout <<"9. Menghapus Kategori" << endl;
    cout <<"10.Mengubah Data" <<endl;
    cout <<"0. Exit                     " << endl;
    cout <<"============================" << endl;
    cout <<"Masukkan Menu: ";
    int input = 0;
    cin >> input;
    cout << endl;
    return input;
}
void insertKategori(list_kategori &L){
    //i.s terdapat list kategori yg mungkin kosong
    //f.s list kategori terisi kategori baru
    infotype_kategori x;
    cout << "Masukkan data kategori dengan format Nama, ID kategori: ";
    cin >> x.nama;
    cin >> x.id;
    cout << endl;

    adr_kategori P = createNewElmKategori(x);

    string posisi;
    cout << "Apakah data kategori ingin dimasukkan di depan/belakang?(D/B): ";
    cin >> posisi;
    cout << endl;
    if (posisi != "D" && posisi != "B"){
        cout << "Input tidak valid, data akan dimasukkan dibelakang" << endl;
        posisi = "B";
    }
    if (first(L) ==NULL){
        first(L) = P;
        last(L) = P;
    }else if (posisi == "D"){
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }else if(posisi == "B"){
        next(last(L)) = P;
        prev(P) = last(L);
        last(L) = P;
    }
    cout << "Data kategori telah dimasukkan." << endl;
}
void showKategori(list_kategori L){
    adr_kategori X = first(L);
    if (X == NULL){
        cout << "Kategori Kosong" << endl;
    }else{
        cout << "Data kategori yang ada dengan format ID, Nama: " << endl;
        while(X!= NULL){
            cout << info(X).id << " " << info(X).nama;
            cout << endl;
            X = next(X);
        }
    }

    cout<< endl;
}
adr_kategori createNewElmKategori(infotype_kategori x){
    adr_kategori P = new elm_kategori;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    barang(P) = NULL;
    return P;
}
adr_barang createNewElmBarang(infotype_barang x){
    adr_barang P = new elm_barang;
    info(P) = x;
    next(P) = NULL;
    return P;
}

void insertBarang(list_kategori &L){
    string kategori;
    cout<< "Masukkan nama kategori yang ingin ditambahkan barang: ";
    cin >> kategori;
    cout << endl;
    adr_kategori P = first(L);
    while(P != NULL && info(P).nama != kategori ){
        P = next(P);
    }
    if (P==NULL || info(P).nama != kategori){
        cout << "Kategori tidak ditemukan" << endl;
    }else{
    infotype_barang X;
    cout <<"Masukkan jumlah barang yang akan ditambahkan: ";
    int y;
    cin >> y;
    cout << endl;
    int i;
    cout << "Masukkan data barang dengan format Nama, Jumlah Stok, dan Harga: " << endl;
    for (i=0;i<y;i++){
    cin >> X.nama;
    cin >> X.stok;
    cin >> X.harga;
    adr_barang B = createNewElmBarang(X);
    if(barang(P)==NULL){
        barang(P) = B;
    }else{
        next(B) = barang(P);
        barang(P) = B;
    }
    }
    cout << endl;
    cout << "Data barang telah dimasukkan" << endl;
    }
}
void showBarang(list_kategori L){
   adr_kategori P = first(L);
    if (P == NULL){
        cout << "Data Kosong" << endl;
    }else{
        cout << "Data barang yang ada berdasarkan kategori dengan format Nama, Jumlah Stok, dan Harga:"<< endl;
        while(P != NULL){
            cout << "Kategori " << info(P).nama << ": " << endl;
            if (barang(P)==NULL){
                cout <<"Data barang kosong"<< endl;
            }else{
                adr_barang B = barang(P);
                while(B != NULL){
                    cout << info(B).nama << " ";
                    cout << info(B).stok << " ";
                    cout << info(B).harga << " ";
                    cout << endl;
                    B = next(B);
                }
            }
            cout << endl;
            P = next(P);
        }
    }
}

adr_barang findBarangInKategori(adr_kategori P, string namaBarang) {
    adr_barang B = barang(P);
    while (B != NULL && info(B).nama != namaBarang) {
        B = next(B);
    }
    return B;
}
void cariBarang(list_kategori L){
    cout << "Masukkan kategori dari barang yang dicari: ";
    string kategori;
    cin >> kategori;
    cout << endl;
    adr_kategori P = first(L);
    while ((P!= NULL) && (info(P).nama !=kategori)){
        P = next(P);
    }
    if (P == NULL || info(P).nama!=kategori) {
        cout << "Kategori tidak ditemukan" << endl;
    }else{
        string barang;
        cout << "Masukkan nama barang yang dicari: ";
        cin >> barang;
        cout << endl;
        adr_barang b = findBarangInKategori(P,barang);
        if ( b ==NULL || info(b).nama != barang){
            cout << "Barang tidak ditemukan" << endl;
        }else{
            cout << "Data barang dengan format, Nama, Stok, Harga: " << endl;
            cout << info(b).nama << " ";
            cout << info(b).stok << " ";
            cout << info(b).harga << " ";
            cout << endl;
        }

    }
    cout <<" " << endl;
}

void deleteBarangInKategori(adr_kategori P, string namaBarang) {
    if (P == NULL) return;
    adr_barang B = barang(P), prevB = NULL;
    while (B != NULL && info(B).nama != namaBarang) {
        prevB = B;
        B = next(B);
    }
    if (B != NULL) {
        if (prevB == NULL) {
            barang(P) = next(B);
        } else {
            next(prevB) = next(B);
        }
        delete B;
        cout << "Barang \"" << namaBarang << "\" telah dihapus.\n";
    } else {
        cout << "Barang \"" << namaBarang << "\" tidak ditemukan.\n";
    }
}
void hapusBarang(list_kategori &L){
     cout << "Masukkan nama dari kategori barang yang ingin dihapus: ";
    string kategori;
    cin >> kategori;
    cout << endl;
    adr_kategori P = first(L);
    while ((P!= NULL) && (info(P).nama !=kategori)){
        P = next(P);
    }
    if (P == NULL || info(P).nama!=kategori) {
        cout << "Kategori tidak ditemukan" << endl;
    }else{
        string barang;
        cout << "Masukkan nama barang yang ingin dihapus: ";
        cin >> barang;
        cout << endl;
        deleteBarangInKategori(P, barang);
    }
}

int countBarangInKategori(adr_kategori P) {
    int count = 0;
    adr_barang B = barang(P);
    while (B != NULL) {
        count++;
        B = next(B);
    }
    return count;
}
void hitungBarang(list_kategori L){
    cout << "Masukkan nama dari kategori yang ingin dihitung jumlah barangnya: ";
    string kategori;
    cin >> kategori;
    cout << endl;
    adr_kategori P = first(L);
    while ((P!= NULL) && (info(P).nama !=kategori)){
        P = next(P);
    }
    if (P == NULL || info(P).nama!=kategori) {
        cout << "Kategori tidak ditemukan" << endl;
    }else{
        int i;
        i = countBarangInKategori(P);
        cout << "Jumlah barang di kategori " << kategori << " adalah: " << i << endl;
    }
}


adr_kategori findKategori(list_kategori L, string namaKategori) {
    adr_kategori P = first(L);
    while (P != NULL && info(P).nama != namaKategori) {
        P = next(P);
    }
    return P;
}
void cariKategori(list_kategori L){
    cout << "Masukkan nama kategori yang dicari: ";
    string kategori;
    cin >> kategori;
    cout << endl;
    adr_kategori P = findKategori(L, kategori);
    if (P == NULL || info(P).nama!=kategori) {
        cout << "Kategori tidak ditemukan" << endl;
    }else{
        cout << "Data Kategori dengan format ID, Nama: " << endl;
        cout << info(P).id << " " << info(P).nama << endl;
    }
    cout << " " << endl;
}

void deleteKategori(list_kategori &L) {
    cout << "Masukkan nama dari kategori barang yang ingin dihapus: ";
    string kategori;
    cin >> kategori;
    cout << endl;
    adr_kategori P = findKategori(L, kategori);
    if (P == NULL) {
        cout << "Kategori \"" << kategori << "\" tidak ditemukan.\n";
        return;
    }

    // Hapus semua barang dalam kategori
    adr_barang B = barang(P);
    while (B != NULL) {
        adr_barang temp = B;
        B = next(B);
        delete temp;
    }

    // Hapus kategori dari list
    if (P == first(L)) {
        first(L) = next(P);
        if (first(L) != NULL) {
            prev(first(L)) = NULL;
        } else {
            last(L) = NULL;
        }
    } else if (P == last(L)) {
        last(L) = prev(P);
        next(last(L)) = NULL;
    } else {
        next(prev(P)) = next(P);
        prev(next(P)) = prev(P);
    }

    delete P;
    cout << "Kategori \"" << kategori << "\" dan semua barang di dalamnya telah dihapus.\n";
}

void ubahData(list_kategori &L){
    cout << "Pilih data yang mau diubah, kategori atau barang? (K/B): ";
    string pilih;
    cin >> pilih;
    cout << endl;
    if (pilih == "K"){
        ubahKategori(L);
    }else if (pilih == "B"){
        ubahBarang(L);
    }else{
        cout << "Input Tidak Valid" << endl;
    }
}

void ubahKategori(list_kategori &L){
    cout << "Nama kategori yang ingin diubah: " <<endl;
    string kategori;
    cin >> kategori;
    cout << endl;
    adr_kategori P = first(L);
    while ((P!= NULL) && (info(P).nama !=kategori)){
        P = next(P);
    }
    if (P == NULL || info(P).nama!=kategori) {
        cout << "Kategori tidak ditemukan" << endl;
    }else{
        cout << "Pilih data kategori yang ingin diubah, ID atau Nama? (I/N): ";
        string pilih;
        cin >> pilih;
        cout << endl;
        if (pilih == "I"){
            string id;
            cout << "Masukkan ID baru: ";
            cin >> id;
            info(P).id = id;
            cout << endl;
            cout << "Data telah diubah" << endl;
        }else if (pilih =="N" ){
            string nama;
            cout << "Masukkan Nama baru: ";
            cin >> nama;
            info(P).nama = nama;
            cout << endl;
            cout << "Data telah diubah" << endl;
        }else{
            cout << "Input Tidak Valid" << endl;
        }
    }
}
void ubahBarang(list_kategori &L){
    cout << "Masukkan nama kategori dari barang yang ingin diubah: " <<endl;
    string kategori;
    cin >> kategori;
    cout << endl;
    adr_kategori P = first(L);
    while ((P!= NULL) && (info(P).nama !=kategori)){
        P = next(P);
    }
    if (P == NULL || info(P).nama!=kategori) {
        cout << "Kategori tidak ditemukan" << endl;
    }else{
        cout << "Masukkan nama barang yang ingin diubah: ";
        string barang;
        cin >> barang;
        cout << endl;
        adr_barang b = barang(P);
        while ((b!=NULL) && (info(b).nama!=barang)){
            b = next(b);
        }
        if ( b ==NULL || info(b).nama != barang){
            cout << "Barang tidak ditemukan" << endl;
        }else{
            cout << "Pilih data barang yang ingin diubah, Nama, Stok atau Harga? (N/S/H): ";
            string pilih;
            cin >> pilih;
            cout << endl;
            if (pilih == "N"){
                string nama;
                cout << "Masukkan Nama baru: ";
                cin >> nama;
                info(b).nama = nama;
                cout << endl;
                cout << "Data telah diubah" << endl;
            }else if (pilih =="S" ){
                int stok;
                cout << "Masukkan Stok baru: ";
                cin >> stok;
                info(b).stok = stok;
                cout << endl;
                cout << "Data telah diubah" << endl;
            }else if(pilih =="H"){
                int harga;
                cout << "Masukkan Harga baru: ";
                cin >> harga;
                info(b).harga = harga;
                cout << endl;
                cout << "Data telah diubah" << endl;
            }else{
                cout << "Input Tidak Valid" << endl;
            }
    }
    }
}













