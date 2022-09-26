#pragma once
#include <iostream>
#include <functional>

class UIEntry
{
private:
	std::string description; 
	std::function <void()> action;
public:
	UIEntry(std::string Description, std::function <void()> Action);
	std::function <void()> getAction();
	std::string getDescription();

};


