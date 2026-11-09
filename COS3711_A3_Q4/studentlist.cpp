#include "studentlist.h"

StudentList* StudentList::onlyInstance = NULL;

StudentList::StudentList()
{

}

StudentList* StudentList::getInstance()
{
    if(onlyInstance == NULL)
    {
        onlyInstance = new StudentList();
    }
    return onlyInstance;
}

void StudentList::addToList(Student *s)
{
    list.append(s);
}

int StudentList::getListSize()
{
    return list.size();
}

Student *StudentList::getStudent(int index)
{
    return list.at(index);
}

int StudentList::checkStudentExists(QString studNum)
{
    for(int i = 0; i < list.size(); i++)
    {
        Student *s = list.at(i);
        if(s->getStudNum() == studNum)
        {
            return i;
        }
    }
    return -1;
}

QString StudentList::studNumList()
{
    if(!list.isEmpty())
    {
        QString studentNumbers;
        for(int i = 0; i < list.size(); i++)
        {
            Student *s = list.at(i);
            studentNumbers.append(s->getStudNum()).append("\n");
        }
        return studentNumbers;
    }
    else
    {
        QString output = QString("The List is empty");
        return output;
    }
}

