#include "student.h"

Student::Student(QString studNum) : studentNum(studNum)
{

}

int Student::average()
{
    int sum = 0;
    for(int i = 0; i < results.size(); i++)
    {
        sum += results[i].second;
    }
    int avg = sum/results.size();
    return avg;
}

bool Student::graduate()
{
    int firstYear = 0;
    int secondYear = 0;
    int thirdYear = 0;
    for(int i = 0; i < results.size(); i++)
    {
        QString module = results[i].first;
        QString year = module.at(3);
        int percentage = results[i].second;
        if(percentage >= 50)
        {
            if(year == "1")
            {
                firstYear++;
            }
            else if(year == "2")
            {
                secondYear++;
            }
            else if(year == "3")
            {
                thirdYear++;
            }
        }
    }
    int sum = firstYear + secondYear + thirdYear;
    if(sum >= 5 && firstYear <= 2 && thirdYear >= 1)
        return true;
    else
        return false;
}

bool Student::checkPassedModule(QString mod)
{
    for(int i = 0; i < results.size(); i++)
    {
        QString currentModule = results[i].first;
        int mark = results[i].second;
        if(mod == currentModule)
        {
            if(mark >= 50)
                return true;
        }
    }
    return false;
}

QString Student::getStudNum()
{
    return studentNum;
}

void Student::addModule(QString mod, int mark)
{
    results.append(qMakePair(mod, mark));
}

QString Student::getModules()
{
    QString output;
    for(int i = 0; i < results.size(); i++)
    {
        QString module = results[i].first;
        QString mark = QString::number(results[i].second);
        QString currentModule = QString("Module: %1     Mark: %2").arg(module).arg(mark);

        output.append(currentModule).append("\n");
    }
    return output;
}

QList<QPair<QString, int>> Student::getAllResults()
{
    return results;
}
