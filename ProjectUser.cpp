#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <ctime>
#include <string>
#define max_lines 5
using namespace std;

int main () {
    int n=0; 
    char nasabah,ch, bukti;
    int i,pil,x,pos,edit,a=0; 
    long int no,total,tujuan,no1,no2;
    double setor,tarik,transfer,donate;
    bool ketemu = false;
    string status;

    time_t t = time(0);
    tm * now = localtime(&t);
    const char * dayNames[] = {"Minggu", "Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu"};
    int dayOfWeek = now->tm_wday;

    struct  {
    char nama [30];
    long int norek;
    double saldo;
    }nas[50];

menu:
    system("cls");
    cout << "==============================================" << endl;
    cout << "|           MONEY SYSTEM (FOR USER)          |" << endl;
    cout << "|============================================|" << endl;
    cout << "|============  'MENU TRANSAKSI'  ============|" << endl;
    cout << "|1.    Pendaftaran Nasabah                   |" << endl;
    cout << "|2.    Penggantian kata sandi                |" << endl;
    cout << "|3.    Penarikan                             |" << endl;
    cout << "|4.    Penarikan                             |" << endl;
    cout << "|5.    Keluar                                |" << endl;
    cout << "|============================================|" << endl;
    cout << "" << endl;
    cout << "Pilihan transaksi : "; 
    cin>> pil;

    if (pil==1) {
    lagi:
            cout << endl;
            cout << "Masukkan nomor rekening  : " ;
            cin >> no;
            for (i=0;i<n;i++) {
            if (no==nas[i].norek)
            ketemu=true;
            else
            ketemu=false;
    }
    if (ketemu){           
            cout <<"Nomor rekening tersebut sudah ada, ulangi lagi" << endl;
            goto lagi;
        }else {
            cout << "masukkan nama anda       : ";
            cin>> nas[n].nama;
            cout << "Masukkan saldo awal anda : ";
            cin>>nas[n].saldo;
        }
        n=n+1;
        nas[i].norek=no;
        cout << endl << "Masukkan sembarang angka untuk kembali ke menu utama : " ; 
        cin>>x;
        goto menu;

    }else if (pil==2){
        

    }else if (pil==3){           
        cout<< endl;
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
        cout <<"Nomor rekening tidak ditemukan" << endl << endl;
        cout <<"Masukkan sembarang angka untuk kembali ke menu utama : " ; 
        cin >> x;
        goto menu;

    } else if (pil==4) { 
        cout<< endl;
        cout << "Masukkan nomor rekening anda : ";
        cin >> no1;
        for  (i=0; i<n; i++){
            if (no1==(nas[i].norek)) {   
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
            transfer:
            cout << endl << "Masukkan nomor rekening tujuan : ";
            cin >> no2;
            for (i=0; i<n; i++) {
                if (no2==(nas[i].norek)) {
                    ketemu=true;
                    break;
                } else
                    ketemu=false;
            } if (ketemu) {
                if (no2==no1) {
                    cout <<"Nomor rekening tujuan tidak boleh sama"<< endl;
                    goto transfer;
                } else {
                cout << "Nama Penerima : " << nas[i].nama << endl;
                cout << "No. Rekening  : " << nas[i].norek << endl;
                cout << endl << "Jumlah Transfer : ";
                cin >> transfer;
                cout << "Donasi seikhlasnya (jika tidak bisa diisi '0') : ";
                cin >> donate;
                total=(transfer+donate);
                }
                if (total<nas[pos].saldo) {
                    nas[pos].saldo=nas[pos].saldo-total;
                    cout << endl;
                    if (nas[pos].saldo-total) {
                        nas[i].saldo=nas[i].saldo+transfer;
                        cout << endl;
                    }
                    if (nas[pos].saldo >= total) {
                        status="Berhasil";
                    } else {
                        status="Gagal (Saldo kurang)";
                    }
                } else {
                    cout << endl << "Saldo anda tidak mencukupi" << endl << endl;
                    cout << "Masukkan sembarang angka untuk kembali ke menu utama : " ; 
                    cin >> x;
                    goto menu;
                }
                cetak:
                cout << "Apakah anda ingin mencetak bukti transfer? (Y/T) : "; 
                cin >> bukti;
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
                goto cetak;
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