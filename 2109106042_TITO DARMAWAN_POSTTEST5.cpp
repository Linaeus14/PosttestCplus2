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
void inputanSort(int &input);
void edit(Data daftarPenghuni[]);
void hapus(Data daftarPenghuni[], int jumlahPenghuni);
void tukarData(Data *data1, Data *data2);
void insertionSortNama(Data daftarPenghuni[], int jumlahPenghuni, int urutan);
void bubbleSortUmur(Data daftarPenghuni[], int jumlahPenghuni, int urutan);
void selectionSortLantai(Data daftarPenghuni[], int jumlahpenghuni, int urutan);
void shellSortNo(Data daftarPenghuni[], int jumlahPenghuni, int urutan);
bool exit();

int main(){
    //Deklrasi variabel local main
    int input, jumlahPenghuni = 0;
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
            <<"Masukan pilihan : ";cin>>input;
            
        //Error handling jika input bukan 1-5
        if(input == 1 or input == 2 or input == 3 or input == 4 or input == 5){
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
                    //Input penggunaan
                    cout<<"\n Tampilkan Dengan Urutan Berdasarkan: \n"
                        <<" 1. Nama\n"
                        <<" 2. Umur\n"
                        <<" 3. Lantai\n"
                        <<" 4. Nomor kamar\n"
                        <<"Masukan pilihan : ";cin>>input;

                    //Percabangan pilihan pengurutan saat pengguna ingin menampilkan data
                    if(input == 1){
                        inputanSort(input);
                        if(input == 1){
                            insertionSortNama(daftarPenghuni, jumlahPenghuni, 1);
                            tampilkanArray(daftarPenghuni, jumlahPenghuni);
                        }
                        else if(input == 2){
                            insertionSortNama(daftarPenghuni, jumlahPenghuni, 2);
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
                            tampilkanArray(daftarPenghuni, jumlahPenghuni);
                        }
                        else if(input == 2){
                            bubbleSortUmur(daftarPenghuni, jumlahPenghuni, 2);
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
                            tampilkanArray(daftarPenghuni, jumlahPenghuni);
                        }
                        else if(input == 2){
                            selectionSortLantai(daftarPenghuni, jumlahPenghuni, 2);
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
                            tampilkanArray(daftarPenghuni, jumlahPenghuni);
                        }
                        else if(input == 2){
                            shellSortNo(daftarPenghuni, jumlahPenghuni, 2);
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
                    loop = exit();
                    break;
            }
        }
        else{
            cout<<"\n  Mohon masukan angka antara 1-5.";
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
void inputan(int &input){
    cout<<"\n Nomor Urut : ";cin>>input;
}

//Prosedur input pilihan sort ascending atau descending
void inputanSort(int &input){
    cout<<"\n Tampilkan Dengan Urutan : \n"
        <<" 1. Ascending (Menaik)\n"
        <<" 2. Decending (Menurun)\n"
        <<"Masukan pilihan : ";cin>>input;
}

//Prosedur mengubah data penghuni secara menyeluruh
void edit(Data daftarPenghuni[]){
    int input2;
    inputan(input2);
    tambahDaftar(daftarPenghuni, input2-1);
}

//Prosedur menghapus data dalam array
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

//prosedur penukaran isi data
void tukarData(Data *data1, Data *data2){ 
    Data pemegangSementara = *data1; 
    *data1 = *data2; 
    *data2 = pemegangSementara; 
}

//Prosedur sort insertion untuk attribut nama
void insertionSortNama(Data daftarPenghuni[], int jumlahPenghuni, int urutan){
    int i, j;
    string kunci;
    switch(urutan){
        case 1:
            for(i = 1; i < jumlahPenghuni; i++){
                kunci = daftarPenghuni[i].orang.nama;
                j = i - 1;

                while(j >= 0 && daftarPenghuni[j].orang.nama > kunci){
                    daftarPenghuni[j + 1] = daftarPenghuni[j];
                    j = j - 1;
                }

                daftarPenghuni[j + 1].orang.nama = kunci;
            }
            break;
        case 2:
            for(i = 1; i < jumlahPenghuni; i++){
                kunci = daftarPenghuni[i].orang.nama;
                j = i - 1;

                while(j >= 0 && daftarPenghuni[j].orang.nama < kunci){
                    daftarPenghuni[j + 1] = daftarPenghuni[j];
                    j = j - 1;
                }

                daftarPenghuni[j + 1].orang.nama = kunci;
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

//Fungsi mengembalikan bool perulangan program
bool exit(){
    return false;
}