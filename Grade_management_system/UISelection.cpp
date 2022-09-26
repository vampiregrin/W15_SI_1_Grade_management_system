#include "UISelection.h"

void UISelection::addOption(char ch, UIEntry entry)
{
	options.insert(std::pair <char, UIEntry> (ch, entry));

}

void UISelection::showOptions()
{
	std::cout << std::endl;
	for (std::unordered_map<char, UIEntry>::iterator ptr = options.begin(); ptr != options.end(); ptr++)
	{
		std::cout << ptr->first << "." << ptr->second.getDescription() << std::endl;		
	}
	std::cout << "0. back" << std::endl;
}

void UISelection::chooseOption()
{
	char ch;
	for (;;) {
		system("CLS");
		showOptions();
		std::cin >> ch;
		if (ch == '0') {
			return;
		}
		std::unordered_map <char, UIEntry> ::iterator ptr = options.find(ch);

		if (ptr != options.end()) {
			std::function<void()> action = ptr->second.getAction();
			action();
		}
	}
}
