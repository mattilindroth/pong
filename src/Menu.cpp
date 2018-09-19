#include "Menu.h"

Menu::Menu()
{

}

void Menu::AddMenuItem(MenuItem *item) {
    pMenuItems.push_back(item);
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

int Menu::Show(Scene *scene) {
    //TODO Add the menu loop here
    // render and keyhandlers also here
    bool quit;
    int result = -1;
    MenuItem *menuItem;

    //Add the menu items to scene
    for(std::vector<MenuItem *>::iterator it = pMenuItems.begin(); it != pMenuItems.end(); ++it) {
        menuItem = (*it);
        scene->AddItem(menuItem);
    }

    quit = false;
    while(quit) {
        const Uint8* keystates = SDL_GetKeyboardState(NULL);

        if(keystates[SDL_SCANCODE_UP]  && !keystates[SDL_SCANCODE_DOWN]) {
            // TODO: Handle selected change

            //HandlePaddleMove(true, right);
        } else if (!keystates[SDL_SCANCODE_ESCAPE]) {
            // TODO: Handle menu quit
            quit = true;
        } else if (!keystates[SDL_SCANCODE_RETURN]) {
            //TODO: Select menu action. Quit with index
            //right->SetSpeed(0, 0);
        }
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
