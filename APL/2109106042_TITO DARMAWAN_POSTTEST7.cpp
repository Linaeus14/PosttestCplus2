/*
Nama : Tito Darmawan
NIM  : 2109106042
Kelas: A2
*/

#include<iostream>
#include<fstream>
#include<sstream>
#include<cctype>
#include<limits>

using namespace std;

//Deklarasi Variabel Global

//file ekternal
fstream penyimpananData;

//Structur identitas
struct Identitas{
    string nama;
    string gender;
    int umur;
    string pekerjaan;
};

//Structur keterangan
struct Data{
    Identitas orang;
    int lantai;
    int nomorKamar;
};

//Array daata daftar penghuni
Data daftarPenghuni[30]; 

//variabel jumlah penghuni
int jumlahPenghuni = 0;

//path penyimpanan eksternal
const string path1 = "data1.csv", path2 = "data2.csv";

//Penggunaan prototype prosedur
void tampilkanArray(Data daftarPenghuni[], int jumlahPenguni);
void tambahDaftar(Data daftarPenghuni[], int jumlahPenghuni);
void inputan(int &input);
void inputanSort(int &input);
void edit(Data daftarPenghuni[], int jumlahPenghuni);
void hapus(Data daftarPenghuni[], int jumlahPenghuni);
void tukarData(Data *data1, Data *data2);
void bubbleSortNama(Data daftarPenghuni[], int jumlahPenghuni, int urutan);
void bubbleSortUmur(Data daftarPenghuni[], int jumlahPenghuni, int urutan);
void selectionSortLantai(Data daftarPenghuni[], int jumlahpenghuni, int urutan);
void shellSortNo(Data daftarPenghuni[], int jumlahPenghuni, int urutan);
string lowercase(string kata);
bool stringCheck(string a, string b);
void binarySearchNama(Data daftarPenghuni[], int jumlahPenghuni);
void binarySearchNomor(Data daftarPenghuni[], int jumlahPenghuni);
bool exit();

//prosedur overload
void errorInputNotString(int &input);
void errorInputNotString(string menu, int &input);

//prosedur untuk data eksternal
void dataCheck(string path);
void memuatPenyimpanan(int &jumlahPenghuni);
void memuatPenyimpanan(Data daftarPenghuni[]);
void menyimmpanData(Data daftarPenghuni[], int jumlahPenghuni);
void menyimmpanData(int jumlahPenghuni);

//Program Utama
int main(){
    //Deklrasi variabel local main
    int input;
    bool loop = true;
    string menuUtama = "\n == Daftar Penghuni Apartemen ==\n 1. Tambah Penghuni\n 2. Ubah Data Penghuni\n 3. Hapus Data penghuni\n 4. Tampilkan Daftar Penghuni\n 5. Cari penghuni\n 6. Exit program\n Masukan pilihan : ",
        menuTampil = "\n Tampilkan Dengan Urutan Berdasarkan: \n 1. Nama\n 2. Umur\n 3. Lantai\n 4. Nomor kamar\nMasukan pilihan : ",
        menuCari = "\nMohon masukan angka 1 atau 2!\n Cari Dengan Berdasarkan: \n 1. Nama\n 2. Nomor kamar\nMasukan pilihan : ";

    //memuat data eksternal
    dataCheck(path1);
    dataCheck(path2);
    memuatPenyimpanan(jumlahPenghuni);
    memuatPenyimpanan(daftarPenghuni);

    //Perulangan program
    while(loop == true){
        //Input penggunaan menu utama
        cout<<menuUtama;
        cin>>input;
        errorInputNotString(menuUtama, input);
        
        //Error handling jika input bukan 1-5
        if(input >= 1 && input <= 6){
            //Percabangan kondisi switch untuk menentukan penggunaan program
            switch(input){
                case 1:
                    tambahDaftar(daftarPenghuni, jumlahPenghuni);
                    jumlahPenghuni++;
                    cout<<" Data telah di tambah! \n";
                    menyimmpanData(jumlahPenghuni);
                    menyimmpanData(daftarPenghuni, jumlahPenghuni);
                    break;

                case 2:
                    tampilkanArray(daftarPenghuni, jumlahPenghuni);
                    if(jumlahPenghuni == 0){
                        break;
                    }

                    edit(daftarPenghuni, jumlahPenghuni);
                    cout<<"\n Data telah di ubah";
                    menyimmpanData(jumlahPenghuni);
                    menyimmpanData(daftarPenghuni, jumlahPenghuni);
                    break;

                case 3:
                    tampilkanArray(daftarPenghuni, jumlahPenghuni);
                    if(jumlahPenghuni == 0){
                        break;
                    }
                    hapus(daftarPenghuni, jumlahPenghuni);
                    jumlahPenghuni--;
                    menyimmpanData(jumlahPenghuni);
                    menyimmpanData(daftarPenghuni, jumlahPenghuni);
                    break;
                    
                case 4:
                    //Input penggunaan
                    cout<<menuTampil;
                    cin>>input;
                    errorInputNotString(menuTampil, input);
                    //Percabangan pilihan pengurutan saat pengguna ingin menampilkan data
                    if(input == 1){
                        inputanSort(input);
                        if(input == 1){
                            bubbleSortNama(daftarPenghuni, jumlahPenghuni, 1);
                            menyimmpanData(jumlahPenghuni);
                            menyimmpanData(daftarPenghuni, jumlahPenghuni);
                            tampilkanArray(daftarPenghuni, jumlahPenghuni);
                        }
                        else if(input == 2){
                            bubbleSortNama(daftarPenghuni, jumlahPenghuni, 2);
                            menyimmpanData(jumlahPenghuni);
                            menyimmpanData(daftarPenghuni, jumlahPenghuni);
                            tampilkanArray(daftarPenghuni, jumlahPenghuni);
                        }
                        else{
                            cout<<"\n Mohon ulangi dan masukan inputan angka secara benar.";
                        }
                    }
                    else if(input == 2){
                        inputanSort(input);
                        if(input == 1){
                            bubbleSortUmur(daftarPenghuni, jumlahPenghuni, 1);
                            menyimmpanData(jumlahPenghuni);
                            menyimmpanData(daftarPenghuni, jumlahPenghuni);
                            tampilkanArray(daftarPenghuni, jumlahPenghuni);
                        }
                        else if(input == 2){
                            bubbleSortUmur(daftarPenghuni, jumlahPenghuni, 2);
                            menyimmpanData(jumlahPenghuni);
                            menyimmpanData(daftarPenghuni, jumlahPenghuni);
                            tampilkanArray(daftarPenghuni, jumlahPenghuni);
                        }
                        else{
                            cout<<"\n Mohon ulangi dan masukan inputan angka secara benar.";
                        }
                    }
                    else if(input == 3){
                        inputanSort(input);
                        if(input == 1){
                            selectionSortLantai(daftarPenghuni, jumlahPenghuni, 1);
                            menyimmpanData(jumlahPenghuni);
                            menyimmpanData(daftarPenghuni, jumlahPenghuni);
                            tampilkanArray(daftarPenghuni, jumlahPenghuni);
                        }
                        else if(input == 2){
                            selectionSortLantai(daftarPenghuni, jumlahPenghuni, 2);
                            menyimmpanData(jumlahPenghuni);
                            menyimmpanData(daftarPenghuni, jumlahPenghuni);
                            tampilkanArray(daftarPenghuni, jumlahPenghuni);
                        }
                        else{
                            cout<<"\n Mohon ulangi dan masukan inputan angka secara benar.";
                        }
                    }
                    else if(input == 4){
                        inputanSort(input);
                        if(input == 1){
                            shellSortNo(daftarPenghuni, jumlahPenghuni, 1);
                            menyimmpanData(jumlahPenghuni);
                            menyimmpanData(daftarPenghuni, jumlahPenghuni);
                            tampilkanArray(daftarPenghuni, jumlahPenghuni);
                        }
                        else if(input == 2){
                            shellSortNo(daftarPenghuni, jumlahPenghuni, 2);
                            menyimmpanData(jumlahPenghuni);
                            menyimmpanData(daftarPenghuni, jumlahPenghuni);
                            tampilkanArray(daftarPenghuni, jumlahPenghuni);
                        }
                        else{
                            cout<<"\n Mohon ulangi dan masukan inputan angka secara benar.";
                        }
                    }
                    else{
                        cout<<"\n Mohon ulangi dan masukan inputan angka secara benar.";
                    }
                    break;

                case 5:
                    cout<<menuCari;
                    cin>>input;
                    errorInputNotString(menuCari, input);

                    //percabangan pemilihan cara mencari
                    if(input == 1){
                        binarySearchNama(daftarPenghuni, jumlahPenghuni);
                    }
                    else if(input == 2){
                        binarySearchNomor(daftarPenghuni, jumlahPenghuni);
                    }
                    else{
                        cout<<"\n Mohon ulangi dan masukan inputan angka secara benar.";
                    }
                    break;

                case 6:
                    loop = exit();
                    break;
            }
        }
        else{
            cout<<"\n  Mohon masukan angka antara 1-5.";
        }
    }
}

//Fungsi dan Prosedur

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
    errorInputNotString(daftarPenghuni[jumlahPenghuni].orang.umur);
    cout<<" Masukan pekerjaan : ";fflush(stdin);getline(cin, daftarPenghuni[jumlahPenghuni].orang.pekerjaan);
    cout<<" Masukan lantai    : ";cin>>daftarPenghuni[jumlahPenghuni].lantai;
    errorInputNotString(daftarPenghuni[jumlahPenghuni].lantai);
    cout<<" Masukan no. kamar : ";cin>>daftarPenghuni[jumlahPenghuni].nomorKamar;
    errorInputNotString(daftarPenghuni[jumlahPenghuni].nomorKamar);
}

//Prosedur input memilih nomor urut daftar penghuni
void inputan(int &input){
    cout<<"\n Nomor Urut : ";cin>>input;
    //error handling input bukan angka
    while(true){
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"\nMohon masukan angka!\n"
                "\n Nomor Urut : ";cin>>input;
        }
        else{
            break;
        }
    }
}

//Prosedur input pilihan sort ascending atau descending
void inputanSort(int &input){
    cout<<"\n Tampilkan Dengan Urutan : \n"
        <<" 1. Ascending (Menaik)\n"
        <<" 2. Decending (Menurun)\n"
        <<"Masukan pilihan : ";cin>>input;
    //error handling input bukan angka
    while(true){
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"\nMohon masukan angka!\n"
                <<"\n Tampilkan Dengan Urutan : \n"
                <<" 1. Ascending (Menaik)\n"
                <<" 2. Decending (Menurun)\n"
                <<"Masukan pilihan : ";cin>>input;
        }
        else{
            break;
        }
    }
}

//Prosedur mengubah data penghuni secara menyeluruh
void edit(Data daftarPenghuni[], int jumlahPenghuni){
    int input;
    inputan(input);
    while(true){
        if(input > jumlahPenghuni || input < 1){
            cout<<"Tidak ada data dengan nomor urut tersebut!";
            inputan(input);
        }
        else{
            break;
        }
    }
    tambahDaftar(daftarPenghuni, input-1);
}

//Prosedur menghapus data dalam array
void hapus(Data daftarPenghuni[], int jumlahPenghuni){
    int input;
    inputan(input);
    while(true){
        if(input > jumlahPenghuni || input < 1){
            cout<<"Tidak ada data dengan nomor urut tersebut!";
            inputan(input);
        }
        else{
            break;
        }
    }
    for(int x = 0;x < jumlahPenghuni;x++){
        if(x == input-1){
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

//prosedur penukaran isi data menggunakan pointer sebagai argumen
void tukarData(Data *data1, Data *data2){ 
    Data pemegangSementara = *data1; 
    *data1 = *data2; 
    *data2 = pemegangSementara; 
}

//Prosedur sort insertion untuk attribut nama
void bubbleSortNama(Data daftarPenghuni[], int jumlahPenghuni, int urutan){
    int i, j;
    bool ditukar;
    switch(urutan){
        case 1:
            for(i = 0; i < jumlahPenghuni-1; i++){
                ditukar = false;
                for (j = 0; j < jumlahPenghuni-i-1; j++){
                    if (daftarPenghuni[j].orang.nama > daftarPenghuni[j+1].orang.nama){
                        tukarData(&daftarPenghuni[j], &daftarPenghuni[j+1]);
                        ditukar = true;
                    }
                }
                if (ditukar == false)
                break;
            }
            break;
        case 2:
            for(i = 0; i < jumlahPenghuni-1; i++){
                ditukar = false;
                for (j = 0; j < jumlahPenghuni-i-1; j++){
                    if (daftarPenghuni[j].orang.nama < daftarPenghuni[j+1].orang.nama){
                        tukarData(&daftarPenghuni[j], &daftarPenghuni[j+1]);
                        ditukar = true;
                    }
                }
                if (ditukar == false)
                break;
            }
            break;
    }
}

//Prosedur buuble sort Data umur
void bubbleSortUmur(Data daftarPenhungi[], int jumlahPenghuni, int urutan){
    int i, j;
    bool ditukar;
    switch(urutan){
        case 1:
            for(i = 0; i < jumlahPenghuni-1; i++){
                ditukar = false;
                for (j = 0; j < jumlahPenghuni-i-1; j++){
                    if (daftarPenghuni[j].orang.umur > daftarPenghuni[j+1].orang.umur){
                        tukarData(&daftarPenghuni[j], &daftarPenghuni[j+1]);
                        ditukar = true;
                    }
                }
                if (ditukar == false)
                break;
            }
            break;
        case 2:
            for(i = 0; i < jumlahPenghuni-1; i++){
                ditukar = false;
                for (j = 0; j < jumlahPenghuni-i-1; j++){
                    if (daftarPenghuni[j].orang.umur < daftarPenghuni[j+1].orang.umur){
                        tukarData(&daftarPenghuni[j], &daftarPenghuni[j+1]);
                        ditukar = true;
                    }
                }
                if (ditukar == false)
                break;
            }
            break;
    }
}

//Prosedur selecton sort berdasarkan lantai penghuni
void selectionSortLantai(Data daftarPenghuni[], int jumlahpenghuni, int urutan){ 
    int i, j, indexMinimal;
    switch(urutan){
        case 1:
            for (i = 0; i < jumlahpenghuni-1; i++){ 
                indexMinimal = i; 
                for (j = i+1; j < jumlahpenghuni; j++){
                    if (daftarPenghuni[j].lantai < daftarPenghuni[indexMinimal].lantai){
                        indexMinimal = j; 
                    }
                    tukarData(&daftarPenghuni[indexMinimal], &daftarPenghuni[i]); 
                }
            }
            break;
        case 2:
            for (i = 0; i < jumlahpenghuni-1; i++){ 
                indexMinimal = i; 
                for (j = i+1; j < jumlahpenghuni; j++){
                    if (daftarPenghuni[j].lantai > daftarPenghuni[indexMinimal].lantai){
                        indexMinimal = j; 
                    }
                    tukarData(&daftarPenghuni[indexMinimal], &daftarPenghuni[i]); 
                }
            }
            break;
    }
} 

//Prosedur shell sort berdasarkan nomor kamar
void shellSortNo(Data daftarPenghuni[], int jumlahPenghuni, int urutan){
    switch(urutan){
        case 1:
            for(int jarak = jumlahPenghuni/2; jarak > 0; jarak /= 2){
                for(int i = jarak; i < jumlahPenghuni; i += 1){
                    Data sementara  = daftarPenghuni[i];
                    int j;           
                    for (j = i; j >= jarak && daftarPenghuni[j - jarak].nomorKamar > sementara.nomorKamar; j -= jarak){
                        daftarPenghuni[j] = daftarPenghuni[j - jarak];
                    }
                    daftarPenghuni[j] = sementara;
                }
            }
            break;
        case 2:
            for(int jarak = jumlahPenghuni/2; jarak > 0; jarak /= 2){
                for(int i = jarak; i < jumlahPenghuni; i += 1){
                    Data sementara  = daftarPenghuni[i];
                    int j;           
                    for (j = i; j >= jarak && daftarPenghuni[j - jarak].nomorKamar < sementara.nomorKamar; j -= jarak){
                        daftarPenghuni[j] = daftarPenghuni[j - jarak];
                    }
                    daftarPenghuni[j] = sementara;
                }
            }
            break;
    }
}

//Fungsi yang mengembalikan string ke alphabet kecil
string lowercase(string kata){
    for(int x = 0;x < kata.length();x++){
        kata[x] = tolower(kata[x]);
    }
    return kata;
}

//fumgsi pengecek kesamaan string dan substring
bool stringCheck(string yangDicari, string isiArray){
    int posisi = 0, index_str;
    bool ketemu = false;
    while(( index_str = isiArray.find(yangDicari, posisi)) != string::npos){
        ketemu = true;
        posisi = index_str + 1;
    }
    if(ketemu){
        return true;
    }
    else{
        return false;
    }
}

//Prosedur seacrhing binary nama penghuni
void binarySearchNama(Data daftarPenghuni[], int jumlahPenghuni){
    bubbleSortNama(daftarPenghuni, jumlahPenghuni, 1);
    Data hasilCari[jumlahPenghuni];
    int indexAkhir = jumlahPenghuni, indexAwal = 0, index = 0;
    bool ketemu, hasilada;
    string yangDicari;
    cout<<"\n Nama yang ingin di cari : ";fflush(stdin);getline(cin, yangDicari);
    yangDicari = lowercase(yangDicari);
    while(indexAwal <= indexAkhir){
        int tengah = indexAwal + (indexAkhir - indexAwal) / 2;
        string isiArray;
        isiArray = daftarPenghuni[tengah].orang.nama;
        isiArray = lowercase(isiArray);
        if(stringCheck(yangDicari, isiArray) == true){
            ketemu = true;
            int sementara = tengah;
            
            //perulangan untuk kemungkinan ada lebih dari satu ke belakang
            while(stringCheck(yangDicari, isiArray)){
                hasilCari[index] = daftarPenghuni[tengah];
                index++;
                tengah -= 1;
                isiArray = daftarPenghuni[tengah].orang.nama;
                isiArray = lowercase(isiArray);
            }

            //perulangan untuk kemungkinan ada lebih dari satu ke depan
            while(stringCheck(yangDicari, isiArray)){
                hasilCari[index] = daftarPenghuni[tengah];
                index++;
                tengah += 1;
                isiArray = daftarPenghuni[tengah].orang.nama;
                isiArray = lowercase(isiArray);
            }
            break;            
        }
        else if(yangDicari[0] > isiArray[0]){
            indexAwal = tengah + 1;
        }
        else{
            indexAkhir = tengah - 1;
        }
    }
    if(ketemu){
        tampilkanArray(hasilCari, index);
    }
    else{
        cout<<"\n Data tidak di temukan!\n";
    }
}

void binarySearchNomor(Data daftarPenghuni[], int jumlahPenghuni){
    shellSortNo(daftarPenghuni, jumlahPenghuni, 1);
    Data hasilCari[jumlahPenghuni];
    int indexAkhir = jumlahPenghuni, indexAwal = 0, index = 0;
    bool ketemu = false;
    int yangDicari;
    cout<<"\n Nomor yang ingin di cari : ";cin>> yangDicari;
    while(indexAwal <= indexAkhir){
        int tengah = indexAwal + (indexAkhir - indexAwal) / 2;
        if(daftarPenghuni[tengah].nomorKamar == yangDicari){
            ketemu = true;
            int sementara = tengah;

            //perulangan untuk kemungkinan ada lebih dari satu ke belakang
            while(daftarPenghuni[tengah].nomorKamar == yangDicari){
                hasilCari[index] = daftarPenghuni[tengah];
                index++;
                tengah -= 1;
            }
            tengah = sementara+1;

            //perulangan untuk kemungkinan ada lebih dari satu ke depan
            while(daftarPenghuni[tengah].nomorKamar == yangDicari){
                hasilCari[index] = daftarPenghuni[tengah];
                index++;
                tengah += 1;
            }
            break;
        }
        else if(daftarPenghuni[tengah].nomorKamar < yangDicari){
            indexAwal = tengah + 1;
        }
        else{
            indexAkhir = tengah - 1;
        }
    
    }
    if(ketemu){
        tampilkanArray(hasilCari, index);
    }
    else{
        cout<<"\n Data tidak di temukan!\n";
    }
}

//Fungsi mengembalikan bool perulangan program
bool exit(){
    return false;
}

//prosedur error handling
void errorInputNotString(int &input){
    while(true){
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Mohon masukan angka untuk input di atas!\n input :  ";cin>>input;
        }
        else{
            break;
        }
    }
}

//prosedur error handling
void errorInputNotString(string menu, int &input){
    while(true){
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"\n Mohon Masukan Pilihan Angka Dengan Benar!"<<endl<<menu;cin>>input;
        }
        else{
            break;
        }
    }
}

//Prosedur mengecek apakah data ada, jika tidak akan di buat baru
void dataCheck(string path){
    penyimpananData.open(path, ios::app);
    if( !penyimpananData.is_open() ){
        penyimpananData.open(path, ios::trunc);
        penyimpananData.close();
    }
    else{
        penyimpananData.close();
    }
}

//Prosedur membaca dan mengambil data dari file eksternal
void memuatPenyimpanan(int &jumlahPenghuni){
    penyimpananData.open(path2, ios::in);
    string jumlah;
    getline(penyimpananData, jumlah, '\n');
    stringstream jumlahString(jumlah);
    jumlahString >> jumlahPenghuni;
    penyimpananData.close();
}

//Prosedur membaca dan mengambil data dari file eksternal
void memuatPenyimpanan(Data daftarPenghuni[]){
    penyimpananData.open(path1, ios::in);

    int x = 0;
    string umur, lantai, noKamar;

    while(!penyimpananData.eof() ){
        getline(penyimpananData, daftarPenghuni[x].orang.nama, ',');
        getline(penyimpananData, daftarPenghuni[x].orang.gender, ',');

        //Ubah string ke tipe data lain
        getline(penyimpananData, umur, ',');
        stringstream umurString(umur);
        umurString >> daftarPenghuni[x].orang.umur;

        getline(penyimpananData, daftarPenghuni[x].orang.pekerjaan, ',');

        getline(penyimpananData, lantai, ',');
        stringstream lantaiString(lantai);
        lantaiString >> daftarPenghuni[x].lantai;

        getline(penyimpananData, noKamar, '\n');
        stringstream noKamarString(noKamar);
        noKamarString >> daftarPenghuni[x].nomorKamar;

        if (penyimpananData.eof()){
            break;
        }
        x++;
    }
    penyimpananData.close();
}

//prosedur menyimpan data ke eksternal file
void menyimmpanData(Data daftarPenghuni[], int jumlahPenghuni){
    penyimpananData.open("data1.csv", ios::out);
    for(int x = 0;x < jumlahPenghuni; x++){
        penyimpananData << daftarPenghuni[x].orang.nama 
                        << "," << daftarPenghuni[x].orang.gender 
                        << "," << daftarPenghuni[x].orang.umur 
                        << "," << daftarPenghuni[x].orang.pekerjaan
                        << "," << daftarPenghuni[x].lantai
                        << "," << daftarPenghuni[x].nomorKamar << endl;
    }
    penyimpananData.close();
}

//prosedur menyimpan data ke eksternal file
void menyimmpanData(int jumlahPenghuni){
    penyimpananData.open("data2.csv", ios::out);
    penyimpananData << jumlahPenghuni << endl;
    penyimpananData.close();
}