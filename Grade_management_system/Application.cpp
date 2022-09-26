#include "Application.h"
#include <fstream>
#include <iostream>


void Application::modifyDatabase()
{
    modifyDatabaseOpt.chooseOption();

}

void Application::loadDatabase()
{
    loadDatabaseOpt.chooseOption();
}


void Application::filterDatabase()
{
    filterDatabaseOpt.chooseOption();
}

void Application::setSortingOrder()
{
    setSortingOrderOpt.chooseOption();
}

void Application::visualiseDatabase()
{
    visualiseDatabaseOpt.chooseOption();
}

void Application::modifyDatabase_AddEntry()
{
    std::string name; 
    int grade;
    std::cout << "Enter the last name of the student:" << std::endl;
    std::cin >> name;
    if (name.size() == 0) {
        return;
    }
    if (dbMgr.checkIfExists(name)) {
        std::cout << "This student already exists!" << std::endl;
        return;
    }
  
    for (; ; ) {
        
        std::string gradeString; 
        std::cout << "Enter the grade (or press q to quit): ";
        std::cin >> gradeString;
        if (gradeString == "q" || gradeString == "Q") {
            return;
        }
        try {
            grade = std::stoi(gradeString);
        }
        catch (std::invalid_argument ex) {
            std::cout << "Wrong value" << std::endl; 
            continue;
        }

        if (grade >= 0 && grade <= 6) {
            break;
        }
        else {
            showMessageAndWait("Incorrect grade!");
        }
    }
    dbMgr.addEntry(DatabaseEntry(name, grade));
    showMessageAndWait(std::string ("Record added for student:") + name);
    
}

void Application::modifyDatabase_RemoveEntry()
{
    std::string name;
    int grade;
    std::cout << "Enter the last name of the student:" << std::endl;
    std::cin >> name;
    if (name.size() == 0) {
        return;
    }
    if (dbMgr.removeEntry(name) < 1) { 
        showMessageAndWait("No records found for given name");
        return;
    }
    showMessageAndWait(std::string("Record removed for student:") + name);
}

void Application::modifyDatabase_ModifyEntry()
{
    std::string name;
    int grade;
    std::cout << "Enter the last name of the student:" << std::endl;
    std::cin >> name;
    if (name.size() == 0) {
        return;
    }
    if (!dbMgr.checkIfExists(name)) {
        showMessageAndWait("This student doesnt exist in database!");
        return;
    }

    for (; ; ) {

        std::string gradeString;
        std::cout << "Enter the grade (or press q to quit): ";
        std::cin >> gradeString;
        if (gradeString == "q" || gradeString == "Q") {
            return;
        }
        try {
            grade = std::stoi(gradeString);
        }
        catch (std::invalid_argument ex) {
            std::cout << "Wrong value" << std::endl;
            continue;
        }

        if (grade >= 0 && grade <= 6) {
            break;
        }
        else {
            std::cout << std::endl << "Incorrect grade." << std::endl;
        }

    }
    dbMgr.modifyEntry(DatabaseEntry(name, grade));
    showMessageAndWait(std::string("Record modified for student:") + name);
}



void Application::modifyDatabase_LoadStore()
{
    loadDatabaseOpt.chooseOption();

}

void Application::modifyDatabase_Filter()
{
    filterDatabaseOpt.chooseOption();
}

void Application::modifyDatabase_SetOrder()

{
    setSortingOrderOpt.chooseOption();
}

void Application::modifyDatabase_Visualise()
{
    dbMgr.showEntries(filteringFunction, comparingFunction);
    getchar();
    getchar();
}

void Application::loadDatabase_Load()
{

    std::string fileName;
    std::cout << "Enter file name:" << std::endl;
    std::cin >> fileName;
    if (fileName.size() == 0) {
        return;
    }
    std::ifstream inputStream;
    inputStream.open(fileName, std::ifstream::in);
    if (!inputStream.good()) {
        showMessageAndWait("File doesn't exist");
        return;
    }
    dbMgr << inputStream;
}

void Application::loadDatabase_Store()
{

    std::string fileName;
    std::cout << "Enter file name:" << std::endl;
    std::cin >> fileName;
    if (fileName.size() == 0) {
        return;
    }
    std::ofstream outputStream;
    outputStream.open(fileName, std::ofstream::out | std::ofstream::trunc);
    if (!outputStream.good()) {
        showMessageAndWait("File doesn't exist");
        return;
    }
    dbMgr >> outputStream;
}

void Application::filterDatabase_OnlyPassing()
{
    filteringFunction = [&](const DatabaseEntry& entry) {
        return (entry.getGrade() > 2);
    };
 
}

void Application::filterDatabase_NonPassing()
{
    filteringFunction = [&](const DatabaseEntry& entry) {
        return (entry.getGrade() <= 2);
    };
}

void Application::filterDatabase_AllGrades()
{
    filteringFunction = [&](const DatabaseEntry& entry) {
        return true;
    };
}

void Application::sortDatabase_IncreasingByName()
{
    comparingFunction = [&](const DatabaseEntry& a, const DatabaseEntry& b) {
        return a.getName() < b.getName();
    };
}

void Application::sortDatabase_DecreasingByName()
{
    comparingFunction = [&](const DatabaseEntry& a, const DatabaseEntry& b) {
        return a.getName() > b.getName();
    };
}

void Application::sortDatabase_IncreasingByGrade()
{
    comparingFunction = [&](const DatabaseEntry& a, const DatabaseEntry& b) {
        return a.getGrade() < b.getGrade();
    };
}

void Application::sortDatabase_DecreasingByGrade()
{
    comparingFunction = [&](const DatabaseEntry& a, const DatabaseEntry& b) {
        return a.getGrade() > b.getGrade();
    };
}

void Application::showMessageAndWait(const std::string& message)
{
    std::cout << message << std::endl; 
    getchar();
    getchar(); 

}


Application::Application()
{
    mainOpt.addOption('1', UIEntry("Modify database", [&]() {modifyDatabase(); }));
    mainOpt.addOption('2', UIEntry("Load/store database", [&]() {modifyDatabase_LoadStore(); }));
    mainOpt.addOption('3', UIEntry("Filter database", [&]() {modifyDatabase_Filter(); }));
    mainOpt.addOption('4', UIEntry("Set sorting order", [&]() {modifyDatabase_SetOrder(); }));
    mainOpt.addOption('5', UIEntry("Visualize database", [&]() {modifyDatabase_Visualise(); }));
    
    modifyDatabaseOpt.addOption('1', UIEntry("Add entry", [&]() {modifyDatabase_AddEntry(); }));
    modifyDatabaseOpt.addOption('2', UIEntry("Remove entry", [&]() {modifyDatabase_RemoveEntry(); }));
    modifyDatabaseOpt.addOption('3', UIEntry("Modify entry", [&]() {modifyDatabase_ModifyEntry(); }));
 
    loadDatabaseOpt.addOption('1', UIEntry("Load database from the file", [&]() {loadDatabase_Load(); }));
    loadDatabaseOpt.addOption('2', UIEntry("Store database in a file", [&]() {loadDatabase_Store(); }));
  
    filterDatabaseOpt.addOption('1', UIEntry("Only passing grades", [&]() {filterDatabase_OnlyPassing(); }));
    filterDatabaseOpt.addOption('2', UIEntry("Only nonpassing grades", [&]() {filterDatabase_NonPassing(); }));
    filterDatabaseOpt.addOption('3', UIEntry("All grades", [&]() {filterDatabase_AllGrades(); }));

    setSortingOrderOpt.addOption('1', UIEntry("Increasing by name", [&]() {sortDatabase_IncreasingByName(); }));
    setSortingOrderOpt.addOption('2', UIEntry("Decreasing by name", [&]() {sortDatabase_DecreasingByName(); }));
    setSortingOrderOpt.addOption('3', UIEntry("Increasing by grade", [&]() {sortDatabase_IncreasingByGrade(); }));
    setSortingOrderOpt.addOption('4', UIEntry("Decreasing by grade", [&]() {sortDatabase_DecreasingByGrade(); }));


        ;
    UISelection visualiseDatabaseOpt;
    
}

int Application::run()
{
    mainOpt.chooseOption();
    return 0;
}
