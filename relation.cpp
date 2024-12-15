#include "relation.h"

void createRelationList(elmRelation& head) {
    head = NULL;
}

elmRelation createNewRelation(elmLecturer lecturer, elmStudent student) {
    elmRelation newRelation = new ElmRelation;
    newRelation->info.lecturer = lecturer;
    newRelation->info.student = student;
    newRelation->next = NULL;
    return newRelation;
}

void insertRelation(elmRelation& head, elmRelation newRelation) {
    if (head == NULL) {
        head = newRelation;
    } else {
        elmRelation temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newRelation; // Menambahkan elemen di akhir
    }
}

void deleteRelation(elmRelation& head, elmLecturer lecturer, elmStudent student) {
    if (head == NULL) {
        cout << "List relasi kosong.\n";
        return;
    }

    elmRelation prev = NULL, current = head;
    while (current != NULL &&
           (current->info.lecturer != lecturer || current->info.student != student)) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        cout << "Relasi tidak ditemukan.\n";
        return;
    }

    if (prev == NULL) {
        head = current->next; // Hapus elemen pertama
    } else {
        prev->next = current->next; // Hapus elemen di tengah/akhir
    }

    delete current;
    cout << "Relasi berhasil dihapus.\n";
}

void showParentWithChild(elmRelation head) {
    if (head == NULL) {
        cout << "Tidak ada relasi.\n";
        return;
    }

    elmRelation temp = head;
    while (temp != NULL) {
        cout << "Dosen: " << temp->info.lecturer->info.name
             << " - Mahasiswa: " << temp->info.student->info.name << endl;
        temp = temp->next;
    }
}

void showParentByChild(elmRelation head, string nim) {
    if (head == NULL) {
        cout << "Tidak ada relasi.\n";
        return;
    }

    elmRelation temp = head;
    while (temp != NULL) {
        if (temp->info.student->info.nim == nim) {
            cout << "Dosen: " << temp->info.lecturer->info.name << endl;
        }
        temp = temp->next;
    }
}

void showChildWithParent(elmRelation head) {
    if (head == NULL) {
        cout << "Tidak ada relasi yang tersedia.\n";
        return;
    }

    elmRelation current = head;
    while (current != NULL) {
        cout << "Mahasiswa: " << current->info.student->info.name
             << " - Dosen: " << current->info.lecturer->info.name << endl;
        current = current->next;
    }
}

void showChildByParent(elmRelation head, string nip) {
    if (head == NULL) {
        cout << "Tidak ada relasi yang tersedia.\n";
        return;
    }

    elmRelation current = head;
    while (current != NULL) {
        if (current->info.lecturer->info.nip == nip) {
            cout << "Mahasiswa: " << current->info.student->info.name << endl;
        }
        current = current->next;
    }
}

int countParentsForChild(elmRelation head, const string& nim) {
    int count = 0;
    elmRelation current = head;
    while (current != NULL) {
        if (current->info.student->info.nim == nim) {
            count++;
        }
        current = current->next;
    }
    return count;
}

int countChildsForParent(elmRelation head, const string& nip) {
    int count = 0;
    elmRelation current = head;
    while (current != NULL) {
        if (current->info.lecturer->info.nip == nip) {
            count++;
        }
        current = current->next;
    }
    return count;
}

void countChildsForAllParent(ListLecturer L, elmRelation head) {
    elmLecturer current = First(L);
    while (current != nullptr) {
        int countRelation = countChildsForParent(head, info(current).nip);
        cout << "NIP  : " << info(current).nip << endl;
        cout << "Nama : " << info(current).name << endl;
        cout << "Kode : " << info(current).code << endl;
        cout << "Umur : " << info(current).age << endl;
        cout << "Count Relasi: " << countRelation << endl;
        cout << "-----------------" << endl;
        current = next(current);
    }
}

int countChildWithoutParent(elmStudent studentList, elmRelation relationList) {
    int count = 0;
    elmStudent currentStudent = studentList;

    while (currentStudent != NULL) {
        bool hasParent = false;

        elmRelation currentRelation = relationList;
        while (currentRelation != NULL) {
            if (currentRelation->info.student == currentStudent) {
                hasParent = true;
                break;
            }
            currentRelation = currentRelation->next;
        }

        if (!hasParent) {
            count++;
        }

        currentStudent = currentStudent->next;
    }

    return count;
}

void editRelation(elmRelation& head, const string& nim, elmLecturer newLecturer) {
    elmRelation current = head;
    while (current != NULL) {
        if (current->info.student->info.nim == nim) {
            current->info.lecturer = newLecturer; // Mengganti dosen
            cout << "Relasi berhasil diperbarui.\n";
            return;
        }
        current = current->next;
    }
    cout << "Relasi untuk mahasiswa dengan NIM " << nim << " tidak ditemukan.\n";
}
