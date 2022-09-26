#pragma once
#include <iostream>
#include <string>

class DatabaseEntry
{
	std::string studentName;
	char grade;

public:
	DatabaseEntry() = default;
	//konstruktor kopiujący
	DatabaseEntry(const DatabaseEntry& other) = default; 
	DatabaseEntry(std::string StudentName, char Grade) { studentName = StudentName; 
	grade = Grade; };
	std::string getName() const;
	char getGrade() const;
	std::ostream& operator >> (std::ostream& os);

};

