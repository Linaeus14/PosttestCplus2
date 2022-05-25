// Nama : TITO DARMAWAN
// NIM  : 2109106042

#include<iostream>

using namespace std;
int n, r, nr, input1; 
long double nf, rf, nrf, hasil;
string input2;
bool loop;
// variabel 
// n = jumlah, r = banyak syarat, nr = selisih dari n dan r, 
// input1 = masukan user atas pilihan perhitungan, input2 = masukan user atas pilihan gunakan ulang atau tidak,
// nf = faktorial dari n, rf = faktorial dari r, nrf = faktorial dari selisih n dan r
// hasil = hasil dari kombinasi atau permutasi,
// loop = penentu penggunaan ulang
main(){
    loop = true;
    while(loop){ // perulangan while
        cout<<"\n  Penghitung Kombinasi dan Permutasi" // output
            <<"\n ===================================="
            <<"\n Masukan jumlah(n)        : ";
        cin>>n; // input
        cout<<" Masukan banyak syarat(r) : ";
        cin>>r;
        nr = n - r; // operasi aritmatika
        nf = 1.0; 
        rf = 1.0;
        nrf = 1.0;
        for(int x = 1;x<=n;x++){ // perulangan for
            nf *= x;
        }
        for(int x = 1;x<=r;x++){
            rf *= x;
        }
        for(int x = 1;x<=nr;x++){
            nrf *= x;
        }
        while(true){
            cout<<"\n 1. Hitung kombinasi"
                <<"\n 2. Hitung Permutasi"
                <<"\n > ";
            cin>>input1;
            if(input1==1){ // percabangan if
                hasil = nf / (rf * nrf);
                cout<<"\n Hasil kombinasi n dan r adalah : "<<hasil;
                break;
            }
            else if(input1==2){ // percabangan else if
                hasil = nf / nrf;
                cout<<"\n Hasil permutasi n dan r adalah : "<<hasil;
                break;
            }
            else{ // percabangan else
                cout<<"\n Input salah coba lagi! ";
            }
        }
        while(true){
            cout<<"\n Gunakan kembali? (y/t) : "
                <<"\n > ";
            cin>>input2;
            if(input2=="y"){
                break;
            }
            else if(input2=="t"){
                loop = false;
                break;
            }
            else{
                cout<<"\n Input salah coba lagi! ";
            }
        }
    }
}