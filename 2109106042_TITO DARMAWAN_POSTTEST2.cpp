//Nama : Tito Darmawan
//NIM  : 2109106042
//Kelas: A2

#include<iostream>

using namespace std;

int matriks1[3][3], matriks2[3][3], matrikshasil[3][3]; //penggunaan array multidimensi

main(){
    //input matriks
    cout<<"\n |==Pengali Matriks 3x3==|\n"<<"\n ==matriks1==";
    int baris1 = -1;
    while(baris1 < 2){ //perulangan untuk input tiap baris matriks1
        baris1++;
        cout<<endl;
        for(int kolom = 0;kolom < 3;kolom++){ //perulangan untuk input tiap kolom matriks1
            cout<<"Matriks1("<<baris1+1<<", "<<kolom+1<<") : ";cin>>matriks1[baris1][kolom];
        }
    }
    cout<<"\n  Dikali"<<"\n ================\n"<<"\n ==matriks2==";
    int baris2 = -1;
    while(baris2 < 2){ //perulangan untuk input tiap baris matriks2
        baris2++;
        cout<<endl;
        for(int kolom = 0;kolom < 3;kolom++){ //perulangan untuk input tiap kolom matriks2
            cout<<"Matriks2("<<baris2+1<<", "<<kolom+1<<") : ";cin>>matriks2[baris2][kolom];
        }
    }

    //perkalian matriks1 baris1 dan matriks2 kolom1 dengan pointer
    int matriks1baris1[3] = {matriks1[0][0], matriks1[0][1], matriks1[0][2]}, *pointer11;
    pointer11 = &matriks1baris1[0]; //deklarasi array baru untuk pointer
    
    int matriks2kolom1[3] = {matriks2[0][0], matriks2[1][0], matriks2[2][0]}, *pointer21; 
    pointer21 = &matriks2kolom1[0]; //deklarasi array baru untuk pointer
    int hasil[3];

    for(int x = 0;x<3;x++){
        hasil[x] = *pointer11 * *pointer21; //penggunaan pointer untuk perhitungan perkalian
        pointer11++, pointer21++;
    }
    int hasiljumlah = hasil[0] + hasil[1] + hasil[2];
    matrikshasil[0][0] = hasiljumlah;

    //perkalian matriks1 baris1 dan matriks2 kolom2 dengan pointer
    pointer11 = &matriks1baris1[0];
    int matriks2kolom2[3] = {matriks2[0][1], matriks2[1][1], matriks2[2][1]}, *pointer22; 
    pointer22 = &matriks2kolom2[0]; //deklarasi array baru untuk pointer

    for(int x = 0;x<3;x++){
        hasil[x] = *pointer11 * *pointer22; //penggunaan pointer untuk perhitungan perkalian
        pointer11++, pointer22++;
    }
    hasiljumlah = hasil[0] + hasil[1] + hasil[2];
    matrikshasil[0][1] = hasiljumlah;

    //perkalian matriks1 baris1 dan matriks2 kolom3 dengan pointer
    pointer11 = &matriks1baris1[0];
    int matriks2kolom3[3] = {matriks2[0][2], matriks2[1][2], matriks2[2][2]}, *pointer23; 
    pointer23 = &matriks2kolom3[0]; //deklarasi array baru untuk pointer

    for(int x = 0;x<3;x++){
        hasil[x] = *pointer11 * *pointer23; //penggunaan pointer untuk perhitungan perkalian
        pointer11++, pointer23++;
    }
    hasiljumlah = hasil[0] + hasil[1] + hasil[2];
    matrikshasil[0][2] = hasiljumlah;

    //perkalian matriks1 baris2 dan matriks2 kolom1 dengan pointer
    pointer21 = &matriks2kolom1[0];
    int matriks1baris2[3] = {matriks1[1][0], matriks1[1][1], matriks1[1][2]}, *pointer12;
    pointer12 = &matriks1baris2[0]; //deklarasi array baru untuk pointer

    for(int x = 0;x<3;x++){
        hasil[x] = *pointer12 * *pointer21; //penggunaan pointer untuk perhitungan perkalian
        pointer12++, pointer21++;
    }
    hasiljumlah = hasil[0] + hasil[1] + hasil[2];
    matrikshasil[1][0] = hasiljumlah;

    //perkalian matriks1 baris2 dan matriks2 kolom2 dengan pointer
    pointer12 = &matriks1baris2[0];
    pointer22 = &matriks2kolom2[0];

    for(int x = 0;x<3;x++){
        hasil[x] = *pointer12 * *pointer22; //penggunaan pointer untuk perhitungan perkalian
        pointer12++, pointer22++;
    }
    hasiljumlah = hasil[0] + hasil[1] + hasil[2];
    matrikshasil[1][1] = hasiljumlah;

    //perkalian matriks1 baris2 dan matriks2 kolom3 dengan pointer
    pointer12 = &matriks1baris2[0];
    pointer23 = &matriks2kolom3[0];

    for(int x = 0;x<3;x++){
        hasil[x] = *pointer12 * *pointer23; //penggunaan pointer untuk perhitungan perkalian
        pointer12++, pointer23++;
    }
    hasiljumlah = hasil[0] + hasil[1] + hasil[2];
    matrikshasil[1][2] = hasiljumlah;

    //perkalian matriks1 baris3 dan matriks2 kolom1 dengan pointer
    pointer21 = &matriks2kolom1[0];
    int matriks1baris3[3] = {matriks1[2][0], matriks1[2][1], matriks1[2][2]}, *pointer13;
    pointer13 = &matriks1baris3[0]; //deklarasi array baru untuk pointer

    for(int x = 0;x<3;x++){
        hasil[x] = *pointer13 * *pointer21; //penggunaan pointer untuk perhitungan perkalian
        pointer13++, pointer21++;
    }
    hasiljumlah = hasil[0] + hasil[1] + hasil[2];
    matrikshasil[2][0] = hasiljumlah;

    //perkalian matriks1 baris3 dan matriks2 kolom2 dengan pointer
    pointer13 = &matriks1baris3[0];
    pointer22 = &matriks2kolom2[0];

    for(int x = 0;x<3;x++){
        hasil[x] = *pointer13 * *pointer22; //penggunaan pointer untuk perhitungan perkalian
        pointer13++, pointer22++;
    }
    hasiljumlah = hasil[0] + hasil[1] + hasil[2];
    matrikshasil[2][1] = hasiljumlah;

    //perkalian matriks1 baris3 dan matriks2 kolom3 dengan pointer
    pointer13 = &matriks1baris3[0];
    pointer23 = &matriks2kolom3[0];

    for(int x = 0;x<3;x++){
        hasil[x] = *pointer13 * *pointer23; //penggunaan pointer untuk perhitungan perkalian
        pointer13++, pointer23++;
    }
    hasiljumlah = hasil[0] + hasil[1] + hasil[2];
    matrikshasil[2][2] = hasiljumlah;

    //deklarasi barisan masing-masing matriks ke pointer awal
    int matrikshasil1[3] = {matrikshasil[0][0], matrikshasil[0][1], matrikshasil[0][2]}, *pointerhasil1,
        matrikshasil2[3] = {matrikshasil[1][0], matrikshasil[1][1], matrikshasil[1][2]}, *pointerhasil2,
        matrikshasil3[3] = {matrikshasil[2][0], matrikshasil[2][1], matrikshasil[2][2]}, *pointerhasil3;
    pointerhasil1 = &matrikshasil1[0], 
    pointerhasil2 = &matrikshasil2[0], 
    pointerhasil3 = &matrikshasil3[0];
    pointer11 = &matriks1baris1[0];
    pointer12 = &matriks1baris2[0];
    pointer13 = &matriks1baris3[0];
    pointer21 = &matriks2kolom1[0];
    pointer22 = &matriks2kolom2[0];
    pointer23 = &matriks2kolom3[0];

    //Output
    cout<<"\n ==Hasil== \n";

    cout<<"\n ["<<*pointer11;pointer11++;cout<<", "<<*pointer11;pointer11++;cout<<", "<<*pointer11<<"]";
    cout<<"\n ["<<*pointer12;pointer12++;cout<<", "<<*pointer12;pointer12++;cout<<", "<<*pointer12<<"]";
    cout<<"\n ["<<*pointer13;pointer13++;cout<<", "<<*pointer13;pointer13++;cout<<", "<<*pointer13<<"]";

    cout<<"\n\n X \n";

    cout<<"\n ["<<*pointer21;pointer21++;cout<<", "<<*pointer22;pointer22++;cout<<", "<<*pointer23;pointer23++;cout<<"]";
    cout<<"\n ["<<*pointer21;pointer21++;cout<<", "<<*pointer22;pointer22++;cout<<", "<<*pointer23;pointer23++;cout<<"]";
    cout<<"\n ["<<*pointer21;cout<<", "<<*pointer22;cout<<", "<<*pointer23<<"]";

     cout<<"\n\n = \n";

    cout<<"\n ["<<*pointerhasil1;pointerhasil1++;cout<<", "<<*pointerhasil1;pointerhasil1++;cout<<", "<<*pointerhasil1<<"]";
    cout<<"\n ["<<*pointerhasil2;pointerhasil2++;cout<<", "<<*pointerhasil2;pointerhasil2++;cout<<", "<<*pointerhasil2<<"]";
    cout<<"\n ["<<*pointerhasil3;pointerhasil3++;cout<<", "<<*pointerhasil3;pointerhasil3++;cout<<", "<<*pointerhasil3<<"]";
}