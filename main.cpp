#include <iostream>
#include <stdlib.h> // menggunakan system("cls")
#include <conio.h> // menggunakan getch()
#define MAX 10 // batas stack yang ingin dibuat, boleh lebih
using namespace std;
// Node stack
struct Node {
    int data;
    Node* next;
};

// Fungsi untuk menambah elemen di stack
void push(Node*& top, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    cout << value << " telah ditambahkan ke stack." << endl;
}

// Fungsi untuk menghapus elemen dari stack
void pop(Node*& top) {
    if (top == nullptr) {
        cout << "Stack kosong, tidak ada yang dapat dihapus." << endl;
        return;
    }
    Node* temp = top;
    top = top->next;
    cout << temp->data << " telah dihapus dari stack." << endl;
    delete temp;
}

// Fungsi untuk melihat elemen teratas di stack
int peek(Node* top) {
    if (top == nullptr) {
        cout << "Stack kosong." << endl;
        return -1;
    }
    return top->data;
}

// Fungsi untuk mengecek apakah stack kosong
bool isEmpty(Node* top) {
    return top == nullptr;
}

// Fungsi untuk menampilkan seluruh elemen stack
void displayStack(Node* top) {
    if (isEmpty(top)) {
        cout << "Stack kosong." << endl;
        return;
    }
    Node* temp = top;
    cout << "Isi stack: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* top = nullptr; // Inisialisasi stack kosong
    int choice, value;

    do {
        cout << "\nMenu Stack Linked List:" << endl;
        cout << "1. Push (Tambah Elemen)" << endl;
        cout << "2. Pop (Hapus Elemen Teratas)" << endl;
        cout << "3. Peek (Lihat Elemen Teratas)" << endl;
        cout << "4. Display (Tampilkan Semua Elemen)" << endl;
        cout << "5. Exit (Keluar)" << endl;
        cout << "Pilih operasi: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan nilai untuk push: ";
                cin >> value;
                push(top, value);
                break;
            case 2:
                pop(top);
                break;
            case 3:
                if (!isEmpty(top)) {
                    cout << "Elemen teratas: " << peek(top) << endl;
                }
                break;
            case 4:
                displayStack(top);
                break;
            case 5:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid, coba lagi." << endl;
        }
    } while (choice != 5);

    return 0;
}
