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
typedef struct ElmLecturer *elmLecturer;

struct ElmLecturer {
    infotypeLecturer info;
    elmLecturer next;
    elmLecturer prev;
};

struct ListLecturer {
    elmLecturer First;
    elmLecturer Last;
};

void createListLecturer(ListLecturer &L);
elmLecturer createElementLecturer(infotypeLecturer dataBaru);
void insertLastLecturer(ListLecturer &L, elmLecturer P);
void deleteFirstLecturer(ListLecturer &L, elmLecturer &P);
void deleteLastLecturer(ListLecturer &L, elmLecturer &P);
void deleteAfterLecturer(ListLecturer &L, elmLecturer Prec, elmLecturer &P);
void deleteLecturerByNip(ListLecturer &L, elmLecturer &P, string nip);
void printListLecturer(ListLecturer L);
void findListLecturerByNip(ListLecturer L, string nip);
void findListLecturerByName(ListLecturer L, string name);
elmLecturer findLecturer(ListLecturer L, string nip);

#endif // LECTURER_H_INCLUDED
