#include "Text.h"

Text::Text(std::string text, TTF_Font *font)
{
    this->pText = text;
    this->pFont = font;
    this->pRect = (SDL_Rect*)malloc(sizeof(SDL_Rect));
    TTF_SizeText(pFont, this->pText.c_str(), &this->pRect->w, &this->pRect->h);
}

void Text::SetText(std::string newText) {
    this->pText = newText;
    TTF_SizeText(pFont, this->pText.c_str(), &this->pRect->w, &this->pRect->h);
}

std::string Text::GetText() {
    return this->pText;
}

void Text::SetLocation(int x, int y) {
    this->pRect->x = x;
    this->pRect->y = y;
}

void Text::SetLocation(SDL_Point point) {
    this->pRect->x = point.x;
    this->pRect->y = point.y;
}

SDL_Rect *Text::GetRectangle() {
    return this->pRect;
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
