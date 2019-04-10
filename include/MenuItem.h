#ifndef MENUITEM_H
#define MENUITEM_H

#include <SDL2\SDL_ttf.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#include "Renderable.h"
#include "Text.h"


class MenuItem : public Renderable
{
    public:
        MenuItem(std::string label ,const SDL_Renderer *renderer);

        void SetLabel(std::string newLabel);
        std::string GetLabel( void );

        bool IsSelected( void );
        void SetSelected( bool selected );

        //Renderable - implementations
        SDL_Rect *GetRectangle( void ) ;
        SDL_Texture *GetTexture( void ) ;

        virtual ~MenuItem();

    protected:

    private:
        bool pIsSelected;
        Text *pText;
        int pSizeW;
        int pSizeH;
};

#endif // MENUITEM_H
