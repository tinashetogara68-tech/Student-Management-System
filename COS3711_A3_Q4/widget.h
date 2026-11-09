#ifndef WIDGET_H
#define WIDGET_H

#include <QCoreApplication>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QProcess>
#include <QGridLayout>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QByteArray>
#include <QStringList>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include "filewriter.h"
#include "student.h"
#include "studentlist.h"


class widget : public QWidget
{
    Q_OBJECT

public:
    widget(QWidget *parent = nullptr);
    ~widget();
    void createGUI();
    QStringList processStudentDetails(QString deets);
    QString toString(Student *s);

private:
    QLineEdit *studNumInput;
    QPushButton *findStud;
    QPushButton *processButton;
    QPlainTextEdit *textDisplayer;
    QProcess *process;
    StudentList *container;
    Student *currentStudent;
    FileWriter *writer;
public slots:
    void createProcess();
    void showStarted();
    void processError();
    void retrieveStudentData();
    void writeXMLFile();

};

#endif // WIDGET_H
