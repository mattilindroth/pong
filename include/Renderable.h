#ifndef RENDERABLE_H
#define RENDERABLE_H

#include <SDL.h>

class Renderable
{
    public:
        virtual SDL_Rect *GetRectangle( void ) = 0;
        virtual SDL_Texture *GetTexture( void ) = 0;
        virtual ~Renderable() {};
    protected:

    private:
};

#endif // RENDERABLE_H
