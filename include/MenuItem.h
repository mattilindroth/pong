#ifndef MENUITEM_H
#define MENUITEM_H

#include <SDL2\SDL_ttf.h>
#include <string>

class MenuItem
{
    public:

        MenuItem(std::string label);

        void SetLabel(std::string newLabel);
        std::string GetLabel( void );

        bool IsSelected( void );
        void SetSelected( bool selected );

        virtual ~MenuItem();

    protected:

    private:
        std::string pLabel;
        bool pIsSelected;
};

#endif // MENUITEM_H
