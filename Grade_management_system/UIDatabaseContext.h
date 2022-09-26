#pragma once
#include <iostream>
#include <functional>
#include "DatabaseEntry.h"

class UIDatabaseContext
{
	std::function<bool(const typename DatabaseEntry, const typename DatabaseEntry)> sortingFunction;
	std::function<bool(const typename DatabaseEntry)> filteringFunction;

public: 
	UIDatabaseContext();
	std::function<bool(const typename DatabaseEntry)> getFilteringFunction();
	std::function<bool(const typename DatabaseEntry, const typename DatabaseEntry)> getSortingFunction();
	void setFilteringFunction(std::function<bool(const typename DatabaseEntry)> function) ;
	void setSortingFunction(std::function<bool(const typename DatabaseEntry, const typename DatabaseEntry)> function);


};

