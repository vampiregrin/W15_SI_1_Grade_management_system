#pragma once
#include "DatabaseManager.h"
#include <functional>
#include "UIDatabaseContext.h"
#include "UISelection.h"

class Application
{
private: 
	DatabaseManager dbMgr; 
	UIDatabaseContext UIContext; 
	UISelection mainOpt;
	UISelection modifyDatabaseOpt;
	UISelection loadDatabaseOpt;
	UISelection filterDatabaseOpt;
	UISelection setSortingOrderOpt;
	UISelection visualiseDatabaseOpt;
	std::function <bool(const DatabaseEntry&)> filteringFunction = [&](const DatabaseEntry& entry) {
		return true;  };
	std::function <bool(const DatabaseEntry&, const DatabaseEntry&)> comparingFunction = [](const DatabaseEntry& a, const DatabaseEntry& b) {
		return a.getName() < b.getName(); };
	void modifyDatabase();
	void loadDatabase();
	void filterDatabase();
	void setSortingOrder();
	void visualiseDatabase();

	void modifyDatabase_AddEntry();
	void modifyDatabase_RemoveEntry();
	void modifyDatabase_ModifyEntry();
	void modifyDatabase_LoadStore();
	void modifyDatabase_Filter();
	void modifyDatabase_SetOrder();
	void modifyDatabase_Visualise();

	void loadDatabase_Load();
	void loadDatabase_Store();

	void filterDatabase_OnlyPassing();
	void filterDatabase_NonPassing();
	void filterDatabase_AllGrades();

	void sortDatabase_IncreasingByName();
	void sortDatabase_DecreasingByName();
	void sortDatabase_IncreasingByGrade();
	void sortDatabase_DecreasingByGrade();
	
	void showMessageAndWait(const std::string& message);

public: 
	Application();
	int run();

};

