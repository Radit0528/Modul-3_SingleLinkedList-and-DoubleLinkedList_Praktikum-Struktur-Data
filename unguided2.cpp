#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string namaProduk;
    int harga;
    Node *prev;
    Node *next;
};

class DoublyLinkedList
{
public:
    Node *head;
    Node *tail;
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void push(string namaProduk, int harga)
    {
        Node *newNode = new Node;
        newNode->namaProduk = namaProduk;
        newNode->harga = harga;
        newNode->prev = nullptr;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void insertAt(string namaProduk, int harga, int position)
    {
        if (position < 1)
        {
            cout << "Invalid position" << endl;
            return;
        }

        Node *newNode = new Node;
        newNode->namaProduk = namaProduk;
        newNode->harga = harga;
        newNode->prev = nullptr;
        newNode->next = nullptr;

        if (position == 1)
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        else
        {
            Node *current = head;
            int count = 1;
            while (current != nullptr && count < position - 1)
            {
                current = current->next;
                count++;
            }

            if (current == nullptr)
            {
                cout << "Invalid position" << endl;
                return;
            }

            newNode->next = current->next;
            newNode->prev = current;
            if (current->next != nullptr)
            {
                current->next->prev = newNode;
            }
            else
            {
                tail = newNode;
            }
            current->next = newNode;
        }
    }

    void deleteNode(string namaProduk)
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->namaProduk == namaProduk)
            {
                if (current->prev == nullptr)
                {
                    head = current->next;
                }
                else
                {
                    current->prev->next = current->next;
                }
                if (current->next == nullptr)
                {
                    tail = current->prev;
                }
                else
                {
                    current->next->prev = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
        }
        cout << "Data not found" << endl;
    }

    bool update(string oldNamaProduk, string newNamaProduk, int newHarga)
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->namaProduk == oldNamaProduk)
            {
                current->namaProduk = newNamaProduk;
                current->harga = newHarga;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void deleteAll()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    void display()
    {
        Node *current = head;
        cout << "Nama Produk   Harga" << endl;
        while (current != nullptr)
        {
            cout << current->namaProduk << ", " << current->harga << endl;
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    DoublyLinkedList list;
    list.push("Originote", 60000);
    list.push("Somethinc", 150000);
    list.push("Skintific", 100000);
    list.push("Wardah", 50000);
    list.push("Hanasui", 30000);

    while (true)
    {
        cout << "Toko Skincare Purwokerto" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                string namaProduk;
                int harga;
                cout << "Enter nama produk: ";
                cin.ignore();
                getline(cin, namaProduk);
                cout << "Enter harga: ";
                cin >> harga;
                list.push(namaProduk, harga);
                break;
            }
            case 2:
            {
                string namaProduk;
                cout << "Enter nama produk to delete: ";
                cin.ignore();
                getline(cin, namaProduk);
                list.deleteNode(namaProduk);
                break;
            }
            case 3:
            {
                string oldNamaProduk, newNamaProduk;
                int newHarga;
                cout << "Enter nama produk to update: ";
                cin.ignore();
                getline(cin, oldNamaProduk);
                cout << "Enter new nama produk: ";
                getline(cin, newNamaProduk);
                cout << "Enter new harga: ";
                cin >> newHarga;
                bool updated = list.update(oldNamaProduk, newNamaProduk, newHarga);
                if (!updated)
                {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4:
            {
                string namaProduk;
                int harga, position;
                cout << "Enter nama produk to add: ";
                cin.ignore();
                getline(cin, namaProduk);
                cout << "Enter harga: ";
                cin >> harga;
                cout << "Enter position: ";
                cin >> position;
                list.insertAt(namaProduk, harga, position);
                break;
            }
            case 5:
            {
                int position;
                cout << "Enter position to delete: ";
                cin >> position;
                cout << "This functionality is not implemented." << endl;
                break;
            }
            case 6:
            {
                list.deleteAll();
                break;
            }
            case 7:
            {
                list.display();
                break;
            }
            case 8:
            {
                return 0;
            }
            default:
            {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }

    return 0;
}
