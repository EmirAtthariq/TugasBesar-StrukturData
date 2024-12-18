#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED
#define first(P) P.first
#define last(P) P.last
#define info(P) P->info
#define prev(P) P->prev
#define next(P) P->next
#define barang(P) P->barang
using namespace std;
typedef struct elm_kategori *adr_kategori;
typedef struct elm_barang *adr_barang;
struct infotype_kategori{
    string nama;
    string id;
};
struct infotype_barang{
    string nama;
    int stok;
    int harga;
};
struct elm_kategori{
    infotype_kategori info;
    adr_kategori next;
    adr_kategori prev;
    adr_barang barang;
};
struct elm_barang{
    infotype_barang info;
    adr_barang next;
};
struct list_kategori{
    adr_kategori first;
    adr_kategori last;
};
struct list_barang{
    adr_barang first;
};
int selectMainMenu();
void createListKategori(list_kategori &L);
void createListBarang(list_barang &L);
adr_kategori createNewElmKategori(infotype_kategori x);
adr_barang createNewElmBarang(infotype_barang x);
void insertKategori(list_kategori &L);
void showKategori(list_kategori L);
void insertBarang(list_kategori &L);
void showBarang(list_kategori L);


adr_barang findBarangInKategori(adr_kategori P, string namaBarang);
void cariBarang(list_kategori L);


void hapusBarang(list_kategori &L);
void deleteBarangInKategori(adr_kategori P, string namaBarang);

void hitungBarang(list_kategori L);
int countBarangInKategori(adr_kategori P);

void cariKategori(list_kategori L);
adr_kategori findKategori(list_kategori L, string namaKategori);

void deleteKategori(list_kategori &L);

void ubahData(list_kategori &L);
void ubahKategori(list_kategori &L);
void ubahBarang(list_kategori &L);

#endif // TUBES_H_INCLUDED
