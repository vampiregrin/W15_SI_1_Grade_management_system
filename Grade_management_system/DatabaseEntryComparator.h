#pragma once
#include "DatabaseEntry.h"
#include <functional>

class DatabaseEntryComparator
{

private: 
    std::function <bool(const DatabaseEntry&, const DatabaseEntry&) > comparingFunction = [&](const DatabaseEntry& a, const DatabaseEntry& b) {
        return a.getName() < b.getName(); };
public:
    DatabaseEntryComparator(std::function <bool(const DatabaseEntry&, const DatabaseEntry&)> ComparingFunction);
    DatabaseEntryComparator(const DatabaseEntryComparator& other) = default; 
    bool operator() (const DatabaseEntry& a, const DatabaseEntry& b) ;

};

