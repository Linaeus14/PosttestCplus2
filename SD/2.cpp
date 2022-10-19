#include<iostream>
#include<fstream> 
#include<sstream> //stringstream ubah(awal)
#include<stdlib.h> //system("CLS")
#include<cstdio> //remove()
#include<utility> //swap()
#include<cctype> //to_lower()
#include<limits> //numeric_limits<streamsize>::max()
#include<windows.h> //SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord)
#include<stdio.h> //printf()
#include<conio.h> //gotoxy()
#include<string.h>

using namespace std;

//Deklarasi

//Structur identitas
struct Identitas{
    string nama;
    string gender;
    int umur;
};

//Structur tanggal
struct tanggal{
    int hari, bulan, tahun;
};

//Structur Data Keterangan
struct Data{
    Identitas orang;
    string area;
    int nomor;
    tanggal waktu;
    string status;
};

//pengunjungay daata daftar penghuni
Data pengunjung[30], riwayat[100], kosong[1];

bool loop = true, save = false;
bool noA[10] = {false, false, false, false, false, false, false, false, false, false};
bool noB[10] = {false, false, false, false, false, false, false, false, false, false};
bool noC[10] = {false, false, false, false, false, false, false, false, false, false};
int input, hari, bulan, tahun, jumlahRiwayat = 0, jumlahPengunjung = 0, jumlahAreaA = 0, jumlahAreaB = 0, jumlahAreaC = 0;
string pathData = "data.csv", pathRiwayat = "riwayat.csv";
fstream dataPengunjung;

//Prototype fungsi dan prosedur

//overload prosedur
void errorInput(int &input);
void errorInput(string tampilanMenu, int &input);

void stringToType(string awal, int &tujuan);
int partisi(Data pengunjung[], int indexAwal, int end);
void quickSortTanggal(Data riwayat[], int indexAwal, int indexAkhir, int tuas);
void bubbleSortArea(Data pengunjung[], int jumlahPengunjung);
void bubbleSortNama(Data pengunjung[], int jumlahPengunjung);
void binarySearchNama(Data riwayat[], int jumlahRiwayat);

void dataCheck(string path);
void memuatPenyimpanan(string path, int tuas);
void menyimmpanData(Data pengunjung[], int jumlahPengunjung, string path, int tuas);
string lowercase(string kata);
void inputIntLimiter(int &variabelInput,int limitKiri, int limitKanan, string teksInput, string teksError);
void startInput(int &hari = hari, int &bulan = bulan, int &tahun = tahun);
void inputan(int &input);
void menu(string menu, int &input, int tuas = 1);
void tambahDaftar(Data pengunjung[], int &jumlahPengunjung);
void tampilkanPengunjung(Data pengunjung[], int jumlah, string area = "Semua Area");
void tampilkanRiwayat(Data pengunjung[], int jumlah);
void hapus(Data pengunjung[], int jumlahPengunjung);
void hapusRiwayat();
void tampilkanTanggal();
int penentuNomor(bool no[]);
void resetNomor(bool no[], int indexHapus);
void gotoxy(int x, int y);
void loadingScreen();
void tagline(int tuas);
void exit();

main(){
    string menuUtama = "\n == Tempat Wisata X ==\n 1. Check-In\n 2. Check-Out\n 3. Tampilan Data\n 4. Data Master\n 5. Riwayat\n 6. Matikan Program\n Masukan pilihan : ",
        menuTampil = "\n == Tampilkan ==\n 1. Area A\n 2. Area B\n 3. Area C\n 4. Semua Area\n 5. Kembali\n Masukan pilihan : ",
        menuCheckOut = "\n == CheckOut Area ==\n 1. Area A\n 2. Area B\n 3. Area C\n 4. Kembali\n Masukan pilihan : ",
        menuDataMaster = "\n == Data list Tempat Wisata ==\n 1. Ubah Tanggal\n 2. Hapus Riwayat\n 3. Kembali \n Masukan pilihan : ",
        menuRiwayat = "\n == Riwayat Kujungan Tempat Wisata ==\n 1. Tampilkan Riwayat\n 2. Pencarian Riwayat\n 3. Kembali \n Masukan pilihan : ";

    dataCheck(pathData);
    dataCheck(pathRiwayat);
    memuatPenyimpanan(pathData, 1);
    memuatPenyimpanan(pathRiwayat, 2);

    loadingScreen();
    cout<<"\n ==Selamat Datang==";
    startInput();
    system("CLS");

    tagline(1);
    while(loop == true){

        //autosave
        if(save){
            menyimmpanData(pengunjung, jumlahPengunjung, pathData,1);
            menyimmpanData(riwayat, jumlahRiwayat, pathRiwayat, 2);
        }
        else{
            save = true;
        }

        //tagline(1);
        menu(menuUtama, input);
        system("CLS");

        //Error handling jika input bukan 1-3
        if(input >= 1 && input <= 6){
            //Percabangan kondisi switch untuk menentukan penggunaan program
            switch(input){
                case 1:
                    tagline(2);
                    // cout<<" =Tambah Data= \n";
                    tambahDaftar(pengunjung, jumlahPengunjung);
                    system("CLS");
                    cout<<"\n Check in berhasil!"
                        <<" \n=====================\n"
                        <<"  "<<pengunjung[jumlahPengunjung-1].orang.nama<<endl
                        <<"  Area "<<pengunjung[jumlahPengunjung-1].area<<" Nomor "<<pengunjung[jumlahPengunjung-1].nomor
                        <<" \n=====================\n";
                    break;
                case 2:
                    tagline(3);
                    if(jumlahPengunjung == 0){
                        cout<<"\n Tidak ada pengunjung yang terdata!\n";
                        save = false;
                        break;
                    }
                    menu(menuCheckOut, input);
                    system("CLS");

                    //Percabangan pilihan area untuk checkout
                    if(input == 1){
                        if(jumlahAreaA == 0){
                            cout<<"\n Tidak ada pengunjung yang terdata di area a!\n";
                            save = false;
                            break;
                        }
                        else{
                            bubbleSortArea(pengunjung, jumlahPengunjung);
                            tampilkanPengunjung(pengunjung, jumlahAreaA, "Area A");
                            hapus(pengunjung, jumlahAreaA);
                        }
                    }
                    else if(input == 2){
                        if(jumlahAreaB == 0){
                            cout<<"\n Tidak ada pengunjung yang terdata di area b!\n";
                            save = false;
                        }
                        else{
                            bubbleSortArea(pengunjung, jumlahPengunjung);
                            tampilkanPengunjung(pengunjung, jumlahAreaB, "Area B");
                            hapus(pengunjung, jumlahAreaB);
                        }
                    }
                    else if(input == 3){
                        if(jumlahAreaC == 0){
                        cout<<"\n Tidak ada pengunjung yang terdata di area c!\n";
                        save = false;
                        }
                        else{
                            bubbleSortArea(pengunjung, jumlahPengunjung);
                            tampilkanPengunjung(pengunjung, jumlahAreaC, "Area C");
                            hapus(pengunjung, jumlahAreaC);
                        }
                    }
                    else if(input == 4){
                        save = false;
                    }
                    else{
                        cout<<"\n Mohon ulangi dan masukan inputan angka secara benar!";
                        save = false;
                    }
                    break;
                case 3:
                    tagline(4);
                    menu(menuTampil, input);
                    system("CLS");
                    //Percabangan tampilkan data tiap areaa
                    if(input == 1){
                        bubbleSortArea(pengunjung, jumlahPengunjung);
                        tampilkanPengunjung(pengunjung, jumlahAreaA, "Area A");
                        save = false;
                    }
                    else if(input == 2){
                        bubbleSortArea(pengunjung, jumlahPengunjung);
                        tampilkanPengunjung(pengunjung, jumlahAreaB, "Area B");
                        save = false;
                    }
                    else if(input == 3){
                        bubbleSortArea(pengunjung, jumlahPengunjung);
                        tampilkanPengunjung(pengunjung, jumlahAreaC, "Area C");
                        save = false;
                    }
                    else if(input == 4){
                        bubbleSortArea(pengunjung, jumlahPengunjung);
                        tampilkanPengunjung(pengunjung, jumlahPengunjung);
                        save = false;
                    }
                    else if(input == 5){
                        save = false;
                    }
                    else{
                        cout<<"\n Mohon ulangi dan masukan inputan angka secara benar!";
                        save = false;
                    }
                    break;

                case 4:
                    tagline(5);
                    //Input penggunaan data master
                    menu(menuDataMaster, input);
                    system("CLS");
                    
                    //Percabangan pilihan menu data master
                    if(input == 1){
                        startInput();
                    }
                    else if(input == 2){
                        hapusRiwayat();
                    }
                    else if(input == 3){
                        save = false;
                    }
                    else{
                        cout<<"\n Mohon ulangi dan masukan inputan angka secara benar!";
                        save = false;
                    }
                    break;
                case 5:
                    tagline(6);
                    menu(menuRiwayat, input);

                    if(input == 1){
                        cout<<"\n Lihat Riwayat\n 1. Terbaru\n 2. Terlama\n Masukan pilihan : ";
                        cin>>input;
                        errorInput("\n Lihat Riwayat\n 1. Terbaru\n 2. Terlama\n Masukan pilihan : ", input);
                        system("CLS");

                        if(input == 1){
                            quickSortTanggal(riwayat, 0, jumlahRiwayat-1, 1);
                            tampilkanRiwayat(riwayat, jumlahRiwayat);
                        }
                        else if(input == 2){
                            quickSortTanggal(riwayat, 0, jumlahRiwayat-1, 2);
                            tampilkanRiwayat(riwayat, jumlahRiwayat);
                        }
                        else{
                            cout<<"\n Mohon ulangi dan masukan inputan angka secara benar!";
                            save = false;
                        }
                    }
                    else if(input == 2){
                        system("CLS");
                        binarySearchNama(riwayat, jumlahRiwayat);
                    }
                    else if(input == 3){
                        system("CLS");
                        save = false;
                    }
                    else{
                        system("CLS");
                        cout<<"\n Mohon ulangi dan masukan inputan angka secara benar!";
                        save = false;
                    }

                    break;
                case 6:
                    exit();
                    break;
            }
        }
        else{
            cout<<"\n  Mohon masukan angka antara 1-6.";
        }
    }
}

//Fungsi dan Prosedur

//--CRUD----------------------------------------------------------------------------------------------------------

//Prosedur menambahkan data baru ke daftar pengunjungay
void tambahDaftar(Data pengunjung[], int &jumlahPengunjung){
    if(jumlahAreaA+jumlahAreaB+jumlahAreaC == 30){
        cout<<" Tempat Wisata Sedang Penuh!";
        return;
    }
    string gender, area;
    cout<<"\n Masukan Nama      : ";fflush(stdin);getline(cin, pengunjung[jumlahPengunjung].orang.nama);
    while(gender != "l" && gender != "p"){
        cout<<" Pilih Gender(L/P) : ";fflush(stdin);getline(cin, gender);
        gender = lowercase(gender);
        if(gender == "l" || gender == "p"){
            pengunjung[jumlahPengunjung].orang.gender = gender;
        }
        else{
            cout<<"Mohon masukan L atau P!";
        }
    }
    cout<<" Masukan umur      : ";cin>>pengunjung[jumlahPengunjung].orang.umur;
    errorInput(pengunjung[jumlahPengunjung].orang.umur);
    while(area != "a" && area != "b" && area != "c"){
        cout<<" Area A: "<<jumlahAreaA<<"/10 | Area B : "<<jumlahAreaB<<"/10 | Area C : "<<jumlahAreaC<<"/10"<<"\n Masukan area      : ";fflush(stdin);getline(cin, area);
        area = lowercase(area);
        if(area == "a" && jumlahAreaA < 10){
            pengunjung[jumlahPengunjung].area = area;
        }
        else if(area == "b" && jumlahAreaB < 10){
            pengunjung[jumlahPengunjung].area = area;
        }
        else if(area == "c" && jumlahAreaC < 10){
            pengunjung[jumlahPengunjung].area = area;
        }
        else if(area != "a" && area != "b" && area != "c"){
            cout<<"Mohon masukan a, b atau c!\n";
        }
        else{
            cout<<"Mohon masukan area yang tidak penuh!";
        }
    }
    if(area == "a"){
        jumlahAreaA++;
        pengunjung[jumlahPengunjung].nomor = penentuNomor(noA);
    }
    else if(area == "b"){
        jumlahAreaB++;
        pengunjung[jumlahPengunjung].nomor = penentuNomor(noB);
    }
    else{
        jumlahAreaC++;
        pengunjung[jumlahPengunjung].nomor = penentuNomor(noC);
    }
    pengunjung[jumlahPengunjung].waktu.hari = hari;
    pengunjung[jumlahPengunjung].waktu.bulan = bulan;
    pengunjung[jumlahPengunjung].waktu.tahun = tahun;
    pengunjung[jumlahPengunjung].status = "Check In";

    riwayat[jumlahRiwayat] = pengunjung[jumlahPengunjung];
    jumlahPengunjung++;
    jumlahRiwayat++;
}

//Prosedur menampilkan daftar penghuni di dalam pengunjungay
void tampilkanPengunjung(Data pengunjung[], int jumlah, string area){
    if(area == "Riwayat"){
        cout<<"\n _Daftar "<<area<<"_ \n";
    }
    else if(area == "Cari"){
        cout<<"\n _Hasil "<<area<<"_ \n";
    }
    else{
        cout<<"\n _Daftar Pengunjung "<<area<<"_ \n";
    }
    int limit;
    if(jumlah>0){
        int perulangan, no = 1;
        if(area == "Area A"){
            perulangan = 0;
            limit = jumlahPengunjung - jumlahAreaB - jumlahAreaC; 
        }
        else if(area == "Area B"){
            perulangan = jumlahAreaA;
            limit = jumlahPengunjung - jumlahAreaC;
        }
        else if(area == "Area C"){
            perulangan = jumlahAreaA+jumlahAreaB;
            limit = jumlahPengunjung;
        }
        else if(area == "Semua Area"){
            perulangan = 0;
            limit = jumlahPengunjung;
        }
        else{
            perulangan = 0;
            limit = jumlah;
        }
        while(perulangan < limit){
            cout<<no<<". Nama      : "<<pengunjung[perulangan].orang.nama<<endl
                <<"   Gender    : "<<pengunjung[perulangan].orang.gender<<endl
                <<"   Umur      : "<<pengunjung[perulangan].orang.umur<<endl
                <<"   Area      : "<<pengunjung[perulangan].area<<endl
                <<"   Nomor     : "<<pengunjung[perulangan].nomor<<endl
                <<"   Tanggal   : "<<pengunjung[perulangan].waktu.hari
                                    <<"-"<<pengunjung[perulangan].waktu.bulan
                                    <<"-"<<pengunjung[perulangan].waktu.tahun<<endl;
            if(area == "Riwayat" || area == "Cari"){
                cout<<"   Aksi      : "<<pengunjung[perulangan].status<<endl;
            }
            cout<<endl;
            perulangan++;
            no++;
        }
    }
    else{
        cout<<"\n _Daftar Kosong_ \n";
    }
}

void tampilkanRiwayat(Data pengunjung[], int jumlah){
    bool loopRiwayat = true;
    int perulangan = 0, tab_ke = 1, no = 1;
    while(loopRiwayat){
        system("CLS");
        cout<<"\n _Daftar Riwayat_ \n";
        perulangan = tab_ke*5-5;
        int limit = 5*tab_ke;
        if(jumlah>0){
            while(perulangan < limit && perulangan != jumlah){
                cout<<no<<". Nama      : "<<pengunjung[perulangan].orang.nama<<endl
                    <<"   Gender    : "<<pengunjung[perulangan].orang.gender<<endl
                    <<"   Umur      : "<<pengunjung[perulangan].orang.umur<<endl
                    <<"   Area      : "<<pengunjung[perulangan].area<<endl
                    <<"   Nomor     : "<<pengunjung[perulangan].nomor<<endl
                    <<"   Tanggal   : "<<pengunjung[perulangan].waktu.hari
                                        <<"-"<<pengunjung[perulangan].waktu.bulan
                                        <<"-"<<pengunjung[perulangan].waktu.tahun<<endl
                    <<"   Aksi      : "<<pengunjung[perulangan].status<<endl<<endl;
                perulangan++;
                no++;
            }
        }
        else{
            cout<<"\n _Daftar Kosong_ \n";
            loopRiwayat = false;
        }

        if(perulangan < 5){
            while(true){
                menu("\n Kontrol Tampilan\n  1. Kembali\n  Masukan pilihan : ", input, 2);
                if(input == 1){
                    loopRiwayat = false;
                    system("CLS");
                    break;
                }
                else{
                    system("CLS");
                    cout<<"\n Mohon masukan input antara 1-2!";
                }
            }
        }
        else if(perulangan == 5){
            while(true){
                menu("\n Kontrol Tampilan\n  1. Selanjutnya\n  2. Kembali\n  Masukan pilihan : ", input, 2);
                if(input == 1){
                    tab_ke += 1;
                    break;
                }
                else if(input == 2){
                    loopRiwayat = false;
                    system("CLS");
                    break;
                }
                else{
                    system("CLS");
                    cout<<"\n Mohon masukan input antara 1-2!";
                }
            }
        }
        else if(perulangan == jumlah){
            while(true){
                menu("\n Kontrol Tampilan\n  1. Sebelumnya\n  2. Kembali\n  Masukan pilihan : ", input, 2);
                if(input == 1){
                    tab_ke -= 1;
                    perulangan -= 5;
                    no -= 5 + jumlah%5;
                    break;
                }
                else if(input == 2){
                    loopRiwayat = false;
                    system("CLS");
                    break;
                }
                else{
                    system("CLS");
                    cout<<"\n Mohon masukan input antara 1-2!";
                }
            }
        }
        else{
            while(true){
                menu("\n Kontrol Tampilan\n  1. Sebelumnya\n  2. Selanjutnya\n  3. Kembali\n  Masukan pilihan : ", input, 2);
                if(input == 1){
                    tab_ke -= 1;
                    perulangan -= 5;
                    no -= 10;
                    break;
                }
                else if(input == 2){
                    tab_ke += 1;
                    break;
                }
                else if(input == 3){
                    loopRiwayat = false;
                    system("CLS");
                    break;
                }
                else{
                    system("CLS");
                    cout<<"\n Mohon masukan input antara 1-3!";
                }
            }
        }
    }
}

//prosedur menampilkan tanggal
void tampilkanTanggal(){
    cout<<"\n /Tanggal/ : "<<hari<<"-"<<bulan<<"-"<<tahun<<endl<<endl;
}

//menghapus data saat checkout
void hapus(Data pengunjung[], int jumlah){
    int input, limit;
    inputan(input);
    while(true){
        if(input > jumlah || input < 0){
            cout<<"Tidak ada data dengan nomor urut tersebut!";
            inputan(input);
        }
        else{
            break;
        }
    }
    if(input == 0){
        system("CLS");
        return;
    }
    else if(jumlah == jumlahAreaA){;
        limit = jumlahPengunjung;
        resetNomor(noA, input-1);
        jumlahAreaA--;
    }
    else if(jumlah == jumlahAreaB){
        input += jumlahAreaA;
        limit = jumlahPengunjung - jumlahAreaA;
        resetNomor(noB, input-1);
        jumlahAreaB--;
    }
    else if(jumlah == jumlahAreaC){
        input += (jumlahAreaA+jumlahAreaB);
        limit = jumlahPengunjung - jumlahAreaA - jumlahAreaC;
        resetNomor(noC, input-1);
        jumlahAreaC--;
    }
    else{
        cout<<"\n function error";
        return;
    }

    for(int x = 0;x < jumlahPengunjung;x++){
        if(x == input-1){
            riwayat[jumlahRiwayat] = pengunjung[x];
            riwayat[jumlahRiwayat].waktu.hari = hari;
            riwayat[jumlahRiwayat].waktu.bulan = bulan;
            riwayat[jumlahRiwayat].waktu.tahun = tahun;
            riwayat[jumlahRiwayat].status = "Check Out";
            for(int y = x;y<limit-1;y++){
                pengunjung[y] = pengunjung[y+1];
            }
            jumlahPengunjung--;
            jumlahRiwayat++;
            system("CLS");
            cout<<"\n Check out berhasil!";
            return;
        }
    }
}

//prosedur menghapus isi riwayat
void hapusRiwayat(){
    string sandi;
    cout<<"\n Mohon masukan sandi untuk menghapus riwayat : ";
    fflush(stdin);getline(cin, sandi);
    if(sandi == "1111"){
        string konfirmasi;
        while(true){
            cout<<"\n Hapus seluruh riwayat? (y/t) : ";
            getline(cin, konfirmasi);
            konfirmasi = lowercase(konfirmasi);
            if(konfirmasi == "y"){
                fill(begin(riwayat),end(riwayat), kosong[0]);
                jumlahRiwayat = 0;
                system("CLS");
                cout<<"\n Isi Riwayat telah di hapus";
                while(true){
                    cout<<"\n Hapus file riwayat juga? (y/t) : ";
                    getline(cin, konfirmasi);
                    konfirmasi = lowercase(konfirmasi);
                    if(konfirmasi == "y"){
                        remove("riwayat.csv");
                        save = false;
                        system("CLS");
                        cout<<"\n Riwayat telah di hapus";
                        break;
                    }
                    else if(konfirmasi == "t"){
                        break;
                    }
                    else{
                        system("CLS");
                        cout<<"\n Input salah!";
                    }
                }
                break;
            }
            else if(konfirmasi == "t"){
                save = false;
                break;
            }
            else{
                system("CLS");
                cout<<"\n Input salah!";
            }
        }
    }
    else{
        cout<<"\n Sandi salah!";
        save = false;
    }
}

//--utilitas-----------------------------------------------------------------------------------------------------------------

//prosedur menu
void menu(string menu, int &input, int tuas){
    system("color B");
    switch(tuas){
        case 1:
            tampilkanTanggal();
            break;
        case 2:
            break;
    }
    cout<<menu;
    cin>>input;
    errorInput(menu, input);
}

//prosedur penukaran isi data menggunakan pointer sebagai argumen
void tukarData(Data *data1, Data *data2){ 
    Data pemegangSementara = *data1; 
    *data1 = *data2; 
    *data2 = pemegangSementara; 
}

//mengubah semua huruf besar string menjadi kecil
string lowercase(string kata){
    for(int x = 0;x < kata.length();x++){
        kata[x] = tolower(kata[x]);
    }
    return kata;
}

//mengubah inputan string menjadi datatype tujuan
void stringToType(string awal, int &tujuan){
    stringstream ubah(awal);
    ubah >> tujuan;
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

//Prosedur input memilih nomor urut daftar penghuni
void inputan(int &input){
    cout<<"\n Nomor Urut (0 untuk kembali) : ";cin>>input;
    //error handling input bukan angka
    while(true){
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"\nMohon masukan angka!\n"
                "\n Nomor Urut (0 untuk kembali) : ";cin>>input;
        }
        else{
            break;
        }
    }
}

//prosedur meminta tanggal saat program di mulai
void startInput(int &hari, int &bulan, int &tahun){
    system("color B");
    cout<<"\n Mohon masukan tanggal hari ini!";
    inputIntLimiter(hari, 1, 31, "\n  Tanggal hari  : ", "   Mohon masukan antara 1-31!");
    inputIntLimiter(bulan, 1, 12, "  Tanggal bulan : ", "   Mohon masukan antara 1-12!");
    inputIntLimiter(tahun, 2022, 9999, "  Tanggal tahun : ", "   Mohon masukan tahun dengan benar!");
}

//Fungsi membagi array untuk quicksort
int partisiA(Data riwayat[], int indexAwal, int indexAkhir)
{
    int i = (indexAwal - 1);
    for (int j = indexAwal; j < indexAkhir; j++){
        if((riwayat[j].waktu.tahun*10000) + (riwayat[j].waktu.bulan*100) + riwayat[j].waktu.hari <= (riwayat[indexAkhir].waktu.tahun*10000) + (riwayat[indexAkhir].waktu.bulan*100) + riwayat[indexAkhir].waktu.hari){
            i++; 
            swap(riwayat[i], riwayat[j]);
        }
    }
    swap(riwayat[i + 1], riwayat[indexAkhir]);
    return (i + 1);
}
int partisiD(Data riwayat[], int indexAwal, int indexAkhir)
{
    int i = (indexAwal - 1);
    for (int j = indexAwal; j < indexAkhir; j++){
        if((riwayat[j].waktu.tahun*10000) + (riwayat[j].waktu.bulan*100) + riwayat[j].waktu.hari > (riwayat[indexAkhir].waktu.tahun*10000) + (riwayat[indexAkhir].waktu.bulan*100) + riwayat[indexAkhir].waktu.hari){
            i++; 
            swap(riwayat[i], riwayat[j]);
        }
    }
    swap(riwayat[i + 1], riwayat[indexAkhir]);
    return (i + 1);
}

//prosedur mengurutkan nomor
void quickSortTanggal(Data riwayat[], int indexAwal, int indexAkhir, int tuas)
{
    if (indexAwal < indexAkhir){
        int pivotIndex;
        switch(tuas){
            case 1:
                pivotIndex = partisiA(riwayat, indexAwal, indexAkhir);
                break;
            case 2:
                pivotIndex = partisiD(riwayat, indexAwal, indexAkhir);
                break;
        }
        quickSortTanggal(riwayat, indexAwal, pivotIndex - 1, tuas);
        quickSortTanggal(riwayat, pivotIndex + 1, indexAkhir, tuas);
    }
}

//Prosedur sort insertion untuk attribut nama
void bubbleSortArea(Data pengunjung[], int jumlahPengunjung){
    int i, j;
    bool ditukar;
    for(i = 0; i < jumlahPengunjung-1; i++){
        ditukar = false;
        for (j = 0; j < jumlahPengunjung-i-1; j++){
            if (pengunjung[j].area > pengunjung[j+1].area){
                tukarData(&pengunjung[j], &pengunjung[j+1]);
                ditukar = true;
            }
        }
        if (ditukar == false)
        break;
    }
}
void bubbleSortNama(Data pengunjung[], int jumlahPengunjung){
    int i, j;
    bool ditukar;
    for(i = 0; i < jumlahPengunjung-1; i++){
        ditukar = false;
        for (j = 0; j < jumlahPengunjung-i-1; j++){
            if (pengunjung[j].orang.nama > pengunjung[j+1].orang.nama){
                tukarData(&pengunjung[j], &pengunjung[j+1]);
                ditukar = true;
            }
        }
        if (ditukar == false)
        break;
    }
}

//prosedur mencari
void binarySearchNama(Data riwayat[], int jumlahRiwayat){
    bubbleSortNama(riwayat, jumlahRiwayat);
    Data hasilCari[jumlahRiwayat];
    int indexAkhir = jumlahRiwayat, indexAwal = 0, index = 0;
    bool ketemu, hasilada;
    string yangDicari;
    cout<<"\n Nama yang ingin di cari : ";fflush(stdin);getline(cin, yangDicari);
    yangDicari = lowercase(yangDicari);
    while(indexAwal <= indexAkhir){
        int tengah = indexAwal + (indexAkhir - indexAwal) / 2;
        string isiArray;
        isiArray = riwayat[tengah].orang.nama;
        isiArray = lowercase(isiArray);
        if(stringCheck(yangDicari, isiArray) == true){
            ketemu = true;
            int sementara = tengah;
            
            //perulangan untuk kemungkinan ada lebih dari satu ke belakang
            while(stringCheck(yangDicari, isiArray)){
                hasilCari[index] = riwayat[tengah];
                index++;
                tengah -= 1;
                isiArray = riwayat[tengah].orang.nama;
                isiArray = lowercase(isiArray);
            }
            tengah = sementara+1;
            isiArray = riwayat[tengah].orang.nama;
            isiArray = lowercase(isiArray);

            //perulangan untuk kemungkinan ada lebih dari satu ke depan
            while(stringCheck(yangDicari, isiArray)){
                hasilCari[index] = riwayat[tengah];
                index++;
                tengah += 1;
                isiArray = riwayat[tengah].orang.nama;
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
        tampilkanRiwayat(hasilCari, index);
    }
    else{
        cout<<"\n Data tidak di temukan!\n";
    }
}

//prosedur menentukan nomor
int penentuNomor(bool no[]){
    int x = 0;
    while(x < 10){
        if(no[x] != true){
            no[x] = true;
            return x+1;
        }
        x++;
    }
    return 0;
}

//prosedur engembalikan slot nomor
void resetNomor(bool no[], int indexHapus){
    int x = 0;
    while(x < 10){
        if(pengunjung[indexHapus].nomor == x+1){
            no[x] = false;
        }
        x++;
    }
}

void gotoxy(int x, int y){
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void loadingScreen(){
    int i,j ;
    char ulang;
    
	// bingkai atas
    for(i=50 ; i<100 ; i++){
        gotoxy(i,1);
        system("color B");
        printf("-");
        gotoxy(i, 3);
        system("color B");
        printf("-");
    }
    gotoxy(60,2);
    system("color B");
    cout<<"D A T A  P E N G U N J U N G";
}

void tagline(int tuas){
    switch(tuas){
        case 1:
            gotoxy(50,1);
            system("color B");
            printf("--------------------------------------------------");
            gotoxy(50, 3);
            system("color B");
            printf("--------------------------------------------------");
            gotoxy(60,2);
            system("color B");
            cout<<"D A T A  P E N G U N J U N G";
            break;
        
        case 2:
            gotoxy(50,1);
            system("color B");
            printf("--------------------------------------------------");
            gotoxy(50, 3);
            system("color B");
            printf("--------------------------------------------------");
            gotoxy(60,2);
            system("color B");
            cout<<"C H E C K  I N  P E N G U N J U N G";
            break;

        case 3:
            gotoxy(50,1);
            system("color B");
            printf("--------------------------------------------------");
            gotoxy(50, 3);
            system("color B");
            printf("--------------------------------------------------");
            gotoxy(60,2);
            system("color B");
            cout<<"C H E C K  O U T  P E N G U N J U N G";
            break;
    
        case 4:
            gotoxy(50,1);
            system("color B");
            printf("--------------------------------------------------");
            gotoxy(50, 3);
            system("color B");
            printf("--------------------------------------------------");
            gotoxy(60,2);
            system("color B");
            cout<<"T A M P I L A N   D A T A";
            break;
        case 5:
            gotoxy(50,1);
            system("color B");
            printf("--------------------------------------------------");
            gotoxy(50, 3);
            system("color B");
            printf("--------------------------------------------------");
            gotoxy(60,2);
            system("color B");
            cout<<"D A T A  M A S T E R";
            break;
        case 6:
            gotoxy(50,1);
            system("color B");
            printf("--------------------------------------------------");
            gotoxy(50, 3);
            system("color B");
            printf("--------------------------------------------------");
            gotoxy(60,2);
            system("color B");
            cout<<"R I W A Y A T";
            break;
        }
}

//keluar dari program
void exit(){
    menyimmpanData(pengunjung, jumlahPengunjung, pathData,1);
    menyimmpanData(riwayat, jumlahRiwayat, pathRiwayat, 2);
    loop = false;
}

//--FIle Eksternal--------------------------------------------------------------------------------------

//Prosedur mengecek apakah data ada, jika tidak akan di buat baru
void dataCheck(string path){
    dataPengunjung.open(path, ios::app);
    if( !dataPengunjung.is_open() ){
        dataPengunjung.open(path, ios::trunc);
        dataPengunjung.close();
    }
    else{
        dataPengunjung.close();
    }
}

//memuat isi file eksternal ke variabel
void memuatPenyimpanan(string path, int tuas){
    dataPengunjung.open(path, ios::in);

    string sementara;
    int sementara2;
    switch(tuas){
        case 1:
            for(int x = 0;x < 10;x++){
                getline(dataPengunjung, sementara, ',');
                stringToType(sementara, sementara2);
                if(sementara2 == 1){
                    noA[x] = true;
                }
                else{
                    noA[x] = false;
                }
            }
            for(int x = 0;x < 10;x++){
                getline(dataPengunjung, sementara, ',');
                stringToType(sementara, sementara2);
                if(sementara2 == 1){
                    noB[x] = true;
                }
                else{
                    noB[x] = false;
                }
            }
            for(int x = 0;x < 9;x++){
                getline(dataPengunjung, sementara, ',');
                    stringToType(sementara, sementara2);
                if(sementara2 == 1){
                    noC[x] = true;
                }
                else{
                    noC[x] = false;
                }
            }
            getline(dataPengunjung, sementara, '\n');
                stringToType(sementara, sementara2);
            if(sementara2 == 1){
                noC[9] = true;
            }
            else{
                noC[9] = false;
            }
            getline(dataPengunjung, sementara, '\n');
                stringToType(sementara,jumlahPengunjung);
            getline(dataPengunjung, sementara, '\n');
                stringToType(sementara,jumlahAreaA);
            getline(dataPengunjung, sementara, '\n');
                stringToType(sementara,jumlahAreaB);
            getline(dataPengunjung, sementara, '\n');
                stringToType(sementara,jumlahAreaC);

            if(jumlahPengunjung != 0){
                int x = 0;
                while(true){
                    if(x == jumlahPengunjung){
                        break;
                    }
                    getline(dataPengunjung, pengunjung[x].orang.nama, ',');
                    getline(dataPengunjung, pengunjung[x].orang.gender, ',');
                    getline(dataPengunjung, sementara, ',');
                        stringToType(sementara ,pengunjung[x].orang.umur);
                    getline(dataPengunjung, pengunjung[x].area, ',');
                    getline(dataPengunjung, sementara, ',');
                        stringToType(sementara, pengunjung[x].nomor);
                    getline(dataPengunjung, sementara, ',');
                        stringToType(sementara, pengunjung[x].waktu.hari);
                    getline(dataPengunjung, sementara, ',');
                        stringToType(sementara, pengunjung[x].waktu.bulan);
                    getline(dataPengunjung, sementara, ',');
                        stringToType(sementara, pengunjung[x].waktu.tahun);
                    getline(dataPengunjung, pengunjung[x].status, '\n');         
                    x++;
                }
            }
            break;
        case 2:
            getline(dataPengunjung, sementara, '\n');
                stringToType(sementara,jumlahRiwayat);
            if(jumlahRiwayat != 0){
                int x = 0;
                while(true){
                    if(x == jumlahRiwayat){
                        break;
                    }
                    getline(dataPengunjung, riwayat[x].orang.nama, ',');
                    getline(dataPengunjung, riwayat[x].orang.gender, ',');
                    getline(dataPengunjung, sementara, ',');
                        stringToType(sementara ,riwayat[x].orang.umur);
                    getline(dataPengunjung, riwayat[x].area, ',');
                    getline(dataPengunjung, sementara, ',');
                        stringToType(sementara, riwayat[x].nomor);
                    getline(dataPengunjung, sementara, ',');
                        stringToType(sementara, riwayat[x].waktu.hari);
                    getline(dataPengunjung, sementara, ',');
                        stringToType(sementara, riwayat[x].waktu.bulan);
                    getline(dataPengunjung, sementara, ',');
                        stringToType(sementara, riwayat[x].waktu.tahun);
                    getline(dataPengunjung, riwayat[x].status, '\n');    
                    x++;
                }
            }
            break;
    }

    dataPengunjung.close();
}

//prosedur menyimpan data ke eksternal file
void menyimmpanData(Data pengunjung[], int jumlahPengunjung, string path, int tuas){
    dataPengunjung.open(path, ios::out);
    switch(tuas){
        case 1:
            for(int x = 0;x < 10;x++){
                if(noA[x]){
                    dataPengunjung << 1 << ",";
                }
                else{
                    dataPengunjung << 0 << ",";
                }
            }
            for(int x = 0;x < 10;x++){
                if(noB[x]){
                    dataPengunjung << 1 << ",";
                }
                else{
                    dataPengunjung << 0 << ",";
                }
            }
            for(int x = 0;x < 9;x++){
                if(noC[x]){
                    dataPengunjung << 1 << ",";
                }
                else{
                    dataPengunjung << 0 << ",";
                }
            }
            dataPengunjung << noC[9] << "\n";
            dataPengunjung << jumlahPengunjung << endl;
            dataPengunjung << jumlahAreaA << endl;
            dataPengunjung << jumlahAreaB << endl;
            dataPengunjung << jumlahAreaC << endl;
            break;
        case 2:
            dataPengunjung << jumlahPengunjung << endl;
            break;
    }
    for(int x = 0;x < jumlahPengunjung; x++){
        dataPengunjung  << pengunjung[x].orang.nama 
                        << "," << pengunjung[x].orang.gender 
                        << "," << pengunjung[x].orang.umur 
                        << "," << pengunjung[x].area
                        << "," << pengunjung[x].nomor
                        << "," << pengunjung[x].waktu.hari
                        << "," << pengunjung[x].waktu.bulan
                        << "," << pengunjung[x].waktu.tahun 
                        << "," << pengunjung[x].status<< endl;
    }
    dataPengunjung.close();
}


//--error handler--

//prosedur error handling
void errorInput(int &input){
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
void errorInput(string tampilanMenu, int &input){
    while(true){
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("CLS");
            cout<<"\n Mohon Masukan Pilihan Angka Dengan Benar!"<<endl;
            menu(tampilanMenu, input);
        }
        else{
            break;
        }
    }
}

//prosedur error handling input dalam suatu range
void inputIntLimiter(int &variabelInput,int limitKiri, int limitKanan, string teksInput, string teksError){
    while(true){
        cout<<teksInput;cin>>variabelInput;
        errorInput(variabelInput);
        if(variabelInput >= limitKiri && variabelInput <= limitKanan){
            break;
        }
        else{
            cout<<teksError;
        }
    }
}