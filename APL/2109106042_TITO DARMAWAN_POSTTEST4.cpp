//Nama : Tito Darmawan
//NIM  : 2109106042
//Kelas: A2

#include<iostream>

using namespace std;

//Deklarasi
struct Identitas{
    string nama;
    string gender;
    int umur;
    string pekerjaan;
};
struct Data{
    Identitas orang;
    int lantai;
    int nomorKamar;
};
Data daftarPenghuni[30]; //Array daftar penghuni

//Penggunaan prototype prosedur
void tampilkanArray(Data daftarPenghuni[], int jumlahPenguni);
void tambahDaftar(Data daftarPenghuni[], int jumlahPenghuni);
void inputan(int &input);
void edit(Data daftarPenghuni[]);
void hapus(Data daftarPenghuni[], int jumlahPenghuni);
bool exit();

int main(){
    //Deklrasi variabel local main
    int input, jumlahPenghuni = 0;;
    bool loop = true;

    //Perulangan program
    while(loop == true){
        //Input penggunaan
        cout<<"\n == Daftar Penghuni Apartemen ==\n"
            <<" 1. Tambah Penghuni\n"
            <<" 2. Ubah Data Penghuni\n"
            <<" 3. Hapus Data penghuni\n"
            <<" 4. Tampilkan Daftar Penghuni\n"
            <<" 5. Exit program\n"
            <<"Masukan pilihan : ";
        cin>>input;

        //Percabangan kondisi switch untuk menentukan penggunaan program
        switch(input){
            case 1:
                tambahDaftar(daftarPenghuni, jumlahPenghuni);
                jumlahPenghuni++;
                cout<<" Data telah di tambah! \n";
                break;
            case 2:
                tampilkanArray(daftarPenghuni, jumlahPenghuni);
                if(jumlahPenghuni == 0){
                    break;
                }
                edit(daftarPenghuni);
                cout<<"\n Data telah di ubah";
                break;
            case 3:
                tampilkanArray(daftarPenghuni, jumlahPenghuni);
                if(jumlahPenghuni == 0){
                    break;
                }
                hapus(daftarPenghuni, jumlahPenghuni);
                jumlahPenghuni--;
                break;
            case 4:
                tampilkanArray(daftarPenghuni, jumlahPenghuni);
                break;
            case 5:
                loop = exit();
                break;
        }
    }
}

//Prosedur menampilkan daftar penghuni di dalam array
void tampilkanArray(Data daftarPenghuni[], int jumlahPenghuni){
    cout<<"\n _Daftar Penghuni Apartemen_ \n";

    if(jumlahPenghuni>0){
        int perulangan = 0;
        while(perulangan < jumlahPenghuni){
            cout<<perulangan+1<<". Nama      : "<<daftarPenghuni[perulangan].orang.nama<<endl
                <<"   Gender    : "<<daftarPenghuni[perulangan].orang.gender<<endl
                <<"   Umur      : "<<daftarPenghuni[perulangan].orang.umur<<endl
                <<"   Pekerjaan : "<<daftarPenghuni[perulangan].orang.pekerjaan<<endl
                <<"   lantai    : "<<daftarPenghuni[perulangan].lantai<<endl
                <<"   No. Kamar : "<<daftarPenghuni[perulangan].nomorKamar<<endl<<endl;
            perulangan++;
        }
    }
    else{
        cout<<"\n _Daftar Kosong_ \n";
    }
}

//Prosedur menambahkan data baru ke daftar array
void tambahDaftar(Data daftarPenghuni[], int jumlahPenghuni){
    cout<<"\n Masukan nama      : ";fflush(stdin);getline(cin, daftarPenghuni[jumlahPenghuni].orang.nama);
    cout<<" Masukan gender    : ";fflush(stdin);getline(cin, daftarPenghuni[jumlahPenghuni].orang.gender);
    cout<<" Masukan umur      : ";cin>>daftarPenghuni[jumlahPenghuni].orang.umur;
    cout<<" Masukan pekerjaan : ";fflush(stdin);getline(cin, daftarPenghuni[jumlahPenghuni].orang.pekerjaan);
    cout<<" Masukan lantai    : ";cin>>daftarPenghuni[jumlahPenghuni].lantai;
    cout<<" Masukan no. kamar : ";cin>>daftarPenghuni[jumlahPenghuni].nomorKamar;
}

//Prosedur input memilih nomor urut daftar penghuni
void inputan(int &input2){
    cout<<"\n Nomor Urut : ";cin>>input2;
}

//Prosedur mengubah data penghuni secara menyeluruh
void edit(Data daftarPenghuni[]){
    int input2;
    inputan(input2);
    tambahDaftar(daftarPenghuni, input2-1);
}

///Prosedur menghapus data dalam array
void hapus(Data daftarPenghuni[], int jumlahPenghuni){
    int input3;
    inputan(input3);
    for(int x = 0;x < jumlahPenghuni;x++){
        if(x == input3-1){
            for(int y = x;y<jumlahPenghuni-1;y++){
                daftarPenghuni[y] = daftarPenghuni[y+1];
            }
            x--;
            jumlahPenghuni--;
            cout<<"\n Data telah di hapus! \n";
            return;
        }
    }
}

//Prosedur menghentikan perulangan program
bool exit(){
    return false;
}