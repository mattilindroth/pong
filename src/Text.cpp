#include "Text.h"

Text::Text(std::string text, TTF_Font *font)
{
    this->pText = text;
    this->pFont = font;
    this->pRect = (SDL_Rect*)malloc(sizeof(SDL_Rect));
}

Text::~Text()
{
    if(this->pRect != NULL) {
        free(this->pRect);
        this->pRect = NULL;
    }
    if(this->pFont != NULL) {
        TTF_CloseFont(this->pFont);
        this->pFont = NULL;
    }
}
