#include <iostream>
#include "Tubes.h"
using namespace std;

int main()
{
    list_kategori A;
    createListKategori(A);
    int pilihan = 0;
    pilihan = selectMainMenu(); //Menampilkan Main Menu
    while(pilihan!= 0){
        switch(pilihan){
        case 1:
            {
            insertKategori(A);
            break;
            }
        case 2:
            insertBarang(A);
            break;

        case 3:
            showKategori(A);
            break;

        case 4:
            showBarang(A);
            break;

        case 5:
            cariBarang(A);
            break;
        case 6:
            cariKategori(A);
            break;
        case 7:
            hitungBarang(A);
            break;
        case 8:
            hapusBarang(A);
            break;
        case 9:
            deleteKategori(A);
            break;
        case 10:
            ubahData(A);
            break;
        }


        pilihan = selectMainMenu();
    }
    cout << "ANDA TELAH KELUAR DARI PROGRAM" << endl;
    return 0;
}
