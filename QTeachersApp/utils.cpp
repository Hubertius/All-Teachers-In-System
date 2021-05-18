#include "utils.h"

namespace HubertiusNamespace
{
    bool connOpen(QSqlDatabase * myDatabase, QString  path) // function is opening connection with database
    {
        (*myDatabase).setDatabaseName(path);
        if((*myDatabase).open())
        {
            qDebug() << "Connected to database.";
            return true;
        }
        else
        {
            qDebug() << "Failed to open the database!";
        }
        return false;
    }

    void connClose(QSqlDatabase * myDatabase) // function is closing connection with database
    {
        (*myDatabase).close();
        (*myDatabase).removeDatabase(QSqlDatabase::defaultConnection);
    }

    bool dataValidation(Teacher& teacher) // function is validating data
    {
        QString stringWithNumber = "0123456789";
        QString toSearchForDigigits = teacher.name + teacher.surname + teacher.sex + teacher.title;
        for(auto ch: stringWithNumber)
        {
            if(toSearchForDigigits.indexOf(ch, 0) != -1)
            {
                qDebug() << "Name, surname, sex or title (one or more) got digits in themselves!";
                return false;
            }
        }
        teacher.sex = teacher.sex.toLower();
        if(teacher.sex == "male" || teacher.sex == "female")
        {
            qDebug() << "There is something wrong with \"sex\"!";
            return false;
        }
        QRegExp reDigits("\\d*"); // a digit (\d), zero or motre times (*)
        if(reDigits.exactMatch(teacher.pesel) && teacher.pesel.size() == 11 && peselValidation(teacher.pesel))
        {
            qDebug() << "PESEL is  completly constructed of 11 digits and is valid.";
        }
        else
        {
            qDebug() << "PESEL is NOT constructed entirely with digits or got less or more than 11 characters.";
            return false;
        }
        if(isStartingWithUpper(teacher.name, teacher.surname, teacher.title, teacher.listOfSubjects))
        {
            qDebug() << "Name, surname, title and list of subjects learned by teachers start with capital letter";
        }
        else
        {
            return false;
        }
        if((teacher.dateOfBirth.at(2) == '.' && teacher.dateOfBirth.at(5) == '.'))
        {
            if(teacher.dateOfBirth.at(0).isDigit() && teacher.dateOfBirth.at(1).isDigit() && teacher.dateOfBirth.at(3).isDigit() && teacher.dateOfBirth.at(4).isDigit() && teacher.dateOfBirth.at(6).isDigit() && teacher.dateOfBirth.at(7).isDigit() && teacher.dateOfBirth.at(8).isDigit() && teacher.dateOfBirth.at(9).isDigit())
            {
                if(!isValidDate(teacher.dateOfBirth.mid(0,2), teacher.dateOfBirth.mid(3, 2), teacher.dateOfBirth.mid(6, 4)))
                {
                    return false;
                }

            }
        }
        else
        {
            qDebug() << "Your date you wrote to update is wrong!";
            return false;
        }
        if( (teacher.name.size() == 0 || teacher.name.size() > 20) ) // Name == 0 || Name > 20
        {
            qDebug() << "Your name size is equal to 0 (\"empty\") or greater than 20! That's wrong!";
            return false;
        }
        else if( (teacher.surname.size() == 0 || teacher.surname.size() > 20) ) // Surname == 0 || Surname > 20
        {
            qDebug() << "Your surname size is equal to 0 (\"empty\") or greater than 20! That's wrong!";
            return false;
        }
        else if( (teacher.sex.size() == 0 || teacher.sex.size() > 6) ) // Sex == 0 || Sex > 6
        {
            qDebug() << "Your \"sex\" QString length is equal to 0 (\"empty\") or greater than 20! That's wrong!";
            return false;
        }
        else if( (teacher.dateOfBirth.size() == 0 || teacher.dateOfBirth.size() > 10) )
        {
            qDebug() << "Your date of birth with two characters of '.' is equal to 0 or greater than 10! That's wrong!";
            return false;
        }
        else if( (teacher.title.size() == 0 || teacher.title.size() > 30) )
        {
            qDebug() << "Your title is eual to 0 or greater than 20! That's wrong!";
            return false;
        }
        else if( (teacher.listOfSubjects.size() == 0 || teacher.listOfSubjects.size() > 50) )
        {
            qDebug() << "Your list of subjects leaded by profesor / teachers is equal to 0 or greater than 20.";
            qDebug() << "It's probably not possible... .";
            return false;
        }
        else
        {
            qDebug() << "Your data to update got correct length!";
        }
        return true; // if everything is "ok" validation function returns true
    }

    bool peselValidation(QString pesel)
    {
        int sum = 0;
        int table[11] = {0};
        for(int i = 0; i < pesel.size(); i++)
        {
            table[i] = pesel.at(i).digitValue();
        }
        sum += table[0] * 1 + table[1] * 3 + table[2] * 7 + table[3] * 9 + table[4] * 1 + table[5] * 3 + table[6] * 7 + table[7] * 9 + table[8] * 1 + table[9] * 3;
        int lastDigit = sum % 10;
        if((10 - lastDigit) == table[10])
        {
            qDebug() << "This UPDATED PESEL is VALID";
            return true;
        }
        return false;
    }

    bool isStartingWithUpper(QString name, QString surname, QString title, QString listOfSubjects)
    {
        QString tempName = name;
        QString tempSurname = surname;
        QString tempTitle = title;
        QString tempListOfSubjects = listOfSubjects;
        tempName[0].toUpper();
        tempSurname[0].toUpper();
        tempTitle[0].toUpper();
        tempListOfSubjects[0].toUpper();
        if(tempName == name && tempSurname == surname && tempTitle == title && tempListOfSubjects == listOfSubjects)
        {
            return true;
        }
        return false;
    }
    
    bool isValidDate(QString day, QString month, QString year)
    {
        bool checkForIntConv = true;
        int dayInt = day.toInt(&checkForIntConv, 10); // conversion of QString of day into int
        if(!checkForIntConv) // checking if QString day conversion to int is false
        {
            qDebug() << "Your day isn't even an integer!";
            return false;
        }
        int monthInt= month.toInt(&checkForIntConv, 10); // conversion of QString of month into int
        if(!checkForIntConv) // checking if QString month conversion to int is false
        {
           qDebug() << "Your month isn't even an integer!";
           return false;
        }
        int yearInt = year.toInt(&checkForIntConv, 10); // conversion of QString of year into int
        if(!checkForIntConv) // checking if QString year conversion to int is false
        {
            qDebug() << "Your year isn't even an integer!";
            return false;
        }
        // checking if year, month and day are in 'suitable' range - START OF CODE
        if(yearInt < 1940 || yearInt > 2000)
        {
            qDebug("It's impossible for professor to be so young / old... .");
            return false;
        }
        if(monthInt < 1 || monthInt > 12)
        {
            qDebug() << "The month couldn't be below 1 or greater than 12!";
            return false;
        }
        if(dayInt < 1 || dayInt > 31)
        {
            qDebug() << "The day couldn't be below 1 or bre greater than 31!";
        }
        //  checking if year, month and day are in 'suitable' range - END OF CODE
        // checking if february is leap year and process of handling it - START OF CODE
        if(monthInt == 2)
        {
            if(isLeap(yearInt))
            {
                return dayInt <= 29;
            }
            else
            {
                return dayInt <= 28;
            }
        }
        // checking if february is leap year and process of handling it - END OF CODE
        // April, June, Semptember and November can hava less or equal to 30 - START OF CODE
        if(monthInt == 4 || monthInt == 6 || monthInt == 9 || monthInt == 11)
        {
            return dayInt <= 30;
        }
        // April, June, Semptember and November can hava less or equal to 30 - END OF CODE
        return true;
    }

    bool isLeap(int year)
    {
        return ( ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0) );
    }
}
