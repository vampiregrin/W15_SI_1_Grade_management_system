#pragma once
#include <string>
#include "DatabaseEntry.h"
#include "DatabaseException.h"
#include <unordered_map>
#include <iostream>
#include <functional>

class DatabaseManager
{
	std::unordered_map <std::string, DatabaseEntry> entries;

public:
	void addEntry(const DatabaseEntry & entry);
	bool removeEntry(const std::string & name);
	void modifyEntry(const DatabaseEntry & entry);
	std::vector <DatabaseEntry> getEntries();
	 //serialization operators
	std::ostream& operator >> (std::ostream& os);
	std::istream& operator << (std::istream& is);
	void showEntries(std::function <bool(const DatabaseEntry&)> filteringFunction, std::function <bool(const DatabaseEntry&, const DatabaseEntry&)> comparingFunction);
	DatabaseEntry * findStudent(const std::string &name) throw (DatabaseException);
	bool checkIfExists(const std::string& name);
};

