#ifndef RELATION_H_INCLUDED
#define RELATION_H_INCLUDED

#include "lecturer.h"
#include "student.h"

struct Relation {
    elmLecturer lecturer;
    elmStudent student;
};

typedef struct Relation relationInfo;
typedef struct ElmRelation *elmRelation;

struct ElmRelation {
    relationInfo info;
    elmRelation next;
};

void createRelationList(elmRelation& head);
elmRelation createNewRelation(elmLecturer lecturer, elmStudent student);
void insertRelation(elmRelation& head, elmRelation newRelation);
void deleteRelation(elmRelation& head, elmLecturer lecturer, elmStudent student);
void showParentWithChild(elmRelation relationList);
void showParentByChild(elmRelation relationList, string nim);
void showChildWithParent(elmRelation head);
void showChildByParent(elmRelation head, string nip);
int countParentsForChild(elmRelation head, const string& nim);
int countChildsForParent(elmRelation head, const string& nip);
void countChildsForAllParent(ListLecturer L, elmRelation head);
int countChildWithoutParent(elmStudent studentList, elmRelation relationList);
void editRelation(elmRelation& head, const string& nim, elmLecturer newLecturer);

#endif
