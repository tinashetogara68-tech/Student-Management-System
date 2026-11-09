#ifndef STUDENT_H
#define STUDENT_H

#include <QPair>
#include <QString>
#include <QList>
#include <QChar>


class Student
{
public:
    Student(QString studNum);
    int average();
    bool graduate();
    bool checkPassedModule(QString mod);
    QString getStudNum();
    void addModule(QString mod, int mark);
    QString getModules();
    QList<QPair<QString, int>> getAllResults();

private:
    QString studentNum;
    QList<QPair<QString, int>> results;
};

#endif // STUDENT_H
