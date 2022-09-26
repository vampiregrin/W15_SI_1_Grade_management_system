#include "DatabaseManager.h"
#include "DatabaseEntryComparator.h"
#include<iostream>
#include <map>

void DatabaseManager::addEntry(const DatabaseEntry &entry)
{
	entries.insert(std::pair <std::string, DatabaseEntry>(entry.getName(), entry));
}

bool DatabaseManager::removeEntry(const std::string& name)
{
	return entries.erase(name) > 0;
}

void DatabaseManager::modifyEntry(const DatabaseEntry& entry)
{
	entries[entry.getName()] = entry;
}

std::vector<DatabaseEntry> DatabaseManager::getEntries()
{
	std::vector <DatabaseEntry> ret;
	
	//iterator: 
	// Declaring iterator to a vector
	std::unordered_map <std::string, DatabaseEntry>::iterator ptr;

	// Displaying vector elements using begin() and end()
	for (ptr = entries.begin(); ptr != entries.end(); ptr++) {
		ret.push_back((*ptr).second);
	}
	return ret;
}

std::ostream& DatabaseManager::operator >> (std::ostream& os)
{
	os << entries.size() << std::endl;
	for (std::unordered_map <std::string, DatabaseEntry>::iterator ptr = entries.begin();
		ptr != entries.end(); ptr++) {
		os << ptr->first << std::endl;
		os << (int) ptr->second.getGrade() << std::endl;
	}
	return os; 
}

std::istream& DatabaseManager::operator <<(std::istream& is)
{
	int size;
	std::string name;
	int grade; 
	is >> size;
	for (int i = 0; i < size; i++) {
		is >> name; 
		is >> grade; 
		addEntry(DatabaseEntry(name, grade));
	}
	return is;
}

void DatabaseManager::showEntries(std::function <bool(const DatabaseEntry&)> 
	filteringFunction, std::function <bool(const DatabaseEntry&, const DatabaseEntry&)> 
	comparingFunction)
{

//	std::multimap<std::string, DatabaseEntry, DatabaseEntryComparator> map(entries.begin(), entries.end(), 
//		DatabaseEntryComparator(comparingFunction));

	std::multimap<std::string, DatabaseEntry, DatabaseEntryComparator> map(entries.begin(), entries.end(), DatabaseEntryComparator(comparingFunction));
	for (std::multimap <std::string, DatabaseEntry> ::iterator it = map.begin(); 
		it != map.end(); it++) {
		if (filteringFunction(it->second)) {
			it->second >> std::cout;
			std::cout << std::endl;
		}
	}
}

DatabaseEntry* DatabaseManager::findStudent(const std::string &name) throw (DatabaseException)
{
	std::unordered_map <std::string, DatabaseEntry> :: iterator it = entries.find(name) ;
	if (it == entries.end()) {
		throw DatabaseException("No record found");
	}
	return new DatabaseEntry(it->second);
}

bool DatabaseManager::checkIfExists(const std::string& name)
{
	std::unordered_map <std::string, DatabaseEntry> ::iterator it = entries.find(name);
	return (it != entries.end()); 
}
