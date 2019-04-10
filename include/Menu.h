#ifndef MENU_H
#define MENU_H

#include "MenuItem.h"
#include "GameItem.h"
#include "Scene.h"
#include "stdio.h"
#include "SceneObject.h"
#include <SDL2/SDL_ttf.h>
#include <vector>

class Menu
{
    public:
        Menu(SDL_Rect menuScreenRect);

        void AddMenuItem(MenuItem *item);
        void RemoveMenuItem(MenuItem *item);
        void RemoveMenuItemAt(int index);

        /// Shows the menu and returns value indicating menuitem index
        /// @param: *scene a pointer to a Scene - object used for rendering the menu
        /// @return: index indicating menuitem selected by user
        int Show(Scene *scene);

        virtual ~Menu();

    protected:
        void ToggleSelected(int indexOfSelected);
    private:
        void SetMenuItemLocations( );
        std::vector<MenuItem *> pMenuItems;
        SDL_Rect pMenuScreenRect;
};

#endif // MENU_H
