#include <iostream>
#include <cstdlib>
#include "lecturer.h"

using namespace std;

void clearscr()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pressEnter()
{
    cout << "Tekan Enter untuk kembali ke menu...";
    cin.ignore();
    cin.get();

    clearscr();
}

// Menu Utama Functions
void showMenu()
{
    cout << "-----------------------------------" << endl;
    cout << "         Aplikasi Pengelola        " << endl;
    cout << "       Tugas Akhir Mahasiswa       " << endl;
    cout << "-----------------------------------" << endl;
    cout << "            Menu Utama             " << endl;
    cout << "-----------------------------------" << endl;
    cout << "1.  Menu Dosen                     " << endl;
    cout << "2.  Menu Mahasiswa                 " << endl;
    cout << "3.  Menu Relasi                    " << endl;
    cout << "99. Keluar                         " << endl;
}

void askMenu(int &input)
{
    cout << "Masukkan nomor menu: ";
    cin >> input;
}

// Menu Dosen Functions
void showMenuInsertDosen(ListLecturer &L)
{
    infotypeLecturer data;
    string nip, nama, kode;
    int umur;

    clearscr();
    cout << "-----------------------------------" << endl;
    cout << "         Aplikasi Pengelola        " << endl;
    cout << "       Tugas Akhir Mahasiswa       " << endl;
    cout << "-----------------------------------" << endl;
    cout << "           Insert Dosen            " << endl;
    cout << "-----------------------------------" << endl;
    cout << "Masukkan NIP: ";
    cin >> data.nip;
    cout << "Masukkan Nama: ";
    cin >> data.name;
    cout << "Masukkan Kode: ";
    cin >> data.code;
    cout << "Masukkan Umur: ";
    cin >> data.age;

    address newDosen = createElementLecturer(data);
    insertLastLecturer(L, newDosen);

    cout << endl << "Data berhasil dimasukkan" << endl;
    pressEnter();
}

void showMenuDeleteDosen(ListLecturer &L)
{
    string nip;
    address P;

    clearscr();
    cout << "-----------------------------------" << endl;
    cout << "         Aplikasi Pengelola        " << endl;
    cout << "       Tugas Akhir Mahasiswa       " << endl;
    cout << "-----------------------------------" << endl;
    cout << "           Delete Dosen            " << endl;
    cout << "-----------------------------------" << endl;
    cout << "Masukkan NIP: ";
    cin >> nip;

    deleteLecturerByNip(L, P, nip);

    pressEnter();
}

void showMenuFindDosen(ListLecturer L)
{
    string nip;

    clearscr();
    cout << "-----------------------------------" << endl;
    cout << "         Aplikasi Pengelola        " << endl;
    cout << "       Tugas Akhir Mahasiswa       " << endl;
    cout << "-----------------------------------" << endl;
    cout << "            Find Dosen             " << endl;
    cout << "-----------------------------------" << endl;
    cout << "Masukkan NIP: ";
    cin >> nip;

    findListLecturer(L, nip);

    pressEnter();
}

void showMenuShowAllDosen(ListLecturer L)
{
    string nip;

    clearscr();
    cout << "-----------------------------------" << endl;
    cout << "         Aplikasi Pengelola        " << endl;
    cout << "       Tugas Akhir Mahasiswa       " << endl;
    cout << "-----------------------------------" << endl;
    cout << "           Show All Dosen          " << endl;
    cout << "-----------------------------------" << endl;

    printListLecturer(L);

    cout << endl;
    pressEnter();
}

void showMenuDosen(ListLecturer &L)
{
    int input;

    do {
        clearscr();
        cout << "-----------------------------------" << endl;
        cout << "         Aplikasi Pengelola        " << endl;
        cout << "       Tugas Akhir Mahasiswa       " << endl;
        cout << "-----------------------------------" << endl;
        cout << "            Menu Dosen             " << endl;
        cout << "-----------------------------------" << endl;
        cout << "1.  Insert Dosen               " << endl;
        cout << "2.  Delete Dosen               " << endl;
        cout << "3.  Find Dosen                 " << endl;
        cout << "4.  Show All Dosen             " << endl;
        cout << "Masukkan nomor menu: ";
        cin >> input;

        if (input == 1) showMenuInsertDosen(L);
        else if (input == 2) showMenuDeleteDosen(L);
        else if (input == 3) showMenuFindDosen(L);
        else if (input == 4) showMenuShowAllDosen(L);

    } while (input == 99);
}

// Menu Mahasiswa Functions
void showMenuMahasiswa()
{
    clearscr();
    cout << "-----------------------------------" << endl;
    cout << "         Aplikasi Pengelola        " << endl;
    cout << "       Tugas Akhir Mahasiswa       " << endl;
    cout << "-----------------------------------" << endl;
    cout << "          Menu Mahasiswa           " << endl;
    cout << "-----------------------------------" << endl;
    cout << "99. Keluar                     " << endl;
}

// Menu Relasi Functions
void showMenuRelasi()
{
    clearscr();
    cout << "-----------------------------------" << endl;
    cout << "         Aplikasi Pengelola        " << endl;
    cout << "       Tugas Akhir Mahasiswa       " << endl;
    cout << "-----------------------------------" << endl;
    cout << "            Menu Relasi            " << endl;
    cout << "-----------------------------------" << endl;
    cout << "99. Keluar                     " << endl;
}

int main()
{
    ListLecturer L;
    createListLecturer(L);

    int inputMenu;

    do {
        showMenu();
        askMenu(inputMenu);

        if (inputMenu == 1) showMenuDosen(L);
        else if (inputMenu == 2) showMenuMahasiswa();
        else if (inputMenu == 3) showMenuRelasi();

    } while (inputMenu != 99);

    return 0;
}
