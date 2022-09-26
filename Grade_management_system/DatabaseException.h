#pragma once
#include <exception>

class DatabaseException : public std::exception
{
public:
	DatabaseException(char const* const message) : std::exception(message) {};
	DatabaseException(const DatabaseException& other) = default; 

};

