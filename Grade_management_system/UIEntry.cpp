#include "UIEntry.h"

UIEntry::UIEntry(std::string Description, std::function<void()> Action)
{
    description = Description;
    action = Action;
}

std::function<void()> UIEntry::getAction()
{
   return action;
}

std::string UIEntry::getDescription()
{
    return description;
}
