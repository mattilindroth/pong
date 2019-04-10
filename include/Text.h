#ifndef TEXT_H
#define TEXT_H

#include <SDL.h>
#include <SDL2\SDL_ttf.h>
#include <string>

class Text
{
    public:
        Text(std::string text, TTF_Font *font);

        void SetText(std::string newText);
        std::string GetText();

        void SetLocation(int x, int y);
        void SetLocation(SDL_Point point);

        SDL_Rect GetRectangle();

        virtual ~Text();

    protected:

    private:
        std::string pText;
        TTF_Font *pFont;
        SDL_Rect *pRect;
};

#endif // TEXT_H
