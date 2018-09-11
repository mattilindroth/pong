#include "MenuItem.h"

MenuItem::MenuItem(std::string label)
{
    pLabel = label;
}
void MenuItem::SetLabel(std::string newLabel) {
    pLabel = newLabel;
}

std::string MenuItem::GetLabel( void ) {
    return pLabel;
}

bool MenuItem::IsSelected( void ) {
    return pIsSelected ;
}

void MenuItem::SetSelected( bool selected ) {
    pIsSelected = selected;
}

MenuItem::~MenuItem()
{
    //dtor
}
