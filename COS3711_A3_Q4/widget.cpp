#include "widget.h"

widget::widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Student Details Processor");
    createGUI();

    container = StudentList::getInstance();

    process = new QProcess(this);

    connect(processButton, &QPushButton::clicked, this, &widget::createProcess);
    connect(process, &QProcess::errorOccurred, this, &widget::processError);
    connect(process, &QProcess::readyReadStandardOutput, this, &widget::showStarted);
    connect(findStud, &QPushButton::clicked, this, &widget::retrieveStudentData);
    connect(qApp, &QCoreApplication::aboutToQuit, this, &widget::writeXMLFile);
}

widget::~widget()
{
}

void widget::createGUI()
{
    QLabel *studNumLabel = new QLabel("Enter Student Number to Find");
    studNumInput = new QLineEdit();
    QRegularExpression studNumRE("^[0-9]{4}$");
    QValidator *studNumVal = new QRegularExpressionValidator(studNumRE, this);
    studNumInput->setValidator(studNumVal);

    processButton = new QPushButton("Create Process");
    findStud = new QPushButton("Find Student");
    textDisplayer = new QPlainTextEdit();
    QGridLayout *grid = new QGridLayout();

    grid->addWidget(processButton, 0, 0, 1, 2);
    grid->addWidget(textDisplayer, 1, 0, 1, 2);
    grid->addWidget(studNumLabel, 2, 0);
    grid->addWidget(studNumInput, 2, 1);
    grid->addWidget(findStud, 3, 0, 1, 2);

    setLayout(grid);
    textDisplayer->setPlaceholderText("Click \"Create Process\" to enter Student Details. Then enter that student number below to return all available data on that student.");
}

QStringList widget::processStudentDetails(QString deets)
{
    QStringList processedDetails = deets.split(QRegularExpression("\\s+"));
    processedDetails.removeAll("Student");
    processedDetails.removeAll("Number:");
    processedDetails.removeAll("Code:");
    processedDetails.removeAll("");
    processedDetails.removeAll("Mark:");
    processedDetails.removeAll("Module");
    return processedDetails;

    //First position of list is now student number. Second is Module Code. Third is mark
}

QString widget::toString(Student *s)
{
    QString mark = QString::number(s->average());
    QString gradStatus;
    if(s->graduate() == false)
    {
        gradStatus = QString("Average: %1\tNot Elligible for Graduation").arg(mark).append("\n");
    }
    else
    {
        gradStatus = QString("Average: %1\tStudent Elligble for Graduation").arg(mark).append("\n");
    }
    return gradStatus;
}

void widget::createProcess()
{
    QString processPath = QString(SOURCE_DIR) + "/GetStudent.exe";
    process->start(processPath);
}

void widget::showStarted()
{
    QByteArray studDetails = process->readAllStandardOutput();
    QString details = QString::fromUtf8(studDetails);
    QStringList updatedDetails = processStudentDetails(details);

    if(container->checkStudentExists(updatedDetails.at(0)) == -1)
    {

        currentStudent = new Student(updatedDetails.at(0));
        currentStudent->addModule(updatedDetails.at(1), updatedDetails.at(2).toInt());
        container->addToList(currentStudent);

        QString output = QString("Student %1 created.\nAchieved %2% in %3").arg(updatedDetails.at(0)).arg(updatedDetails.at(2)).arg(updatedDetails.at(1));
        textDisplayer->appendPlainText(output);
    }
    else
    {
        currentStudent = container->getStudent(container->checkStudentExists(updatedDetails.at(0)));
        if(currentStudent->checkPassedModule(updatedDetails.at(1)) == true)
        {
            textDisplayer->appendPlainText("Student has already completed that module");
        }
        else
        {
            currentStudent->addModule(updatedDetails.at(1), updatedDetails.at(2).toInt());

            QString output = QString("Student %1 already Exists.\nModule %2 added with %3% achieved").arg(updatedDetails.at(0)).arg(updatedDetails.at(1)).arg(updatedDetails.at(2));
            textDisplayer->appendPlainText(output);
        }
    }

    qDebug() << updatedDetails.size();
    qDebug() << container->getListSize();
}

void widget::processError()
{
    textDisplayer->setPlainText("There was an error with the process");
}

void widget::retrieveStudentData()
{
    QString checkStudNum = studNumInput->text();
    if(container->checkStudentExists(checkStudNum) == -1)
    {
        QString noStudent = QString("The student was not found. There are %1 students in the list: \n%2").arg(container->getListSize()).arg(container->studNumList());
        textDisplayer->appendPlainText(noStudent);
    }
    else
    {
        int indexPos = container->checkStudentExists(checkStudNum);
        currentStudent = container->getStudent(indexPos);

        QString fullStudentDetails;
        fullStudentDetails.append(toString(currentStudent)).append(currentStudent->getModules());
        textDisplayer->setPlainText(fullStudentDetails);
    }
}

void widget::writeXMLFile()
{
    qDebug() << "The file must be written here";
    writer = new FileWriter(container);
}


