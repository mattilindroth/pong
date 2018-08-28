#ifndef MENUITEM_H
#define MENUITEM_H

#include <SDL2\SDL_ttf.h>

class MenuItem
{
    public:

        MenuItem(string label);

        void SetLabel(string newLabel);
        string GetLabel( void );

        bool IsSelected( void );
        void SetSelected( bool selected );

        virtual ~MenuItem();

    protected:

    private:
        string pLabel;
        bool pIsSelected;
};

#endif // MENUITEM_H
