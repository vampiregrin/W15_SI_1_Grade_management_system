#include "DatabaseEntryComparator.h"

DatabaseEntryComparator::DatabaseEntryComparator(std::function<bool(const DatabaseEntry&, 
    const DatabaseEntry&)> ComparingFunction) : comparingFunction(ComparingFunction)
{

}

bool DatabaseEntryComparator::operator()(const DatabaseEntry& a, const DatabaseEntry& b )
{
    return comparingFunction(a, b);
}
