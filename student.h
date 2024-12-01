#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <iostream>

typedef struct Student studentInfo;
typedef struct ElmStudent *elmStudent;

struct Student {
    string nidn;
    string name;
    string code;
    string gender;
};

struct ElmStudent {
    studentInfo info;
    elmStudent next;
};

// contract methods

#endif // STUDENT_H_INCLUDED
