#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include "student.h"
#include <QList>
#include <QListIterator>

class StudentList
{
public:
    static StudentList* getInstance();
    void addToList(Student *s);
    int getListSize();
    Student* getStudent(int index);
    int checkStudentExists(QString studNum);
    QString studNumList();

private:
    StudentList();
    static StudentList* onlyInstance;
    QList<Student*> list;
};

#endif // STUDENTLIST_H
