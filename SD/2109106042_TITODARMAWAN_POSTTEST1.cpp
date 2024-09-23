#include <iostream>
#include <limits>

using namespace std;

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

void Create(Data *array, int *jumlahRoster);
void Read(Data *array, int *jumlahRoster);
void Update(Data *array, int *jumlahRoster);
void Delete(Data *array, int *jumlahRoster);
void errorInput(int &input);

int main()
{
    int input, jumlahRoster = 0, input2;
    int *inp = &input2;
    bool loop = true;
    Data roster[6], *pdata;

    string menuUtama = "\n == Data Roster Karakter ==\n 1. Tambah Data\n 2. Lihat Data\n 3. Ubah Data\n 4. Hapus data\n 5. Keluar\n Masukan pilihan : ";
    while (loop == true)
    {
        pdata = &roster[0];
        cout << menuUtama;
        cin >> input;
        switch (input)
        {
        case 1:
            Create(pdata, &jumlahRoster);
            break;

        case 2:
            Read(pdata, &jumlahRoster);
            break;

        case 3:
            Update(pdata, &jumlahRoster);
            break;

        case 4:
            Delete(pdata, &jumlahRoster);
            break;

        case 5:
            loop = false;
            break;

        default:
            cout << "Terjadi Kesalahan";
            break;
        }
    }
}

void Create(Data *array, int *jumlahRoster)
{
    int input = 1;
    for (int x = 0; x < *jumlahRoster; x++)
    {
        array++;
    }

    cout << " \nTambah Data Karakter\n "
         << " SID     : ";
    cin >> array->sid;
    errorInput(array->sid);

    cout << "  Nama    : ";
    fflush(stdin);
    getline(cin, array->bio.nama);

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
        array->bio.gender = "Laki - laki";
        break;

    case 2:
        array->bio.gender = "Perempuan";
        break;

    case 3:
        array->bio.gender = "Tidak Terdefinisi";
        break;

    default:
        cout << "Terjadi Kesalahan";
        break;
    }
    input = 1;

    cout << "  Umur  :  ";
    cin >> array->bio.umur;
    errorInput(array->bio.umur);

    cout << "  Tanggal lahir\n"
         << "   Hari (angka) : ";
    cin >> array->lahir.hari;
    errorInput(array->lahir.hari);
    cout << "   Bulan : ";
    cin >> array->lahir.bulan;
    errorInput(array->lahir.bulan);
    cout << "   Tahun : ";
    cin >> array->lahir.tahun;
    errorInput(array->lahir.tahun);

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
        array->clas = "Saber";
        break;

    case 2:
        array->clas = "Lancer";
        break;

    case 3:
        array->clas = "Archer";
        break;

    case 4:
        array->clas = "Caster";
        break;

    case 5:
        array->clas = "Rider";
        break;

    case 6:
        array->clas = "Assassin";
        break;

    case 7:
        array->clas = "Extra";
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
        array->position = "Front";
        break;

    case 2:
        array->position = "Back";
        break;

    default:
        cout << "Terjadi Kesalahan";
        break;
    }

    *jumlahRoster = *jumlahRoster + 1;
    cout << " \nBerhasil!\n ";
}

void Read(Data *array, int *jumlahRoster)
{
    if (*jumlahRoster == 0)
    {
        cout << " \nKosong\n ";
        return;
    }

    cout << " \n=Roster Karakter=\n ";
    int no = 1;
    while (no - 1 < *jumlahRoster)
    {
        cout << no
             << ". SID       : " << array->sid << endl
             << "   Nama      : " << array->bio.nama << endl
             << "   Gender    : " << array->bio.gender << endl
             << "   Umur      : " << array->bio.umur << endl
             << "   Lahir     : " << array->lahir.hari << "-" << array->lahir.bulan << "-" << array->lahir.tahun << endl
             << "   Class     : " << array->clas << endl
             << "   Posisi    : " << array->position << endl;
        no++;
        array++;
    }
}

void Update(Data *array, int *jumlahRoster)
{
    if (*jumlahRoster == 0)
    {
        cout << " \nKosong\n ";
        return;
    }
    int input;
    Read(array, jumlahRoster);

    cout << "\n Pilih yang ingin di ubah (no urut) : ";
    do
    {
        if (input <= 0 or input >= *jumlahRoster + 1)
        {
            cout << " \nMasukan angka urut! \n Input : ";
        }
        cin >> input;
        errorInput(input);
    } while (input <= 0 or input >= *jumlahRoster + 1);

    input -= 1;
    int *inpp = &input;
    Create(array, inpp);
}

void Delete(Data *array, int *jumlahRoster)
{
    if (*jumlahRoster == 0)
    {
        cout << " \nKosong\n ";
        return;
    }
    int input = 1, limit = *jumlahRoster;
    Read(array, jumlahRoster);

    cout << "\n Pilih yang ingin di hapus (no urut) : ";
    do
    {
        if (input <= 0 or input >= *jumlahRoster + 1)
        {
            cout << " \nMasukan angka urut! \n Input : ";
        }
        cin >> input;
        errorInput(input);
    } while (input <= 0 or input >= *jumlahRoster + 1);

    for (int x = 0; x < limit; x++)
    {
        if (x == input - 1)
        {
            for (int y = x; y < *jumlahRoster - 1; y++)
            {
                array[y] = array[y + 1];
            }
            *jumlahRoster = *jumlahRoster - 1;
            cout << "Dihapus!";
            return;
        }
    }
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