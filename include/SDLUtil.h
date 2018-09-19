#ifndef SDLUTIL_H
#define SDLUTIL_H

#include <SDL.h>

class SDLUtil
{
    public:
        SDLUtil();
        public static SDL_Texture Surface2Texture(SDL_Surface *surface, SDL_Renderer *renderer);
        virtual ~SDLUtil();

    protected:

    private:
};

#endif // SDLUTIL_H
