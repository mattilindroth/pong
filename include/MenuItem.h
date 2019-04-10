#ifndef MENUITEM_H
#define MENUITEM_H

#include <SDL2\SDL_ttf.h>
#include <string>
#include "SceneObject.h"
#include <stdio.h>
#include <stdlib.h>

class MenuItem : public SceneObject
{
    public:

        MenuItem(std::string label ,SDL_Renderer *renderer);

        void SetLabel(std::string newLabel);
        std::string GetLabel( void );

        bool IsSelected( void );
        void SetSelected( bool selected );

        virtual ~MenuItem();

    protected:

    private:
        std::string pLabel;
        bool pIsSelected;
        SDL_Texture *pTextureSelected;
        SDL_Texture *pTemporaryTexture;
        int pSizeW;
        int pSizeH;
};

#endif // MENUITEM_H
