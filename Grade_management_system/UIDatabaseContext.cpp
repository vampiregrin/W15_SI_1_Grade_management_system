#include "UIDatabaseContext.h"

UIDatabaseContext::UIDatabaseContext()
{
	sortingFunction = [](const DatabaseEntry a, const DatabaseEntry b) {
		return a.getName() > b.getName(); 
	};
	filteringFunction = [](const DatabaseEntry a) {
			return true;
	};
}

std::function<bool(const typename DatabaseEntry)> UIDatabaseContext::getFilteringFunction()
{
	return filteringFunction;
}

std::function<bool(const typename DatabaseEntry, const typename DatabaseEntry)> UIDatabaseContext::getSortingFunction()
{
	return sortingFunction;
}

void UIDatabaseContext::setFilteringFunction(std::function<bool(const typename DatabaseEntry)> function)
{
	filteringFunction = function;
}

void UIDatabaseContext::setSortingFunction(std::function<bool(const typename DatabaseEntry, const typename DatabaseEntry)> function)
{
	sortingFunction = function;
}
