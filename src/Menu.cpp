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
    bool quit;
    int result = 0;
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
            result = result - 1;
            if(result < 0 )
                result = pMenuItems.size();
        else if(!keystates[SDL_SCANCODE_UP]  && keystates[SDL_SCANCODE_DOWN])
            result = result + 1;
            if(((unsigned int)result) > pMenuItems.size())
                result = 0;
        } else if (!keystates[SDL_SCANCODE_ESCAPE]) {
            // TODO: Handle menu quit
            result = -1;
            quit = true;
        } else if (!keystates[SDL_SCANCODE_RETURN]) {
            //TODO: Select menu action. Quit with index
            quit = true;
            //right->SetSpeed(0, 0);
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
