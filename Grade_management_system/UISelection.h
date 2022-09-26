#pragma once
#include <unordered_map>
#include "UIEntry.h"

class UISelection
{
private:
	std::unordered_map <char, UIEntry> options;
public: 
	void addOption(char ch, UIEntry entry);
	void showOptions();
	void chooseOption();
};

