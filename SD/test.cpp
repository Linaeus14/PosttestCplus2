#include <iostream>
#include <limits>

using namespace std;

// Pendeklarasian Structur dan Node
struct Identitas
{
    string nama;
    string gender;
    int umur;
};
struct tanggalLahir
{
    int hari,
        bulan,
        tahun;
};
struct Data
{
    int sid;
    Identitas bio;
    tanggalLahir lahir;
    string clas;
    string position;
};
struct Node
{
    Data data;
    Node *next;
};

//Prototype dari procedure dan fucntion di bawah main
void Read(Node *head);
void CreateM(Node **head, int *jumlahRoster);
void errorInput(int &input);
Node inputData();

int main()
{
    //Deklarasi variabel lokal
    int jumlahRoster = 0, input;
    bool loop = true;
    Node *head = NULL;
    string menuUtama = "\n == Data Roster Karakter ==\n 1. Tambah Data Middle\n 2. Lihat Data\n 3. Keluar\n Masukan pilihan : ";

    //loop menu utama
    while (loop == true)
    {
        cout << menuUtama;
        cin >> input;
        switch (input)
        {
        case 1:
            //pilihan satau add middle
            CreateM(&head, &jumlahRoster);
            break;

        case 2:
            //tampilkan data
            Read(head);
            break;

        case 3:
            //keluar
            loop = false;
            break;

        default:
            cout << " \n Terjadi Kesalahan\n";
            break;
        }
    }
}

//procedure menambahkan Node baru di awal, akhir, atau tengah urutan berdasarkan urutan yang di pilih
void CreateM(Node **head, int *jumlahRoster)
{
    int input;

    //mengecek apakah linked list kosong atau tidak, jika ya maka hanya bisa pilih urutan 1
    if (*head == NULL)
    {
        cout << "Urutan ke "
             << "(hanya 1) : ";
    }

    //menunjukan urutan yang bisa di pilih
    else
    {
        cout << "Urutan ke "
             << "(1-" << *jumlahRoster + 1 << ") : ";
    }


    cin >> input;errorInput(input); //input urutan yang akan di tambah
    if (0 < input and input < *jumlahRoster + 2) //syarat input yang di perbolehkan
    {
        //Membuat pointer Node baru dan sementara untuk traversal lokal
        Node *nodeBaru = new Node;
        nodeBaru->data = inputData().data;
        Node *temp = *head;

        //Menambah Node baru ke head jika di pilih urutan 1
        if (input == 1)
        {
            nodeBaru->next = *head;
            *head = nodeBaru;
            *jumlahRoster = *jumlahRoster + 1;
            return;
        }

        //melakukan tranversal sebannyak input -1
        for (int x = 0; x < input - 2; x++)
        {
            //mentransversal pointer sementara ke arah alamat yang di inginkan
            temp = temp->next;
        }

        //Memasang next Node sebelumnya dengan alamat node baru dan next node baru dengan alamt Node stelahnya
        nodeBaru->next = temp->next;
        temp->next = nodeBaru;
        *jumlahRoster = *jumlahRoster + 1;
    }
    else
    {
        //Jika input di luar syarat
        cout << "\n Tidak ada urutan " << input << "! \n";
        return;
    }
}

void Read(Node *head)
{
    if (head == NULL)
    {
        cout << ">> LinkedList masih kosong <<" << endl;
        return;
    }

    int no = 1;
    cout << " \n=Roster Karakter=\n";
    while (head != NULL)
    {
        cout << no
             << ". SID       : " << head->data.sid << endl
             << "   Nama      : " << head->data.bio.nama << endl
             << "   Gender    : " << head->data.bio.gender << endl
             << "   Umur      : " << head->data.bio.umur << endl
             << "   Lahir     : " << head->data.lahir.hari << "-" << head->data.lahir.bulan << "-" << head->data.lahir.tahun << endl
             << "   Class     : " << head->data.clas << endl
             << "   Posisi    : " << head->data.position << endl;
        no++;
        head = head->next;
    }
    cout << endl;
}

Node inputData()
{
    Node *dataBaru = new Node;
    int input;
    cout << " \nTambah Data Karakter\n "
         << " SID     : ";
    cin >> dataBaru->data.sid;
    errorInput(dataBaru->data.sid);

    cout << "  Nama    : ";
    fflush(stdin);
    getline(cin, dataBaru->data.bio.nama);

    cout << "  Gender\n   1. Laki-laki\n   2. Perempuan\n   3. Tidak Terdefinisi\n  Pilih (1/2/3) :  ";
    do
    {
        if (input <= 0 or input >= 4)
        {
            cout << " \nMasukan angka 1-3! \n Input : ";
        }
        cin >> input;
        errorInput(input);
    } while (input <= 0 or input >= 4);

    switch (input)
    {
    case 1:
        dataBaru->data.bio.gender = "Laki - laki";
        break;

    case 2:
        dataBaru->data.bio.gender = "Perempuan";
        break;

    case 3:
        dataBaru->data.bio.gender = "Tidak Terdefinisi";
        break;

    default:
        cout << "Terjadi Kesalahan";
        break;
    }
    input = 1;

    cout << "  Umur  :  ";
    cin >> dataBaru->data.bio.umur;
    errorInput(dataBaru->data.bio.umur);

    cout << "  Tanggal lahir\n"
         << "   Hari (angka) : ";
    cin >> dataBaru->data.lahir.hari;
    errorInput(dataBaru->data.lahir.hari);
    cout << "   Bulan : ";
    cin >> dataBaru->data.lahir.bulan;
    errorInput(dataBaru->data.lahir.bulan);
    cout << "   Tahun : ";
    cin >> dataBaru->data.lahir.tahun;
    errorInput(dataBaru->data.lahir.tahun);

    cout << "  Class\n   1. Saber\n   2. Lancer\n   3. Archer\n   4. Caster\n   5. Rider\n   6. Assassin\n   7. Extra\n    Pilih :  ";
    do
    {
        if (input <= 0 or input >= 8)
        {
            cout << " \nMasukan angka 1-7! \n Input : ";
        }
        cin >> input;
        errorInput(input);
    } while (input <= 0 or input >= 8);

    switch (input)
    {
    case 1:
        dataBaru->data.clas = "Saber";
        break;

    case 2:
        dataBaru->data.clas = "Lancer";
        break;

    case 3:
        dataBaru->data.clas = "Archer";
        break;

    case 4:
        dataBaru->data.clas = "Caster";
        break;

    case 5:
        dataBaru->data.clas = "Rider";
        break;

    case 6:
        dataBaru->data.clas = "Assassin";
        break;

    case 7:
        dataBaru->data.clas = "Extra";
        break;

    default:
        cout << "Terjadi Kesalahan";
        break;
    }
    input = 1;

    cout << "  Posisi\n   1. Front\n   2. Back\n    Pilih :  ";
    do
    {
        if (input <= 0 or input >= 3)
        {
            cout << " \nMasukan angka 1-2! \n Input : ";
        }
        cin >> input;
        errorInput(input);
    } while (input <= 0 or input >= 3);

    switch (input)
    {
    case 1:
        dataBaru->data.position = "Front";
        break;

    case 2:
        dataBaru->data.position = "Back";
        break;

    default:
        cout << "Terjadi Kesalahan";
        break;
    }

    cout << " \nBerhasil!\n ";
    return *dataBaru;
}

void errorInput(int &input)
{
    while (true)
    {
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Mohon masukan angka untuk input di atas!\n input :  ";
            cin >> input;
        }
        else
        {
            break;
        }
    }
}