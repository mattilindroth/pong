#include "MenuItem.h"

MenuItem::MenuItem(string label)
{
    pLabel = label;
}
void MenuItem::SetLabel(string newLabel) {
    pLabel = newLabel;
}

string MenuItem::GetLabel( void ) {
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
