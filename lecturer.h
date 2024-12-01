#ifndef LECTURER_H_INCLUDED
#define LECTURER_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

typedef struct Lecturer lecturerInfo;
typedef struct ElmLecturer *elmLecturer;

struct Lecturer {
    string nidn;
    string name;
    string code;
    string gender;
};

struct ElmLecturer {
    lecturerInfo info;
    elmLecturer next;
};

// contract methods

#endif // LECTURER_H_INCLUDED
