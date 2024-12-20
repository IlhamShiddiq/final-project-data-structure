#include <iostream>
#include "lecturer.h"

using namespace std;

void createListLecturer(ListLecturer &L) {
    First(L) = nullptr;
    Last(L) = nullptr;
}

elmLecturer createElementLecturer(infotypeLecturer dataBaru) {
    elmLecturer P = new ElmLecturer;
    info(P) = dataBaru;
    next(P) = nullptr;
    prev(P) = nullptr;
    return P;
}

void insertLastLecturer(ListLecturer &L, elmLecturer P) {
    if (First(L) == nullptr) {
        First(L) = P;
        Last(L) = P;
    } else {
        next(Last(L)) = P;
        prev(P) = Last(L);
        Last(L) = P;
    }
}

void deleteFirstLecturer(ListLecturer &L, elmLecturer &P) {
    if (First(L) != nullptr) {
        P = First(L);
        if (First(L) == Last(L)) {
            First(L) = nullptr;
            Last(L) = nullptr;
        } else {
            First(L) = next(First(L));
            prev(First(L)) = nullptr;
        }
        next(P) = nullptr;
    }
}

void deleteLastLecturer(ListLecturer &L, elmLecturer &P) {
    if (Last(L) != nullptr) {
        P = Last(L);
        if (First(L) == Last(L)) {
            First(L) = nullptr;
            Last(L) = nullptr;
        } else {
            Last(L) = prev(Last(L));
            next(Last(L)) = nullptr;
        }
        prev(P) = nullptr;
    }
}

void deleteAfterLecturer(ListLecturer &L, elmLecturer Prec, elmLecturer &P) {
    if (Prec != nullptr && next(Prec) != nullptr) {
        P = next(Prec);
        next(Prec) = next(P);
        if (next(P) != nullptr) {
            prev(next(P)) = Prec;
        } else {
            Last(L) = Prec;
        }
        next(P) = nullptr;
        prev(P) = nullptr;
    }
}

void deleteLecturerByNip(ListLecturer &L, elmLecturer &P, string nip) {
    if (First(L) == nullptr) {
        cout << "List kosong" << endl;
    } else {
        elmLecturer Q = First(L);
        elmLecturer Prec = nullptr;

        while (Q != nullptr) {
            if (info(Q).nip == nip) {
                if (Q == First(L)) {
                    deleteFirstLecturer(L, P);
                } else if (Q == Last(L)) {
                    deleteLastLecturer(L, P);
                } else {
                    deleteAfterLecturer(L, Prec, P);
                }
                return;
            }
            Prec = Q;
            Q = next(Q);
        }
    }
}

void printListLecturer(ListLecturer L) {
    if (First(L) == nullptr) {
        cout << "List kosong" << endl;
    } else {
        elmLecturer P = First(L);
        while (P != nullptr) {
            cout << "NIP  : " << info(P).nip << endl;
            cout << "Nama : " << info(P).name << endl;
            cout << "Kode : " << info(P).code << endl;
            cout << "Umur : " << info(P).age << endl;
            cout << "-----------------" << endl;
            P = next(P);
        }
    }
}

void findListLecturerByNip(ListLecturer L, string nip) {
    if (First(L) == nullptr) {
        cout << "List kosong" << endl;
    } else {
        elmLecturer P = First(L);
        bool isExists = false;
        while (P != nullptr) {
            if (info(P).nip == nip) {
                isExists = true;

                cout << "NIP  : " << info(P).nip << endl;
                cout << "Nama : " << info(P).name << endl;
                cout << "Kode : " << info(P).code << endl;
                cout << "Umur : " << info(P).age << endl;
                cout << "-----------------" << endl;
                break;
            }
            P = next(P);
        }

        if (!isExists) cout << "Data tidak ditemukan" << endl;
    }
}

void findListLecturerByName(ListLecturer L, string name) {
    if (First(L) == nullptr) {
        cout << "List kosong" << endl;
    } else {
        elmLecturer P = First(L);
        bool isExists = false;
        while (P != nullptr) {
            if (info(P).name == name) {
                isExists = true;

                cout << "NIP  : " << info(P).nip << endl;
                cout << "Nama : " << info(P).name << endl;
                cout << "Kode : " << info(P).code << endl;
                cout << "Umur : " << info(P).age << endl;
                cout << "-----------------" << endl;
                break;
            }
            P = next(P);
        }

        if (!isExists) cout << "Data tidak ditemukan" << endl;
    }
}

elmLecturer findLecturer(ListLecturer L, string nip) {
    if (First(L) == nullptr) {
        return NULL;
    } else {
        elmLecturer P = First(L);
        while (P != nullptr) {
            if (info(P).nip == nip) {
                return P;
                break;
            }
            P = next(P);
        }
    }
}
