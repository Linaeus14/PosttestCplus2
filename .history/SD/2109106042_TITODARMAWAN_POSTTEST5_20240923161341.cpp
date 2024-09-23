#include <iostream>
#include <limits>
#include <bits/stdc++.h>

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
struct Node
{
    Data data;
    Node *next;
    Node *prev;
};

void Create(Node *&head, Node *&tail, int &jumlahRoster, string menu);
void Read(Node *head, Node *tail, int index, int tuas);
void Update(Node *&head);
void Delete(Node *&head, Node *&tail, int &jumlahRoster, string menu);
void CF(Node *&head, Node *&tail, int &jumlahRoster);
void CL(Node *&head, Node *&tail, int &jumlahRoster);
void CP(Node *&head, Node *&tail, int &jumlahRoster);
void DF(Node *&head, Node *&tail, int &jumlahRoster);
void DL(Node *&head, Node *&tail, int &jumlahRoster);
void DP(Node *&head, Node *&tail, int &jumlahRoster);
void swap(Node *a, Node *b);
void _quickSort(Node *head, Node tail, int kategori);
void quickSort(Node head, Node tail, int kategori);
void Sort(Node *&head, Node *&tail, string menu);
void Search(Node *&head, Node *&tail, int jumlahRoster, string menu);
void errorInput(int &input);
int min(int x, int y);
int fibonacciSearch(Node *node, int x, int n);
int jumpSearch(Node *node, int x, int n);
Node *partition(Node *l, Node *h, int kategori);
Node inputData();

int main()
{
    int jumlahRoster = 0, input;
    bool loop = true;
    Node *head = nullptr;
    Node *tail = nullptr;

    string menuUtama = "\n == Data Roster Karakter ==\n 1. Tambah Data\n 2. Lihat Data\n 3. Ubah Data\n 4. Hapus data\n 5. Cari Data\n 6. Keluar\n Masukan pilihan : ";
    string menuTambah = "\n == Tambah Data Roster Karakter ==\n 1. Tambah di awal\n 2. Tambah di akhir\n 3. Tambah urutan tertentu\n Masukan pilihan : ";
    string menuHapus = "\n == Hapus Data Roster Karakter ==\n 1. Hapus urutan pertama\n 2. Hapus urutan akhir\n 3. Hapus urutan tertentu\n Masukan pilihan : ";
    string menuSort = "\n == Tampilkan Data Roster Karakter ==\n 1. Tampilkan tanpa sort dari depan\n 2. Tampilkan tanpa sort dari belakang\n 3. Sorting Berdasarkan SID (Ascending)\n 4. Sorting Berdasarkan SID (Descending)\n 5. Sorting Berdasarkan Umur (Ascending)\n 6. Sorting Berdasarkan Umur (Descending)\n Masukan pilihan : ";
    string menuSearch = "\n == Cari Data Roster Karakter ==\n 1. Cari Umur\n 2. Cari SID\n Masukan pilihan : ";
    while (loop == true)
    {
        cout << menuUtama;
        cin >> input;
        switch (input)
        {
        case 1:
            Create(head, tail, jumlahRoster, menuTambah);
            break;

        case 2:
            Sort(head, tail, menuSort);
            break;

        case 3:
            Update(head);
            break;

        case 4:
            Delete(head, tail, jumlahRoster, menuHapus);
            break;

        case 5:
            Search(head, tail, jumlahRoster, menuSearch);
            break;

        case 6:
            loop = false;
            break;

        default:
            cout << " \n Terjadi Kesalahan\n";
            break;
        }
    }
}

void Create(Node *&head, Node *&tail, int &jumlahRoster, string menu)
{
    int input;
    bool loop = true;
    while (loop == true)
    {
        cout << menu;
        cin >> input;
        errorInput(input);
        switch (input)
        {
        case 1:
            CF(head, tail, jumlahRoster);
            loop = false;
            break;

        case 2:
            CL(head, tail, jumlahRoster);
            loop = false;
            break;

        case 3:
            CP(head, tail, jumlahRoster);
            loop = false;
            break;

        case 0:
            loop = false;
            break;

        default:
            cout << "Masukan antara 1-3 (0 untuk kembali)!";
            break;
        }
    }
}

void CF(Node *&head, Node *&tail, int &jumlahRoster)
{
    Node *nodeBaru = new Node;
    nodeBaru->data = inputData().data;
    if (head == nullptr)
    {
        nodeBaru->next = nullptr;
        nodeBaru->prev = nullptr;
        head = nodeBaru;
        tail = nodeBaru;
    }
    else
    {
        nodeBaru->next = head;
        (head)->prev = nodeBaru;
        nodeBaru->prev = nullptr;
        head = nodeBaru;
    }
    jumlahRoster = jumlahRoster + 1;
}

void CL(Node *&head, Node *&tail, int &jumlahRoster)
{
    Node *nodeBaru = new Node;
    nodeBaru->data = inputData().data;
    if (tail == nullptr)
    {
        nodeBaru->next = nullptr;
        nodeBaru->prev = nullptr;
        head = nodeBaru;
        tail = nodeBaru;
    }
    else
    {
        nodeBaru->prev = tail;
        (tail)->next = nodeBaru;
        nodeBaru->next = nullptr;
        tail = nodeBaru;
    }
    jumlahRoster = jumlahRoster + 1;
}

void CP(Node *&head, Node *&tail, int &jumlahRoster)
{
    int input;
    if (head == nullptr)
    {
        cout << "Urutan ke "
             << "(hanya 1) : ";
    }
    else
    {
        cout << "Urutan ke "
             << "(1-" << jumlahRoster + 1 << ") : ";
    }
    cin >> input;
    if (0 < input and input < jumlahRoster + 2)
    {
        Node *nodeBaru = new Node;
        nodeBaru->data = inputData().data;
        Node *temp = head;
        Node *temp2;

        if (input == 1)
        {
            nodeBaru->next = nullptr;
            nodeBaru->prev = nullptr;
            head = nodeBaru;
            tail = nodeBaru;
            jumlahRoster = jumlahRoster + 1;
            return;
        }

        for (int x = 0; x < input - 2; x++)
        {
            temp = temp->next;
        }
        temp2 = temp->next;

        nodeBaru->next = temp->next;
        nodeBaru->prev = temp;
        temp2->prev = nodeBaru;
        temp->next = nodeBaru;
        jumlahRoster = jumlahRoster + 1;
    }
    else
    {
        cout << "\n Tidak ada urutan " << input << "! \n";
        return;
    }
}

void Read(Node *head, Node *tail, int index, int tuas)
{
    if (index != -3 and index != -2 and index != -1)
    {
        for (int i = 0; i < index; i++)
        {
            head = head->next;
        }
        switch (tuas)
        {
        case 0:
            if (head->prev != nullptr)
            {
                while (head->data.sid == (head->prev)->data.sid)
                {
                    if (head->prev != nullptr)
                    {
                        head = head->prev;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            if (head->next != nullptr)
            {
                cout << "\n Data yang di temukan : " << endl
                     << endl;
                do
                {
                    cout << "   SID       : " << head->data.sid << endl
                         << "   Nama      : " << head->data.bio.nama << endl
                         << "   Gender    : " << head->data.bio.gender << endl
                         << "   Umur      : " << head->data.bio.umur << endl
                         << "   Lahir     : " << head->data.lahir.hari << "-" << head->data.lahir.bulan << "-" << head->data.lahir.tahun << endl
                         << "   Class     : " << head->data.clas << endl
                         << "   Posisi    : " << head->data.position << endl
                         << endl;
                    if (head->next != nullptr)
                    {
                        head = head->next;
                    }
                    else
                    {
                        break;
                    }
                } while ((head->prev)->data.sid == head->data.sid);
                return;
            }
            else
            {
                cout << "\n Data yang di temukan : " << endl
                     << endl
                     << "   SID       : " << head->data.sid << endl
                     << "   Nama      : " << head->data.bio.nama << endl
                     << "   Gender    : " << head->data.bio.gender << endl
                     << "   Umur      : " << head->data.bio.umur << endl
                     << "   Lahir     : " << head->data.lahir.hari << "-" << head->data.lahir.bulan << "-" << head->data.lahir.tahun << endl
                     << "   Class     : " << head->data.clas << endl
                     << "   Posisi    : " << head->data.position << endl
                     << endl;
                return;
            }
            break;

        case 1:
            if (head->prev != nullptr)
            {
                while (head->data.bio.umur == (head->prev)->data.bio.umur)
                {
                    if (head->prev != nullptr)
                    {
                        head = head->prev;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            if (head->next != nullptr)
            {
                cout << "\n Data yang di temukan : " << endl
                     << endl;
                do
                {
                    cout << "   SID       : " << head->data.sid << endl
                         << "   Nama      : " << head->data.bio.nama << endl
                         << "   Gender    : " << head->data.bio.gender << endl
                         << "   Umur      : " << head->data.bio.umur << endl
                         << "   Lahir     : " << head->data.lahir.hari << "-" << head->data.lahir.bulan << "-" << head->data.lahir.tahun << endl
                         << "   Class     : " << head->data.clas << endl
                         << "   Posisi    : " << head->data.position << endl
                         << endl;
                    if (head->next != nullptr)
                    {
                        head = head->next;
                    }
                    else
                    {
                        break;
                    }
                } while ((head->prev)->data.bio.umur == head->data.bio.umur);
                return;
            }
            else
            {
                cout << "\n Data yang di temukan : " << endl
                     << endl
                     << "   SID       : " << head->data.sid << endl
                     << "   Nama      : " << head->data.bio.nama << endl
                     << "   Gender    : " << head->data.bio.gender << endl
                     << "   Umur      : " << head->data.bio.umur << endl
                     << "   Lahir     : " << head->data.lahir.hari << "-" << head->data.lahir.bulan << "-" << head->data.lahir.tahun << endl
                     << "   Class     : " << head->data.clas << endl
                     << "   Posisi    : " << head->data.position << endl
                     << endl;
                return;
            }
            break;
        }
    }
    else if (index == -1)
    {
        cout << "\n Data tidak ditemukan! \n";
        return;
    }
    else
    {
        if (head == nullptr)
        {
            cout << ">> LinkedList masih kosong <<" << endl;
            return;
        }
        else if (index == -2)
        {
            int no = 1;
            cout << " \n=Roster Karakter=\n";
            while (head != nullptr)
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
        else
        {
            int no = 1;
            cout << " \n=Roster Karakter=\n";
            while (tail != nullptr)
            {
                cout << no
                     << ". SID       : " << tail->data.sid << endl
                     << "   Nama      : " << tail->data.bio.nama << endl
                     << "   Gender    : " << tail->data.bio.gender << endl
                     << "   Umur      : " << tail->data.bio.umur << endl
                     << "   Lahir     : " << tail->data.lahir.hari << "-" << tail->data.lahir.bulan << "-" << tail->data.lahir.tahun << endl
                     << "   Class     : " << tail->data.clas << endl
                     << "   Posisi    : " << tail->data.position << endl;
                no++;
                tail = tail->prev;
            }
            cout << endl;
        }
    }
}

void Sort(Node *&head, Node *&tail, string menu)
{
    int input;
    bool loop = true;
    while (loop == true)
    {
        cout << menu;
        cin >> input;
        errorInput(input);
        switch (input)
        {
        case 1:
            Read(head, tail, -2, 0);
            loop = false;
            break;

        case 2:
            Read(head, tail, -3, 0);
            loop = false;
            break;

        case 3:
            quickSort(head, tail, 11);
            Read(head, tail, -2, 0);
            loop = false;
            break;

        case 4:
            quickSort(head, tail, 12);
            Read(head, tail, -2, 0);
            loop = false;
            break;

        case 5:
            quickSort(head, tail, 21);
            Read(head, tail, -2, 0);
            loop = false;
            break;

        case 6:
            quickSort(head, tail, 22);
            Read(head, tail, -2, 0);
            loop = false;
            break;

        case 0:
            loop = false;
            break;

        default:
            cout << "Masukan antara 1-6 (0 untuk kembali)!";
            break;
        }
    }
}

void Update(Node *&head)
{
    if (head == nullptr)
    {
        cout << "\n >> LinkedList masih kosong << \n"
             << endl;
        return;
    }
    string ubah;
    cout << "Masukan nama karakter yang akan diubah : ";
    cin >> ubah;
    Node *temp = (head);
    while (temp != nullptr)
    {
        if (temp->data.bio.nama == ubah)
        {
            cout << "Masukan data yang baru : ";
            temp->data = inputData().data;
            cout << "Data berhasil diubah" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Data tidak ditemukan" << endl;
}

void Delete(Node *&head, Node *&tail, int &jumlahRoster, string menu)
{
    if (head == nullptr)
    {
        cout << "\n >> LinkedList masih kosong << \n"
             << endl;
        return;
    }

    int input;
    bool loop = true;
    while (loop == true)
    {
        cout << menu;
        cin >> input;
        errorInput(input);
        switch (input)
        {
        case 1:
            DF(head, tail, jumlahRoster);
            loop = false;
            break;

        case 2:
            DL(head, tail, jumlahRoster);
            loop = false;
            break;

        case 3:
            DP(head, tail, jumlahRoster);
            loop = false;
            break;

        case 0:
            loop = false;
            break;

        default:
            cout << "Masukan antara 1-3 (0 untuk kembali)!";
            break;
        }
    }
}

void DF(Node *&head, Node *&tail, int &jumlahRoster)
{
    if (head == tail)
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        head = (head)->next;
        (head)->prev = nullptr;
    }
    jumlahRoster = jumlahRoster - 1;
    cout << "\n Telah dihapus! \n";
}

void DL(Node *&head, Node *&tail, int &jumlahRoster)
{
    if (head == tail)
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        tail = (tail)->prev;
        (tail)->next = nullptr;
    }
    jumlahRoster = jumlahRoster - 1;
    cout << "\n Telah dihapus! \n";
}

void DP(Node *&head, Node *&tail, int &jumlahRoster)
{
    int input;
    Read(head, tail, -2, 0);
    cout << "Hapus urutan ke "
         << "(1-" << jumlahRoster << ") : ";
    cin >> input;
    if (0 < input and input < jumlahRoster + 1)
    {
        if (input == 1)
        {
            if (head == tail)
            {
                head = nullptr;
                tail = nullptr;
            }
            else
            {
                head = (head)->next;
                (head)->prev = nullptr;
            }
            jumlahRoster = jumlahRoster - 1;
            cout << "\n Telah dihapus! \n";
            return;
        }

        Node *temp = head, *temp2;
        for (int x = 0; x < input - 2; x++)
        {
            temp = temp->next;
        }
        temp2 = (temp->next)->next;

        temp2->prev = temp;
        temp->next = temp2;
        jumlahRoster = jumlahRoster - 1;
        cout << "\n Telah dihapus! \n";
    }
    else
    {
        cout << "\nTidak ada urutan " << input << "!\n";
        return;
    }
}

void swap(Node *a, Node *b)
{
    Node *t = new Node;
    t->data = a->data;
    a->data = b->data;
    b->data = t->data;
}

Node *partition(Node *l, Node *h, int kategori)
{
    int x;
    if (kategori == 11 or kategori == 12)
    {
        x = h->data.sid;
    }
    else
    {
        x = h->data.bio.umur;
    }
    Node *i = l->prev;

    switch (kategori)
    {
    case 11:
        for (Node *j = l; j != h; j = j->next)
        {
            if (j->data.sid <= x)
            {
                i = (i == nullptr) ? l : i->next;

                swap(i, j);
            }
        }
        i = (i == nullptr) ? l : i->next;
        swap(i, h);
        return i;
        break;

    case 12:
        for (Node *j = l; j != h; j = j->next)
        {
            if (j->data.sid >= x)
            {
                i = (i == nullptr) ? l : i->next;

                swap(i, j);
            }
        }
        i = (i == nullptr) ? l : i->next;
        swap(i, h);
        return i;
        break;

    case 21:
        for (Node *j = l; j != h; j = j->next)
        {
            if (j->data.bio.umur <= x)
            {
                i = (i == nullptr) ? l : i->next;

                swap(i, j);
            }
        }
        i = (i == nullptr) ? l : i->next;
        swap(i, h);
        return i;
        break;

    case 22:
        for (Node *j = l; j != h; j = j->next)
        {
            if (j->data.bio.umur >= x)
            {
                i = (i == nullptr) ? l : i->next;

                swap(i, j);
            }
        }
        i = (i == nullptr) ? l : i->next;
        swap(i, h);
        return i;
        break;
    }
    return i;
}

void _quickSort(Node head, Node tail, int kategori)
{
    if (tail != nullptr && head != tail && head != tail->next)
    {
        Node *p = partition(head, tail, kategori);
        _quickSort(head, p->prev, kategori);
        _quickSort(p->next, tail, kategori);
    }
}

void quickSort(Node head, Node tail, int kategori)
{
    _quickSort(head, tail, kategori);
    return;
}

void Search(Node *&head, Node *&tail, int jumlahRoster, string menu)
{
    int input, index;
    bool loop = true;
    while (loop == true)
    {
        cout << menu;
        cin >> input;
        errorInput(input);
        switch (input)
        {
        case 1:
            cout << "Umur yan di cari : ";
            cin >> input;
            errorInput(input);
            quickSort(head, tail, 21);
            index = fibonacciSearch(head, input, jumlahRoster);
            Read(head, tail, index, 1);
            loop = false;
            break;

        case 2:
            cout << "SID yan di cari : ";
            cin >> input;
            errorInput(input);
            quickSort(head, tail, 11);
            index = jumpSearch(head, input, jumlahRoster);
            Read(head, tail, index, 0);
            loop = false;
            break;

        case 0:
            loop = false;
            break;

        default:
            cout << "Masukan antara 1-2 (0 untuk kembali)!";
            break;
        }
    }
}

int min(int x, int y)
{
    return (x <= y) ? x : y;
}

int fibonacciSearch(Node *node, int x, int n)
{
    int F0 = 0;
    int F1 = 1;
    int F = F0 + F1;
    while (F < n)
    {
        F0 = F1;
        F1 = F;
        F = F0 + F1;
    }
    int offset = -1;
    while (F > 1)
    {

        Node head = node;
        int i = min(offset + F0, n - 1);
        for (int trv = 0; head->next != nullptr && trv < i; trv++)
        {
            head = head->next;
        }
        if (head->data.bio.umur < x)
        {
            F = F1;
            F1 = F0;
            F0 = F - F1;
            offset = i;
        }
        else if (head->data.bio.umur > x)
        {
            F = F0;
            F1 = F1 - F0;
            F0 = F - F1;
        }
        else
        {
            return i;
        }
    }

    Node head2 = node;
    for (int trv = 0; head2->next != nullptr && trv < offset + 1; trv++)
    {
        head2 = head2->next;
    }
    if (F1 && head2->data.bio.umur == x)
        return offset + 1;
    return -1;
}

int jumpSearch(Node *node, int x, int n)
{
    int step = sqrt(n);
    int prev;
    Node head = node;

    if (head->data.sid == x)
        return 0;

    for (int trv = 0; head->next != nullptr && trv < min(step, n) - 1; trv++)
    {
        head = head->next;
    }

    while (head->data.sid < x)
    {
        prev = step;
        step += sqrt(n);
        if (prev >= n)
            return -1;

        for (int trv = 0; head->next != nullptr && trv < min(step, n) - 1; trv++)
        {
            head = head->next;
        }
    }

    Node head2 = node;

    for (int trv = 0; head2->next != nullptr && trv < prev; trv++)
    {
        head2 = head2->next;
    }

    while (head2->data.sid < x)
    {
        prev++;
        if (prev == min(step, n))
            return -1;

        for (int trv = 0; head2->next != nullptr && trv < prev; trv++)
        {
            head2 = head2->next;
        }
    }

    if (head2->data.sid == x)
        return prev;
    return -1;
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
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Membersihkan input buffer dari cin sebelumnya
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