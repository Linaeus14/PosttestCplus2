//Nama : Tito Darmawan
//NIM  : 2109106042
//Kelas: A2

#include<iostream>

using namespace std;

//Deklarasi variabel
string daftarBuku[100]; //Array daftar buku

//Penggunaan prototype prosedur
void tampilkanArray(string daftarBuku[], int jumlahBuku);
void tambahDaftar(string daftarBuku[], int jumlahBuku);
void inputan(int &input); //penggunaan pointer untuk inputan
void edit(string daftarBuku[]);
void hapus(string daftarBuku[], int jumlahBuku);

int main(){
    //Deklrasi local main
    int input, jumlahBuku = 0;;
    bool loop = true;

    //Perulangan program
    while(loop == true){
        //Input penggunaan
        cout<<"\n == Daftar Buku ==\n"
            <<" 1. Tambah Buku\n"
            <<" 2. Ubah Nama Buku\n"
            <<" 3. Hapus Buku\n"
            <<" 4. Tampilkan Daftar Buku\n"
            <<" 5. Exit program\n"
            <<"Masukan pilihan : ";
        cin>>input;

        //Percabangan kondisi switch untuk menentukan penggunaan program
        switch(input){
            case 1:
                tambahDaftar(daftarBuku, jumlahBuku);
                jumlahBuku++;
                break;
            case 2:
                tampilkanArray(daftarBuku, jumlahBuku);
                edit(daftarBuku);
                break;
            case 3:
                tampilkanArray(daftarBuku, jumlahBuku);
                hapus(daftarBuku, jumlahBuku);
                jumlahBuku--;
                break;
            case 4:
                tampilkanArray(daftarBuku, jumlahBuku);
                break;
            case 5:
                loop = false; //Penghenti perulangan program
                break;
        }
    }
}

//Prosedur menampilkan daftar buku di dalam array
void tampilkanArray(string daftarBuku[], int jumlahBuku){
    cout<<"\n _Daftar Buku_ \n";

    if(jumlahBuku>0){
        int perulangan = 0;
        while(perulangan < jumlahBuku){
            cout<<perulangan+1<<". "<<daftarBuku[perulangan]<<endl;
            perulangan++;
        }
    }
    else{
        cout<<"\n _Daftar Kosong_ \n";
    }
}

//Prosedur menambahkan nama buku baru ke daftar array
void tambahDaftar(string daftarBuku[], int jumlahBuku){
    cout<<"\n Masukan nama buku : ";fflush(stdin);getline(cin, daftarBuku[jumlahBuku]);
    cout<<"\n Buku telah di tambah! \n";
}

//Prosedur input memilih nomor urut daftar buku
void inputan(int &input2){
    cout<<"\n Nomor Buku : ";cin>>input2;
}

//Prosedur mengubah nama buku salah satu buku di daftar buku
void edit(string daftarBuku[]){
    int input2;
    inputan(input2);
    cout<<endl<<daftarBuku[input2-1]<<"\n Ubah menjadi : ";fflush(stdin);getline(cin, daftarBuku[input2-1]);
    cout<<"\n Buku telah di ubah menjadi \""<<daftarBuku[input2-1]<<"\"\n";
}

///Prosedur menghapus data dalam array dari suatu buku di daftar buku
void hapus(string daftarBuku[], int jumlahBuku){
    int input3;
    inputan(input3);
    for(int x = 0;x < jumlahBuku;x++){
        if(x == input3-1){
            for(int y = x;y<jumlahBuku-1;y++){
                daftarBuku[y] = daftarBuku[y+1];
            }
            x--;
            jumlahBuku--;
            cout<<"\n Buku telah di hapus! \n";
            return;
        }
    }
}