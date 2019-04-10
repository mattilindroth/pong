#include "Menu.h"

Menu::Menu(SDL_Rect menuScreen)
{
    this->pMenuScreenRect = menuScreen;
}

void Menu::AddMenuItem(MenuItem *item) {
    pMenuItems.push_back(item);
    fprintf(stderr, "pMenuItems.Count() = %i\n", pMenuItems.size());
}

void Menu::RemoveMenuItem(MenuItem *item) {
    for(unsigned int i = 0; i < pMenuItems.size(); i++) {
        if(item == pMenuItems.at(i)){
            this->RemoveMenuItemAt(i);
        }
    }
}

void Menu::RemoveMenuItemAt(int index) {
    pMenuItems.erase(pMenuItems.begin()+index);
}

void Menu::SetMenuItemLocations( ) {

    int cumulativeY = 0;
    int currentW = 0;
    int combinedFontHeights = 0;
    int spacingY = 0;
    MenuItem *menuItem;
    std::string text;

    for(std::vector<MenuItem *>::iterator it = pMenuItems.begin(); it != pMenuItems.end(); ++it) {
        menuItem = (*it);
        combinedFontHeights += menuItem->GetRectangle()->h;
        currentW = menuItem->GetRectangle()->w;

        //Set the x so the text is in the middle of menuscreen.
        menuItem->GetRectangle()->x = (this->pMenuScreenRect.x + (this->pMenuScreenRect.w / 2) - (currentW / 2));
    }
    spacingY = (this->pMenuScreenRect.h - combinedFontHeights) / (pMenuItems.size() -1);

    cumulativeY = this->pMenuScreenRect.y;
    for(std::vector<MenuItem *>::iterator it = pMenuItems.begin(); it != pMenuItems.end(); ++it) {
        menuItem = (*it);
        menuItem->GetRectangle()->y = cumulativeY;
        cumulativeY += spacingY + menuItem->GetRectangle()->h;
    }
}

void Menu::ToggleSelected(int indexOfSelected) {
    MenuItem *menuItem;
    int i = 0;
    for(std::vector<MenuItem *>::iterator it = pMenuItems.begin(); it != pMenuItems.end(); ++it) {
        menuItem = (*it);
        menuItem->SetSelected(i == indexOfSelected);
        i++;
    }
}

int Menu::Show(Scene *scene) {
    bool quit;
    int result = 0;
    MenuItem *menuItem;
    SDL_Event e;

    this->SetMenuItemLocations();

    //Add the menu items to scene
    for(std::vector<MenuItem *>::iterator it = pMenuItems.begin(); it != pMenuItems.end(); ++it) {
        menuItem = (*it);
        scene->AddItem(menuItem);
    }
    SDL_Delay(500);
    quit = false;
    while(quit == false) {

        while(SDL_PollEvent(&e) != 0) {
            switch (e.type ) {
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_KEYDOWN:
                    switch (e.key.keysym.scancode) {
                        case SDL_SCANCODE_ESCAPE:
                            result = -1;
                            quit = true;
                            break;
                        case SDL_SCANCODE_RETURN:
                            quit = true;
                            break;
                        case SDL_SCANCODE_UP:
                            result = result - 1;
                            if(result < 0 )
                                result = pMenuItems.size();
                            ToggleSelected(result);
                            break;
                        case SDL_SCANCODE_DOWN:
                            result = result + 1;
                            if(((unsigned int)result) > pMenuItems.size())
                                result = 0;
                            ToggleSelected(result);
                            break;
                        default:
                            break;
                        }
                break;
            }
        }
        scene->RenderItems();
    }
    //remove items from scene
    scene->Clear();

    return result;
}

Menu::~Menu()
{
    MenuItem *sObject;
    for (std::vector<MenuItem *>::iterator it = pMenuItems.begin(); it != pMenuItems.end(); ++it) {
        sObject = (*it);
        delete sObject;
    }
}
