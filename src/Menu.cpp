#include "Menu.h"

Menu::Menu(TTF_Font *menuItemFont)
{
    pFont = menuItemFont;
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

void Menu::SetMenuItemLocations( Scene *scene ) {

    int maxW = 0;
    int currentW = 0;
    int height = 0; //Note we asssume here the height is same for each item which of course is naive
    int dh;
    MenuItem *menuItem;
    std::string text;
    //Find longest text
    for(std::vector<MenuItem *>::iterator it = pMenuItems.begin(); it != pMenuItems.end(); ++it) {
        menuItem = (*it);
        text = menuItem->GetLabel();
        TTF_SizeText(pFont, text.c_str(), &currentW, &height);
        if(currentW > maxW) {
            maxW = currentW;
        }
    }

    dh = scene->GetScreenSizeY() / pMenuItems.size();

}

int Menu::Show(Scene *scene) {
    bool quit;
    int result = 0;
    MenuItem *menuItem;
    SDL_Event e;

    //Add the menu items to scene
    for(std::vector<MenuItem *>::iterator it = pMenuItems.begin(); it != pMenuItems.end(); ++it) {
        menuItem = (*it);
        scene->AddItem(menuItem);
    }
    SDL_Delay(500);
    quit = false;
    while(quit == false) {
        const Uint8* keystates = SDL_GetKeyboardState(NULL);

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
                            break;
                        case SDL_SCANCODE_DOWN:
                            result = result + 1;
                            if(((unsigned int)result) > pMenuItems.size())
                                result = 0;
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
