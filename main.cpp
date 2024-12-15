#include <iostream>
#include <cstdlib>

#include "lecturer.h"
#include "student.h"
#include "relation.h"

using namespace std;

ListLecturer L;
elmStudent studentList;
elmRelation relationList;

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

void lecturerDummy()
{
    infotypeLecturer data;
    data.nip = "1001";
    data.name = "Ilham";
    data.code = "ILH";
    data.age = "21";
    elmLecturer newDosen1 = createElementLecturer(data);
    insertLastLecturer(L, newDosen1);

    data.nip = "1002";
    data.name = "Shiddiq";
    data.code = "SHD";
    data.age = "22";
    elmLecturer newDosen2 = createElementLecturer(data);
    insertLastLecturer(L, newDosen2);
}

void studentDummy()
{
    elmStudent newStudent1 = createNewStudent("2001", "Sana", "PJJ", "P");
    insertStudent(studentList, newStudent1);

    elmStudent newStudent2 = createNewStudent("2002", "Yujin", "PJJ", "P");
    insertStudent(studentList, newStudent2);
}

// Menu Dosen Functions
void showMenuInsertDosen()
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

    elmLecturer newDosen = createElementLecturer(data);
    insertLastLecturer(L, newDosen);

    cout << endl << "Data berhasil dimasukkan" << endl;
    pressEnter();
}

void showMenuDeleteDosen()
{
    string nip;
    elmLecturer P;

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

void showMenuFindDosen()
{
    int option;
    string input;

    clearscr();
    cout << "-----------------------------------" << endl;
    cout << "         Aplikasi Pengelola        " << endl;
    cout << "       Tugas Akhir Mahasiswa       " << endl;
    cout << "-----------------------------------" << endl;
    cout << "            Find Dosen             " << endl;
    cout << "-----------------------------------" << endl;
    cout << "1. Cari berdasarkan NIP            " << endl;
    cout << "2. Cari berdasarkan Nama           " << endl;
    cout << "Masukkan Pilihan: ";
    cin >> option;

    if (option == 1) {
        cout << "Masukkan NIP: ";
        cin >> input;
        findListLecturerByNip(L, input);
    } else {
        cout << "Masukkan Nama: ";
        cin >> input;
        findListLecturerByName(L, input);
    }

    pressEnter();
}

void showMenuShowAllDosen()
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

void showMenuDosen()
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
        cout << "1.  Insert Dosen                   " << endl;
        cout << "2.  Delete Dosen                   " << endl;
        cout << "3.  Find Dosen                     " << endl;
        cout << "4.  Show All Dosen                 " << endl;
        cout << "99. Keluar                         " << endl;
        cout << "Masukkan nomor menu: ";
        cin >> input;

        if (input == 1) showMenuInsertDosen();
        else if (input == 2) showMenuDeleteDosen();
        else if (input == 3) showMenuFindDosen();
        else if (input == 4) showMenuShowAllDosen();

    } while (input == 99);
}

// Menu Mahasiswa Functions
void showMenuInsertMahasiswa()
{
    string nim, name, code, gender;

    clearscr();
    cout << "-----------------------------------" << endl;
    cout << "         Aplikasi Pengelola        " << endl;
    cout << "       Tugas Akhir Mahasiswa       " << endl;
    cout << "-----------------------------------" << endl;
    cout << "         Insert Mahasiswa          " << endl;
    cout << "-----------------------------------" << endl;
    cout << "Masukkan NIM: ";
    cin >> nim;
    cout << "Masukkan Nama: ";
    cin >> name;
    cout << "Masukkan Kode Prodi: ";
    cin >> code;
    cout << "Masukkan Gender: ";
    cin >> gender;

    elmStudent newStudent = createNewStudent(nim, name, code, gender);
    insertStudent(studentList, newStudent);

    cout << endl << "Data berhasil dimasukkan" << endl;
    pressEnter();
}

void showMenuDeleteMahasiswa()
{
    string nim;

    clearscr();
    cout << "-----------------------------------" << endl;
    cout << "         Aplikasi Pengelola        " << endl;
    cout << "       Tugas Akhir Mahasiswa       " << endl;
    cout << "-----------------------------------" << endl;
    cout << "         Delete Mahasiswa          " << endl;
    cout << "-----------------------------------" << endl;
    cout << "Masukkan NIM: ";
    cin >> nim;

    deleteStudent(studentList, nim);

    pressEnter();
}

void showMenuFindMahasiswa()
{
    int option;
    string input;

    clearscr();
    cout << "-----------------------------------" << endl;
    cout << "         Aplikasi Pengelola        " << endl;
    cout << "       Tugas Akhir Mahasiswa       " << endl;
    cout << "-----------------------------------" << endl;
    cout << "          Find Mahasiswa           " << endl;
    cout << "-----------------------------------" << endl;
    cout << "1. Cari berdasarkan NIM            " << endl;
    cout << "2. Cari berdasarkan Nama           " << endl;
    cout << "Masukkan Pilihan: ";
    cin >> option;

    if (option == 1) {
        cout << "Masukkan NIM: ";
        cin >> input;
        findStudentByNim(studentList, input);
    } else {
        cout << "Masukkan Nama: ";
        cin >> input;
        findStudentByName(studentList, input);
    }

    pressEnter();
}

void showMenuShowAllMahasiswa()
{
    string nip;

    clearscr();
    cout << "-----------------------------------" << endl;
    cout << "         Aplikasi Pengelola        " << endl;
    cout << "       Tugas Akhir Mahasiswa       " << endl;
    cout << "-----------------------------------" << endl;
    cout << "         Show All Mahasiswa        " << endl;
    cout << "-----------------------------------" << endl;

    showAllStudents(studentList);

    cout << endl;
    pressEnter();
}

void showMenuMahasiswa()
{
    int input;

    do {
        clearscr();
        cout << "-----------------------------------" << endl;
        cout << "         Aplikasi Pengelola        " << endl;
        cout << "       Tugas Akhir Mahasiswa       " << endl;
        cout << "-----------------------------------" << endl;
        cout << "          Menu Mahasiswa           " << endl;
        cout << "-----------------------------------" << endl;
        cout << "1.  Insert Mahasiswa               " << endl;
        cout << "2.  Delete Mahasiswa               " << endl;
        cout << "3.  Find Mahasiswa                 " << endl;
        cout << "4.  Show All Mahasiswa             " << endl;
        cout << "Masukkan nomor menu: ";
        cin >> input;

        if (input == 1) showMenuInsertMahasiswa();
        else if (input == 2) showMenuDeleteMahasiswa();
        else if (input == 3) showMenuFindMahasiswa();
        else if (input == 4) showMenuShowAllMahasiswa();

    } while (input == 99);


}

// Menu Relasi Functions
void showMenuInsertRelasi()
{
    string nip, nim;

    clearscr();
    cout << "-----------------------------------" << endl;
    cout << "         Aplikasi Pengelola        " << endl;
    cout << "       Tugas Akhir Mahasiswa       " << endl;
    cout << "-----------------------------------" << endl;
    cout << "           Insert Relasi           " << endl;
    cout << "-----------------------------------" << endl;
    cout << "Masukkan NIP dosen: ";
    cin >> nip;
    cout << "Masukkan NIM mahasiswa: ";
    cin >> nim;

    elmLecturer lecturer = findLecturer(L, nip);
    elmStudent student = findStudent(studentList, nim);

    if (lecturer == NULL || student == NULL) {
        cout << "\nDosen atau Mahasiswa tidak ditemukan.\n";
    } else {
        elmRelation newRelation = createNewRelation(lecturer, student);
        insertRelation(relationList, newRelation);
        cout << "\nRelasi berhasil ditambahkan.\n";
    }

    pressEnter();
}

void showMenuDeleteRelasi()
{
    string nip, nim;

    clearscr();
    cout << "-----------------------------------" << endl;
    cout << "         Aplikasi Pengelola        " << endl;
    cout << "       Tugas Akhir Mahasiswa       " << endl;
    cout << "-----------------------------------" << endl;
    cout << "           Delete Relasi           " << endl;
    cout << "-----------------------------------" << endl;
    cout << "Masukkan NIP dosen: ";
    cin >> nip;
    cout << "Masukkan NIM mahasiswa: ";
    cin >> nim;

    elmLecturer lecturer = findLecturer(L, nip);
    elmStudent student = findStudent(studentList, nim);

    if (lecturer == NULL || student == NULL) {
        cout << "\nDosen atau Mahasiswa tidak ditemukan.\n";
    } else {
        deleteRelation(relationList, lecturer, student);
        cout << "\nRelasi berhasil dihapus.\n";
    }

    pressEnter();
}

void showMenuShowRelasiAllParent()
{
    clearscr();
    cout << "-----------------------------------" << endl;
    cout << "         Aplikasi Pengelola        " << endl;
    cout << "       Tugas Akhir Mahasiswa       " << endl;
    cout << "-----------------------------------" << endl;
    cout << "       Show All Relasi Parent      " << endl;
    cout << "-----------------------------------" << endl;

    showParentWithChild(relationList);
    pressEnter();
}

void showMenuShowRelasiByParent()
{
    string nip;

    clearscr();
    cout << "-----------------------------------" << endl;
    cout << "         Aplikasi Pengelola        " << endl;
    cout << "       Tugas Akhir Mahasiswa       " << endl;
    cout << "-----------------------------------" << endl;
    cout << "       Show All Relasi Parent      " << endl;
    cout << "-----------------------------------" << endl;
    cout << "Masukkan NIP dosen: ";
    cin >> nip;

    showChildByParent(relationList, nip);
    pressEnter();
}

void showMenuShowRelasiAllChild()
{
    clearscr();
    cout << "-----------------------------------" << endl;
    cout << "         Aplikasi Pengelola        " << endl;
    cout << "       Tugas Akhir Mahasiswa       " << endl;
    cout << "-----------------------------------" << endl;
    cout << "       Show All Relasi Child       " << endl;
    cout << "-----------------------------------" << endl;

    showChildWithParent(relationList);
    pressEnter();
}

void showMenuShowRelasiByChild()
{
    string nim;

    clearscr();
    cout << "-----------------------------------" << endl;
    cout << "         Aplikasi Pengelola        " << endl;
    cout << "       Tugas Akhir Mahasiswa       " << endl;
    cout << "-----------------------------------" << endl;
    cout << "       Show All Relasi Child       " << endl;
    cout << "-----------------------------------" << endl;
    cout << "Masukkan NIM mahasiswa: ";
    cin >> nim;

    showParentByChild(relationList, nim);
    pressEnter();
}

void showMenuCountRelasiDosen()
{
    string nim;

    clearscr();
    cout << "-----------------------------------" << endl;
    cout << "         Aplikasi Pengelola        " << endl;
    cout << "       Tugas Akhir Mahasiswa       " << endl;
    cout << "-----------------------------------" << endl;
    cout << "       Count Relasi All Dosen      " << endl;
    cout << "-----------------------------------" << endl;
    countChildsForAllParent(L, relationList);
    pressEnter();
}

void showMenuCountRelasiMahasiswa()
{
    string nim;

    clearscr();
    cout << "-----------------------------------" << endl;
    cout << "         Aplikasi Pengelola        " << endl;
    cout << "       Tugas Akhir Mahasiswa       " << endl;
    cout << "-----------------------------------" << endl;
    cout << "       Count Relasi Mahasiswa      " << endl;
    cout << "-----------------------------------" << endl;
    cout << "Masukkan NIM mahasiswa: ";
    cin >> nim;

    int parentCount = countParentsForChild(relationList, nim);
    cout << "Mahasiswa dengan NIM " << nim << " memiliki " << parentCount << " parent.\n";
    pressEnter();
}

void showMenuCountNonRelasiMahasiswa()
{
    clearscr();
    cout << "-----------------------------------" << endl;
    cout << "         Aplikasi Pengelola        " << endl;
    cout << "       Tugas Akhir Mahasiswa       " << endl;
    cout << "-----------------------------------" << endl;
    cout << "     Count Non Relasi Mahasiswa    " << endl;
    cout << "-----------------------------------" << endl;

    int nonRelasiCount = countChildWithoutParent(studentList, relationList);
    cout << "Jumlah mahasiswa yang tak berelasi: " << nonRelasiCount << endl;
    pressEnter();
}

void showMenuEditRelasiMahasiswa()
{
    string nip, nim;

    clearscr();
    cout << "-----------------------------------" << endl;
    cout << "         Aplikasi Pengelola        " << endl;
    cout << "       Tugas Akhir Mahasiswa       " << endl;
    cout << "-----------------------------------" << endl;
    cout << "       Edit Relasi Mahasiswa       " << endl;
    cout << "-----------------------------------" << endl;
    cout << "Masukkan NIM mahasiswa: ";
    cin >> nim;
    cout << "Masukkan NIP dosen yang baru: ";
    cin >> nip;

    elmLecturer lecturer = findLecturer(L, nip);

    if (lecturer == NULL) {
        cout << "\nDosentidak ditemukan.\n";
    } else {
        editRelation(relationList, nim, lecturer);
    }
    pressEnter();
}

void showMenuRelasi()
{
    int input;

    do {
        clearscr();
        cout << "-----------------------------------" << endl;
        cout << "         Aplikasi Pengelola        " << endl;
        cout << "       Tugas Akhir Mahasiswa       " << endl;
        cout << "-----------------------------------" << endl;
        cout << "            Menu Relasi            " << endl;
        cout << "-----------------------------------" << endl;
        cout << "1.  Insert Relasi                  " << endl;
        cout << "2.  Delete Relasi                  " << endl;
        cout << "3.  Show Relasi All Parent         " << endl;
        cout << "4.  Show Relasi By Parent          " << endl;
        cout << "5.  Show Relasi All Child          " << endl;
        cout << "6.  Show Relasi By Child           " << endl;
        cout << "7.  Count Relasi All Dosen         " << endl;
        cout << "8.  Count Relasi Mahasiswa         " << endl;
        cout << "9.  Count Non Relasi Mahasiswa     " << endl;
        cout << "10. Edit Relasi Mahasiswa          " << endl;
        cout << "99. Keluar                         " << endl;
        cout << "Masukkan nomor menu: ";
        cin >> input;

        if (input == 1) showMenuInsertRelasi();
        else if (input == 2)showMenuDeleteRelasi();
        else if (input == 3) showMenuShowRelasiAllParent();
        else if (input == 4) showMenuShowRelasiByParent();
        else if (input == 5) showMenuShowRelasiAllChild();
        else if (input == 6) showMenuShowRelasiByChild();
        else if (input == 7) showMenuCountRelasiDosen();
        else if (input == 8) showMenuCountRelasiMahasiswa();
        else if (input == 9) showMenuCountNonRelasiMahasiswa();
        else if (input == 10) showMenuEditRelasiMahasiswa();

    } while (input == 99);
}

int main()
{
    createListLecturer(L);
    lecturerDummy();
    studentDummy();

    int inputMenu;

    do {
        showMenu();
        askMenu(inputMenu);

        if (inputMenu == 1) showMenuDosen();
        else if (inputMenu == 2) showMenuMahasiswa();
        else if (inputMenu == 3) showMenuRelasi();

    } while (inputMenu != 99);

    return 0;
}
