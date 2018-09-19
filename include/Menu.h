#ifndef MENU_H
#define MENU_H

#include "MenuItem.h"
#include "GameItem.h"
#include "Scene.h"
#include "SceneObject.h"
#include <vector>

class Menu
{
    public:
        Menu();


        void AddMenuItem(MenuItem *item);
        void RemoveMenuItem(MenuItem *item);
        void RemoveMenuItemAt(int index);

        /// Shows the menu and returns value indicating menuitem index
        /// @param: *scene a pointer to a Scene - object used for rendering the menu
        /// @return: index indicating menuitem selected by user
        int Show(Scene *scene);

        virtual ~Menu();

    protected:

    private:
        std::vector<MenuItem *> pMenuItems;
};

#endif // MENU_H
