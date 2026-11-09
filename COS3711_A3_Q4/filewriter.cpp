#include "filewriter.h"

FileWriter::FileWriter(StudentList *list)
{
    QDomDocument doc;

    QDomElement root = doc.createElement("StudentList");

    doc.appendChild(root);

    for(int i = 0; i < list->getListSize(); i++)
    {
        Student *s = list->getStudent(i);
        QDomElement stud = doc.createElement("Student");
        root.appendChild(stud);
        stud.setAttribute("number", s->getStudNum());
        QList<QPair<QString, int>> currentStudResults = s->getAllResults();
        for(int j = 0; j < currentStudResults.size(); j++)
        {
            QDomElement mod = doc.createElement("Module");
            stud.appendChild(mod);
            mod.setAttribute("Code", currentStudResults[j].first);
            mod.setAttribute("Mark", currentStudResults[j].second);
        }
    }

    QFile file("StudentResultsList.xml");
    if(!file.open(QIODevice::WriteOnly))
    {
        qCritical() << "The file could not be written";
    }
    else
    {
        QTextStream ostream(&file);
        ostream << doc.toString();
        file.close();
        qDebug() << "File Written and finished";
    }
}
