#include "DatabaseEntry.h"
#include <iostream>

std::string DatabaseEntry::getName() const
{
    return studentName;
}

char DatabaseEntry::getGrade() const
{
    return grade;
}

std::ostream& DatabaseEntry::operator>>(std::ostream& os)
{
    os << studentName << ":" << (int)grade;
    return os; 
}
