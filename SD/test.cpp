#include <iostream>
using namespace std;
 
struct mahasiswa{
    string nama;
    int nim;
    double ipk;
};
 
struct Node{
    mahasiswa data;
    Node *next;
    Node *prev;
};
 
int panjangList;
 
void show(Node *head){
    if (head == NULL){
        cout << "LinkedList Kosong" << endl;
        system("pause");
        return;
    } else {
        Node *temp = head;
        int indeks;
        for (indeks = 0; temp != NULL; indeks++){
            cout << "[" << indeks << "]" << endl;
            cout << "Nama: " << temp->data.nama << endl;
            cout << "NIM : " << temp->data.nim << endl;
            cout << "IPK : " << temp->data.ipk << endl;
            temp = temp->next;
        }
        panjangList = indeks;
        system("pause");
    }
}

void showLast(Node *tail, int panjangList){
    if (tail == NULL){
        cout << "LinkedList Kosong" << endl;
        system("pause");
        return;
    } else {
        Node *temp = tail;
        int indeks;
        for (indeks = panjangList; temp != NULL; indeks--){
            cout << "[" << indeks << "]" << endl;
            cout << "Nama: " << temp->data.nama << endl;
            cout << "NIM : " << temp->data.nim << endl;
            cout << "IPK : " << temp->data.ipk << endl;
            temp = temp->prev;
        }
        system("pause");
    }
}

void insertFirst(Node **head, Node **tail){
    cout << "\n[ Tambah data di awal ]" << endl;
    Node *newNode = new Node();
    cout << "Nama: "; cin.ignore(); getline(cin, newNode->data.nama);
    cout << "NIM : "; cin >> newNode->data.nim;
    cout << "IPK : "; cin >> newNode->data.ipk;
    newNode->prev = NULL;
    newNode->next = *head;
    if (*head == NULL && *tail == NULL){
        *head = newNode;
        *tail = newNode;
    } else {
        *head = newNode;
    }
    panjangList++;
    cout << "Data telah tersimpan." << endl;
    system("pause");
}

void insertLast(Node **head, Node **tail){
    cout << "\n[ Tambah data di akhir ]" << endl;
    Node *newNode = new Node();
    cout << "Nama: "; cin.ignore(); getline(cin, newNode->data.nama);
    cout << "NIM : "; cin >> newNode->data.nim;
    cout << "IPK : "; cin >> newNode->data.ipk;
    newNode->prev = *tail;
    newNode->next = NULL;
    if (*head == NULL && *tail == NULL){
        *head = newNode;
        *tail = newNode;
    } else {
        (*tail)->next = newNode;
        *tail = newNode;
    }
    panjangList++;
    cout << "Data telah tersimpan." << endl;
    system("pause");
}
 
void deleteLast(Node **head, Node **tail) {
    if (*head == NULL && *tail == NULL){
        cout << "LinkedList Kosong" << endl;
        system("pause");
    } else if((*head)->next == NULL){
        Node *del = *head;
        *head = NULL;
        *tail = NULL;
        delete del;
        panjangList--;
        cout << "Data telah terhapus." << endl;
        system("pause");
    } else {
        Node *del;
        del = *tail;    
        *tail = (*tail)->prev;
        (*tail)->next = NULL;
        delete del;
        panjangList--;
        cout << "Data telah terhapus." << endl;
        system("pause");
    }
}
 
int main(){
    Node *HEAD = NULL, *TAIL = NULL;
    int menu = -1;
    while (menu != 0){
        system("cls");
        cout << "\n[ DOUBLE LINKED LIST ]" << endl;
        cout << "Menu:" << endl;
        cout << "1. Tampilkan Data" << endl;
        cout << "2. Tambah Data di Akhir" << endl;
        cout << "3. Hapus Data Terakhir" << endl;
        cout << "4. Tampilkan Data Terakhir" << endl;
        cout << "5. Tambah Data di Awal" << endl;
        cout << "0. Exit" << endl;
        cout << "Menu > "; cin >> menu;
        switch(menu) {
            case 1: show(HEAD); break;
            case 2: insertLast(&HEAD, &TAIL); break;
            case 3: deleteLast(&HEAD, &TAIL); break;
            case 4: showLast(TAIL, panjangList); break;
            case 5: insertFirst(&HEAD, &TAIL); break;
            case 0: continue;
            default: cout << "ERROR: Menu tidak tersedia." << endl; system("pause"); break;
        }
    }
    return 0;
}