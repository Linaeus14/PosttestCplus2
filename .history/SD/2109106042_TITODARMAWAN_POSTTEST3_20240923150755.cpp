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
struct Node
{
    Data data;
    Node *next;
};

void Create(Node *&head, int *jumlahRoster, string menu);
void Read(Node *head);
void Update(Node *&head);
void Delete(Node *&head, int *jumlahRoster, string menu);
void CF(Node *&head, int *jumlahRoster);
void CL(Node *&head, int *jumlahRoster);
void CP(Node *&head, int *jumlahRoster);
void DF(Node *&head, int *jumlahRoster);
void DL(Node *&head, int *jumlahRoster);
void DP(Node *&head, int *jumlahRoster);
void quickSort(struct Node *&headRef, int kategori = 11);
void Sort(Node *&head, string menu);
void errorInput(int &input);
Node *getTail(struct Node *cur);
Node *partition(Node *head, Node *end, Node **newHead, Node **newEnd, int kategori);
Node *quickSortRecur(struct Node *head, struct Node *end, int kategori);
Node inputData();

int main()
{
    int jumlahRoster = 0, input;
    bool loop = true;
    Node *head = NULL;

    string menuUtama = "\n == Data Roster Karakter ==\n 1. Tambah Data\n 2. Lihat Data\n 3. Ubah Data\n 4. Hapus data\n 5. Keluar\n Masukan pilihan : ";
    string menuTambah = "\n == Tambah Data Roster Karakter ==\n 1. Tambah di awal\n 2. Tambah di akhir\n 3. Tambah urutan tertentu\n Masukan pilihan : ";
    string menuHapus = "\n == Hapus Data Roster Karakter ==\n 1. Hapus urutan pertama\n 2. Hapus urutan akhir\n 3. Hapus urutan tertentu\n Masukan pilihan : ";
    string menuSort = "\n == Tampilkan Data Roster Karakter ==\n 1. Tampilkan tanpa sort\n 2. Sorting Berdasarkan SID (Ascending)\n 3. Sorting Berdasarkan SID (Descending)\n 4. Sorting Berdasarkan Umur (Ascending)\n 5. Sorting Berdasarkan Umur (Descending)\n Masukan pilihan : ";
    while (loop == true)
    {
        cout << menuUtama;
        cin >> input;
        switch (input)
        {
        case 1:
            Create(head, &jumlahRoster, menuTambah);
            break;

        case 2:
            Sort(head, menuSort);
            break;

        case 3:
            Update(&head);
            break;

        case 4:
            Delete(&head, &jumlahRoster, menuHapus);
            break;

        case 5:
            loop = false;
            break;

        default:
            cout << " \n Terjadi Kesalahan\n";
            break;
        }
    }
}

void Create(Node *&head, int *jumlahRoster, string menu)
{
    int input;
    bool loop = true;
    while (loop == true)
    {
        cout << menu;
        cin >> input;
        switch (input)
        {
        case 1:
            CF(head, jumlahRoster);
            loop = false;
            break;

        case 2:
            CL(head, jumlahRoster);
            loop = false;
            break;

        case 3:
            CP(head, jumlahRoster);
            loop = false;
            break;
        case 0:
            loop = false;
        default:
            cout << "Masukan antara 1-3 (0 untuk kembali)!";
            break;
        }
    }
}

void CF(Node *&head, int *jumlahRoster)
{
    Node *nodeBaru = new Node;
    nodeBaru->data = inputData().data;

    nodeBaru->next = *head;
    *head = nodeBaru;
    *jumlahRoster = *jumlahRoster + 1;
}

void CL(Node *&head, int *jumlahRoster)
{
    Node *nodeBaru = new Node;
    nodeBaru->data = inputData().data;
    nodeBaru->next = NULL;

    if (*head == NULL)
    {
        *head = nodeBaru;
        *jumlahRoster = *jumlahRoster + 1;
        return;
    }

    Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = nodeBaru;
    *jumlahRoster = *jumlahRoster + 1;
}

void CP(Node *&head, int *jumlahRoster)
{
    int input;
    if (*head == NULL)
    {
        cout << "Urutan ke "
             << "(hanya 1) : ";
    }
    else
    {
        cout << "Urutan ke "
             << "(1-" << *jumlahRoster + 1 << ") : ";
    }
    cin >> input;
    if (0 < input and input < *jumlahRoster + 2)
    {
        Node *nodeBaru = new Node;
        nodeBaru->data = inputData().data;
        Node *temp = *head;

        if (input == 1)
        {
            nodeBaru->next = *head;
            *head = nodeBaru;
            *jumlahRoster = *jumlahRoster + 1;
            return;
        }

        for (int x = 0; x < input - 2; x++)
        {
            temp = temp->next;
        }
        nodeBaru->next = temp->next;
        temp->next = nodeBaru;
        *jumlahRoster = *jumlahRoster + 1;
    }
    else
    {
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

void Sort(Node *&head, string menu)
{
    int input;
    bool loop = true;
    while (loop == true)
    {
        cout << menu;
        cin >> input;
        switch (input)
        {
        case 1:
            Read(*head);
            loop = false;
            break;

        case 2:
            quickSort(head, 11);
            Read(*head);
            loop = false;
            break;

        case 3:
            quickSort(head, 12);
            Read(*head);
            loop = false;
            break;
        case 4:
            quickSort(head, 21);
            Read(*head);
            loop = false;
            break;
        case 5:
            quickSort(head, 22);
            Read(*head);
            loop = false;
            break;
        case 0:
            loop = false;
        default:
            cout << "Masukan antara 1-5 (0 untuk kembali)!";
            break;
        }
    }
}

void Update(Node *&head)
{
    if (*head == NULL)
    {
        cout << "\n >> LinkedList masih kosong << \n"
             << endl;
        return;
    }
    string ubah;
    cout << "Masukan nama karakter yang akan diubah : ";
    cin >> ubah;
    Node *temp = (*head);
    while (temp != NULL)
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

void Delete(Node *&head, int *jumlahRoster, string menu)
{
    if (*head == NULL)
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
        switch (input)
        {
        case 1:
            DF(head, jumlahRoster);
            loop = false;
            break;

        case 2:
            DL(head, jumlahRoster);
            loop = false;
            break;

        case 3:
            DP(head, jumlahRoster);
            loop = false;
            break;
        case 0:
            loop = false;
        default:
            cout << "Masukan antara 1-3 (0 untuk kembali)!";
            break;
        }
    }
}

void DF(Node *&head, int *jumlahRoster)
{
    *head = (*head)->next;
    *jumlahRoster = *jumlahRoster - 1;
    cout << "\n Telah dihapus! \n";
}

void DL(Node *&head, int *jumlahRoster)
{

    if ((*head)->next == NULL)
    {
        *head = NULL;
        *jumlahRoster = *jumlahRoster - 1;
        cout << "\n Telah dihapus! \n";
        return;
    }

    Node *temp = *head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    *jumlahRoster = *jumlahRoster - 1;
    cout << "\n Telah dihapus! \n";
}

void DP(Node *&head, int *jumlahRoster)
{
    int input;
    Read(*head);
    cout << "Hapus urutan ke "
         << "(1-" << *jumlahRoster << ") : ";
    cin >> input;
    if (0 < input and input < *jumlahRoster + 1)
    {
        if (input == 1)
        {
            *head = (*head)->next;
            *jumlahRoster = *jumlahRoster - 1;
            cout << "\n Telah dihapus! \n";
            return;
        }

        Node *temp = *head, *temp2 = *head;
        for (int x = 0; x < input - 2; x++)
        {
            temp = temp->next;
        }
        temp2 = temp->next;
        temp->next = temp2->next;
        *jumlahRoster = *jumlahRoster - 1;
        cout << "\n Telah dihapus! \n";
    }
    else
    {
        cout << "\nTidak ada urutan " << input << "!\n";
        return;
    }
}

Node *getTail(struct Node *cur)
{
    while (cur != NULL && cur->next != NULL)
    {
        cur = cur->next;
    }
    return cur;
}

Node *partition(Node *head, Node *end, Node **newHead, Node **newEnd, int kategori)
{
    Node *pivot = end;
    Node *prev = NULL, *cur = head, *tail = pivot;

    switch (kategori)
    {
    case 11:
        while (cur != pivot)
        {
            if (cur->data.sid < pivot->data.sid)
            {
                if ((*newHead) == NULL)
                {
                    (*newHead) = cur;
                }
                prev = cur;
                cur = cur->next;
            }
            else
            {
                if (prev)
                {
                    prev->next = cur->next;
                }
                struct Node *tmp = cur->next;
                cur->next = NULL;
                tail->next = cur;
                tail = cur;
                cur = tmp;
            }
        }
        if ((*newHead) == NULL)
        {
            (*newHead) = pivot;
        }
        (*newEnd) = tail;
        return pivot;
        break;

    case 12:
        while (cur != pivot)
        {
            if (cur->data.sid > pivot->data.sid)
            {
                if ((*newHead) == NULL)
                {
                    (*newHead) = cur;
                }
                prev = cur;
                cur = cur->next;
            }
            else
            {
                if (prev)
                {
                    prev->next = cur->next;
                }
                struct Node *tmp = cur->next;
                cur->next = NULL;
                tail->next = cur;
                tail = cur;
                cur = tmp;
            }
        }
        if ((*newHead) == NULL)
        {
            (*newHead) = pivot;
        }
        (*newEnd) = tail;
        return pivot;
        break;

    case 21:
        while (cur != pivot)
        {
            if (cur->data.bio.umur < pivot->data.bio.umur)
            {
                if ((*newHead) == NULL)
                {
                    (*newHead) = cur;
                }
                prev = cur;
                cur = cur->next;
            }
            else
            {
                if (prev)
                {
                    prev->next = cur->next;
                }
                struct Node *tmp = cur->next;
                cur->next = NULL;
                tail->next = cur;
                tail = cur;
                cur = tmp;
            }
        }
        if ((*newHead) == NULL)
        {
            (*newHead) = pivot;
        }
        (*newEnd) = tail;
        return pivot;
        break;

    case 22:
        while (cur != pivot)
        {
            if (cur->data.bio.umur > pivot->data.bio.umur)
            {
                if ((*newHead) == NULL)
                {
                    (*newHead) = cur;
                }
                prev = cur;
                cur = cur->next;
            }
            else
            {
                if (prev)
                {
                    prev->next = cur->next;
                }
                struct Node *tmp = cur->next;
                cur->next = NULL;
                tail->next = cur;
                tail = cur;
                cur = tmp;
            }
        }
        if ((*newHead) == NULL)
        {
            (*newHead) = pivot;
        }
        (*newEnd) = tail;
        return pivot;
        break;
    }
    return pivot;
}

Node *quickSortRecur(Node *head, Node *end, int kategori)
{
    if (!head || head == end)
    {
        return head;
    }

    Node *newHead = NULL, *newEnd = NULL;
    Node *pivot = partition(head, end, &newHead, &newEnd, kategori);

    if (newHead != pivot)
    {
        struct Node *tmp = newHead;
        while (tmp->next != pivot)
        {
            tmp = tmp->next;
            tmp->next = NULL;
            newHead = quickSortRecur(newHead, tmp, kategori);
            tmp = getTail(newHead);
            tmp->next = pivot;
        }
        pivot->next = quickSortRecur(pivot->next, newEnd, kategori);
        return newHead;
    }
    return newHead;
}

void quickSort(Node *&headRef, int kategori)
{
    (*headRef) = quickSortRecur(*headRef, getTail(*headRef), kategori);
    (*headRef) = quickSortRecur(*headRef, getTail(*headRef), kategori);
    return;
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