#include <iostream>
#include <string>
using namespace std;
struct Node
{
    string nama;
    int usia;
    Node *next;
};
class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }
    void insertDepan(string nama, int usia)
    {
        Node *baru = new Node;
        baru->nama = nama;
        baru->usia = usia;
        baru->next = head;
        head = baru;
    }
    void insertBelakang(string nama, int usia)
    {
        Node *baru = new Node;
        baru->nama = nama;
        baru->usia = usia;
        baru->next = nullptr;
        if (head == nullptr)
        {
            head = baru;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = baru;
        }
    }
    void insertTengah(string nama, int usia, int posisi)
    {
        if (posisi < 1)
        {
            cout << "Posisi tidak valid" << endl;
            return;
        }
        if (posisi == 1)
        {
            insertDepan(nama, usia);
            return;
        }
        Node *baru = new Node;
        baru->nama = nama;
        baru->usia = usia;
        Node *temp = head;
        for (int i = 1; i < posisi - 1 && temp != nullptr; i++)
        {
            temp = temp->next;
        }
        if (temp == nullptr)
        {
            cout << "Posisi tidak valid" << endl;
            return;
        }
        baru->next = temp->next;
        temp->next = baru;
    }
    void hapus(string nama)
    {
        if (head == nullptr)
        {
            cout << "List kosong!" << endl;
            return;
        }
        if (head->nama == nama)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr && temp->next->nama != nama)
        {
            temp = temp->next;
        }
        if (temp->next == nullptr)
        {
            cout << "Data tidak ditemukan" << endl;
            return;
        }
        Node *hapus = temp->next;
        temp->next = temp->next->next;
        delete hapus;
    }
    void ubah(string namaLama, string namaBaru, int usiaBaru)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->nama == namaLama)
            {
                temp->nama = namaBaru;
                temp->usia = usiaBaru;
                return;
            }
            temp = temp->next;
        }
        cout << "Data tidak ditemukan" << endl;
    }
    void tampil()
    {
        if (head == nullptr)
        {
            cout << "List kosong!" << endl;
            return;
        }
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->nama << " " << temp->usia << endl;
            temp = temp->next;
        }
    }
};
int main()
{
    LinkedList list;
    string namaAnda;
    int usiaAnda;
    cout << "Masukkan nama anda: ";
    getline(cin, namaAnda);
    cout << "Masukkan usia anda: ";
    cin >> usiaAnda;
    cin.ignore();
    list.insertDepan(namaAnda, usiaAnda);

    list.insertBelakang("John", 19);
    list.insertBelakang("Jane", 20);
    list.insertBelakang("Michael", 18);
    list.insertBelakang("Yusuke", 19);
    list.insertBelakang("Akechi", 20);
    list.insertBelakang("Hoshino", 18);
    list.insertBelakang("Karin", 18);

    cout << "Data awal:" << endl;
    list.tampil();
    
    list.hapus("Akechi");
    list.insertTengah("Futaba", 18, 3);
    list.insertDepan("Igor", 20);
    list.ubah("Michael", "Reyn", 18);
    cout << "\nData setelah operasi:" << endl;
    list.tampil();
    return 0;
}
