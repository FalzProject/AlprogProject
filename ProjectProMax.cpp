#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <fstream>
#include <conio.h>
#include <ctime>
#include <vector>
#define persenan 0.1
using namespace std;

int main () {
    int n=0; 
    char nasabah,ch;
    int i,pil,x,pos,edit,a=0; 
    long int no,total,tujuan;
    double setor,tarik,transfer,donate;
    bool ketemu = false;
    string status;

    time_t t = time(0);
    tm * now = localtime(&t);
    const char * dayNames[] = {"Minggu", "Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu"};
    int dayOfWeek = now->tm_wday;

    struct {
    char nama [30];
    long int norek;
    double saldo;
    }nas[50];

menu:
    system("cls");
    cout << "==============================================" << endl;
    cout << "|       DUID SYSTEM VIP LIMITED EDITION      |" << endl;
    cout << "|============================================|" << endl;
    cout << "|============  'MENU TRANSAKSI'  ============|" << endl;
    cout << "|1.    Pendaftaran Nasabah                   |" << endl;
    cout << "|2.    Penyetoran                            |" << endl;
    cout << "|3.    Penarikan                             |" << endl;
    cout << "|4.    Transfer saldo                        |" << endl;
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
            cout << "Masukkan nama anda       : ";
            cin>> nas[n].nama;
            cout << "Masukkan saldo awal anda : ";
            cin>> nas[n].saldo;
        } 
        n=n+1;
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
        cout << "Masukkan jumlah penarikan : " ; cin >> tarik;
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

    } else if (pil==4) {       //Tambahan fitur    
        cout<< endl;
        cout << "Masukkan nomor rekening anda : ";
        cin >> no;
        for  (i=0; i<n; i++){
            if (no==(nas[i].norek)) {   
                pos=i;
                ketemu=true;
                break;
            }else
                ketemu=false;
        }
        if (ketemu) { 
            cout << "Nama Pengirim : " << nas[pos].nama << endl;
            cout << "No. Rekening  : " << nas[pos].norek << endl;
            cout << "Total saldo   : " << nas[pos].saldo << endl;
            cout << endl << "Masukkan nomor rekening tujuan : ";
            cin >> no;
            for (i=0; i<n; i++) {
                if (no==(nas[i].norek)) {
                    ketemu=true;
                    break;
                } else
                    ketemu=false;
            } if (ketemu) {
                cout << "Nama Penerima : " << nas[i].nama << endl;
                cout << "No. Rekening  : " << nas[i].norek << endl;
                cout << endl << "Jumlah Transfer : ";
                cin >> transfer;
                cout << "Donasi seikhlasnya (jika tidak bisa diisi '0') : ";
                cin >> donate;
                total=(transfer+donate);
                if (total<nas[pos].saldo) {
                    nas[pos].saldo=nas[pos].saldo-total;
                    cout << endl;
                    if (nas[pos].saldo-total) {
                        nas[i].saldo=nas[i].saldo+transfer;
                        cout << endl;
                    }
                    if (nas[pos].saldo >= total) { //Status masih salah
                        status="Berhasil";
                    } else {
                        status="Gagal (Saldo kurang)";
                    }
                } else {
                    cout << endl << "Saldo anda tidak mencukupi!" << endl << endl;
                    cout << "Masukkan sembarang angka untuk kembali ke menu utama : " ; 
                    cin >> x;
                    goto menu;
                }
                cout << "Apakah anda ingin mencetak bukti transfer? (Y/T) : "; 
                char bukti; cin >> bukti;
                switch (bukti) {
                    case 'Y':
                    case 'y':
                cout << endl;
                cout << "=========================================" << endl;
                cout << "               BUKTI TRANSFER            " << endl;
                cout << "=========================================" << endl;
                cout << "Hari      : " << dayNames[dayOfWeek] << "" << endl;
                cout << "Tanggal   : " << __DATE__ <<            "" << endl;
                cout << "Waktu     : " << __TIME__ <<            "" << endl;
                cout << "=========================================" << endl;
                cout << "No Rek. Penerima   : "<<nas[pos].norek<<"" << endl;
                cout << "Nama Pengirim      : "<<nas[pos].nama<< "" << endl;
                cout << "-----------------------------------------" << endl;
                cout << "No Rek. Penerima   : " <<nas[i].norek <<"" << endl;
                cout << "Nama Penerima      : " <<nas[i].nama << "" << endl;
                cout << "-----------------------------------------" << endl;
                cout << "Nominal            : Rp " << transfer <<"" << endl;
                cout << "Biaya Lain         : Rp " << donate <<  "" << endl;
                cout << "Total Transfer     : Rp " << total <<   "" << endl;
                cout << "Status Transaksi   : " << status <<     "" << endl;
                cout << "=========================================" << endl;
                cout << "    TERIMAKASIH ATAS KEPERCAYAAN ANDA    " << endl;
                cout << "        UNTUK BERTRANSAKSI DISINI        " << endl;
                cout << "=========================================" << endl;
                cout << endl;
                    break;
                    case 'T':
                    case 't':
                cout << endl << "Terimakasih sudah bertransaksi disini" << endl << endl;
                cout << "Masukkan sembarang angka untuk kembali ke menu utama : " ; 
                cin >> x;
                goto menu;
                    break; 
                    default:
                cout << endl << "Silahkan pilih sesuai petunjuk" << endl;
                }
            } else
            cout << "Nomor rekening tidak ditemukan" << endl << endl;
            cout << "Masukkan sembarang angka untuk kembali ke menu utama : " ; 
            cin >> x;
            goto menu;
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
        cout << endl;
        cout << "Masukkan nomor rekening anda : ";
        cin >> no;
        for (i=0; i<n; i++) {
            if (no==(nas[i].norek)) {
                pos=i;
                ketemu=true;
                break;
            } else 
                ketemu=false;
        }
        if (ketemu) {
            balik:
            cout << "1. Hapus data nasabah" << endl;
            cout << "2. Ganti password nasabah (coming soon)" << endl;
            cout << "3. Kembali ke menu awal" << endl;
            cout << "Silahkan pilih salah satu: "; cin >> edit;  
            if (edit==1) {
                cout << endl << "Data Nasabah:" << endl;
                for (i=0; i<n; i++) {
                    cout << "No. Rek : " << nas[pos].norek<<endl;
                    cout << "Nama    : " << nas[pos].nama<<endl;
                    cout << "Saldo   : " << nas[pos].saldo<<endl;
                }
                cout<<endl<<" !!PERINGATAN, SEBELUM MENGHAPUS "<<endl;
                cout<<"HARAP TARIK SALDO TERLEBIH DAHULU!!"<<endl;
                cout<<endl<<"Ketik 1 untuk konfirmasi penghapusan : "; 
                int index; cin >> index;
                if (index == 1) {
                    n=n-1;
                    nas[i].norek=no; //masih proses
                    cout << " (Data berhasil dihapus)"<<endl;
                } else {
                    cout << " (Error. Gagal menghapus data)"<<endl;
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
        } else
        cout << "Nomor rekening tidak ditemukan" << endl<< endl;
        cout << "Masukkan sembarang angka untuk kembali ke menu utama : " ;
        cin>>x;
        goto menu;

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