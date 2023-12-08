#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <fstream>
#include <conio.h>
#define persenan 0.1
using namespace std;

int main () {
    int n=0, jumlahdata=0; 
    char nasabah,ch;
    int i,pil,x,pos,edit,a=0; 
    long int no,tujuan;
    double setor,tarik;
    bool ketemu = false;

    struct {
    char nama [30];
    long int norek;
    double saldo;
    string pass;
    }nas[50];

menu:
    system("cls");
    cout << "==============================================" << endl;
    cout << "|           MONEY SYSTEM (FOR ADMIN)         |" << endl;
    cout << "|============================================|" << endl;
    cout << "|============  'MENU TRANSAKSI'  ============|" << endl;
    cout << "|1.    Pendaftaran Nasabah                   |" << endl;
    cout << "|2.    Penyetoran                            |" << endl;
    cout << "|3.    Penarikan                             |" << endl;
    cout << "|5.    Cetak Daftar Nasabah                  |" << endl;
    cout << "|6.    Cari Nasabah                          |" << endl;
    cout << "|7.    Pengaturan Nasabah                    |" << endl;
    cout << "|8.    Keluar                                |" << endl;
    cout << "|============================================|" << endl;
    cout << endl;
    cout << "Pilihan menu : "; 
    cin>> pil;

    if (pil==1) {
    lagi:
            cout << endl;
            cout << "Masukkan nomor rekening  : " ;
            cin >> no; 
            for (i=0; i<n; i++) {
            if (no==nas[i].norek)
            ketemu=true;
            else
            ketemu=false;
    }
    if (ketemu) {           
            cout <<"Nomor rekening tersebut sudah ada, ulangi lagi" << endl;
            goto lagi;
        } else {
            cout << "Masukkan nama anda      : ";
            cin>> nas[n].nama;
            cout << "Masukkan saldo          : ";
            cin >> nas[n].saldo;
            cout << "Buat Password           : ";
            cin >> nas[n].pass;

            n++;
            cout << endl << "Data berhasil ditambahkan.\n";
        } 
        nas[i].norek=no;
        cout << endl << "Masukkan sembarang angka untuk kembali ke menu utama : " ; 
        cin>>x;
        goto menu;

    } else if (pil==2) {
        cout << endl;
        cout << "Masukkan nomor rekening : "; 
        cin>> no;
        for(i=0; i<n; i++) {
            if (no==(nas[i].norek)) {
            pos=i;
            ketemu=true;
            break;
        } else
            ketemu=false;
        }
        if (ketemu) {
            cout << "Masukkan jumlah setoran : ";
            cin >> setor;
            nas[pos].saldo=nas[pos].saldo+setor;
            cout << endl; 
        } else
            cout << "Nomor rekening tidak ditemukan" << endl<< endl;
            cout << "Masukkan sembarang angka untuk kembali ke menu utama : " ; 
            cin >> x;
            goto menu;

    } else if (pil==3) {           
        cout << endl;
        cout << "Masukkan nomor rekening : " ; 
        cin >> no;
        for  (i=0; i<n ; i++){
            if (no==(nas[i].norek)) {   
                pos=i;
                ketemu=true;
                break;
            }else
                ketemu=false;
        }
        if (ketemu){ 
        cout << "Masukkan jumlah penarikan : " ; 
        cin >> tarik;
        if  (tarik<(nas[pos].saldo)){
            nas[pos].saldo=nas[pos].saldo-tarik;
            cout<< endl;
        } else
            cout << "Maaf saldo anda tidak mencukupi" << endl;
    } else
        cout << "Nomor rekening tidak ditemukan" << endl << endl;
        cout << "Masukkan sembarang angka untuk kembali ke menu utama : " ; 
        cin >> x;
        goto menu;

    } else if (pil==5) {
        cout << endl << endl;
        cout << "                 Daftar Nasabah Tabungan                 " << endl;
        cout << "|====|================|================|================|" << endl;
        cout << "| NO |  NO REKENING   |     NAMA       |  TOTAL SALDO   |" << endl;
        cout << "|====|================|================|================|" << endl;
        for (i=0; i<n; i++) {
            cout << setw (4)<<i+1;
            cout << setw (17)<<nas[i].norek;
            cout << setw (14)<<nas[i].nama;
            cout << setw (14)<<((nas[i].saldo)+(nas[i].saldo*0.1))<< endl;
        }
        cout << endl << endl;
        cout << "                 Daftar Nasabah Tabungan                 " << endl;
        cout << "|====|================|================|================|" << endl;
        cout << "Jumlah total saldo diatas telah ditambah bunga 10%" << endl << endl;
        cout << "Masukkan sembarang angka untuk kembali ke menu utama : "  ;
        cin >>x;
        goto menu;

    }  else if (pil==6) {
        cout << endl << "Masukkan nomor rekening yang akan dicari : " ;
        cin >> no ;
        for (i=0; i<n ; i++) {
            if (no ==(nas[i].norek)){
                pos=i;
                ketemu=true;
                break;
            } else
                ketemu=false;
        }
        if (ketemu) {
            cout <<"Nomor rekening            : " <<nas[pos].norek<<endl;
            cout <<"Nama nasabah              : " <<nas[pos].nama<<endl;
            cout <<"Saldo                     : " <<nas[pos].saldo<<endl;
            cout <<"Total saldo setelah bunga : " <<((nas[i].saldo)+(nas[i].saldo*persenan)) << endl;
        } else
        cout << "Nomor rekening tidak ditemukan" << endl<< endl;
        cout << "Masukkan sembarang angka untuk kembali ke menu utama : " ;
        cin>>x;
        goto menu;
    
    } else if (pil==7) {
        balik:
        cout << endl;
        cout << "1. Hapus data nasabah" << endl;
        cout << "2. Ganti password nasabah (coming soon)" << endl;
        cout << "3. Kembali ke menu awal" << endl;
        cout << "Silahkan pilih salah satu: "; cin >> edit;  
        if (edit==1) {
            cout << "Data Nasabah:\n";
            for (int i=0; i<n; i++) {
                cout << i+1 << ", No. Rek: " << nas[i].norek << ". Nama: " << nas[i].nama << ", Saldo: " << nas[i].saldo << "\n";
            }

            cout << "Pilih nomor data yang akan dihapus: ";
            int nomorHapus;
            cin >> nomorHapus;

            if (nomorHapus>0 && nomorHapus<=n) {
                for (int i=nomorHapus - 1; i<n - 1; ++i) {
                    nas[i] = nas[i + 1];
                }

                n--;
                cout << "Data berhasil dihapus.\n";
                goto balik;
            } else {
                cout << "Pilihan tidak valid.\n";
                goto balik;
            }
        } else if (edit==2) {
            cout << endl << "Ganti pasword nasabah (belum tersedia)";
            cout << endl;
            goto balik;
        } else if (edit==3) {
            cout << "Apa anda yakin ingin kembali ke menu utama? (Y/T) : ";
            char menu; cin >> menu;
            switch (menu) {
                case 'y':
                case 'Y':
                goto menu;
                    break;
                case 't':
                case 'T':
                goto balik;
                    break;
            }
        } else {
            cout << endl << "Pilihan tidak valid" << endl;
            goto balik;
        }

    } else if (pil==8) {
        cout << endl;
        cout << endl << "Terimakasih telah bertransaksi disini..." << endl << endl;
        a++;

    } else {
        cout << endl;
        cout << endl << "Pilihan tidak valid..." << endl << endl;
        cout << "Masukkan sembarang angka untuk kembali ke menu utama : " ;
        cin>>x;
        goto menu;
    }
            while(a<=0);

            return 0;
}