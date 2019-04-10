#ifndef TEXT_H
#define TEXT_H

#include <SDL.h>
#include <SDL2\SDL_ttf.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include "Renderable.h"

class Text : public Renderable
{
    public:
        Text(std::string text, SDL_Color color, TTF_Font *font, const SDL_Renderer *renderer);

        void SetText(std::string newText);
        std::string GetText();

        void SetLocation(int x, int y);
        void SetLocation(SDL_Point point);

        SDL_Color GetColor( void );
        void SetColor(SDL_Color color);

        //Renderable implementation
        SDL_Rect *GetRectangle( void );
        SDL_Texture *GetTexture( void );

        virtual ~Text();

    protected:
        void UpdateTexture();
    private:
        std::string pText;
        TTF_Font *pFont;
        SDL_Rect *pRect;
        SDL_Texture *pTexture;
        SDL_Color pColor;
        const SDL_Renderer *pRenderer;
};

#endif // TEXT_H
