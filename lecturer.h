#ifndef LECTURER_H_INCLUDED
#define LECTURER_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

#define First(L) ((L).First)
#define Last(L) ((L).Last)
#define info(P) ((P)->info)
#define next(P) ((P)->next)
#define prev(P) ((P)->prev)

using namespace std;

struct Lecturer {
    string nip;
    string name;
    string code;
    string age;
};

typedef struct Lecturer infotypeLecturer;
typedef struct ElmLecturer *address;

struct ElmLecturer {
    infotypeLecturer info;
    address next;
    address prev;
};

struct ListLecturer {
    address First;
    address Last;
};

void createListLecturer(ListLecturer &L);
address createElementLecturer(infotypeLecturer dataBaru);
void insertLastLecturer(ListLecturer &L, address P);
void deleteFirstLecturer(ListLecturer &L, address &P);
void deleteLastLecturer(ListLecturer &L, address &P);
void deleteAfterLecturer(ListLecturer &L, address Prec, address &P);
void deleteLecturerByNip(ListLecturer &L, address &P, string nip);
void printListLecturer(ListLecturer L);
void findListLecturer(ListLecturer L, string nip);

#endif // LECTURER_H_INCLUDED
