#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <QDomDocument>
#include <QDomElement>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QPair>
#include <QList>
#include "student.h"
#include "studentlist.h"

class FileWriter
{
public:
    FileWriter(StudentList *list);
};

#endif // FILEWRITER_H
