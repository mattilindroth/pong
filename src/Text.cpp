#include "Text.h"

void Text::UpdateTexture() {
    SDL_Surface *textSurface;

    textSurface = TTF_RenderText_Solid(this->pFont, this->pText.c_str(), this->pColor);
    if (textSurface == NULL) {
        printf("Could not create surface from text. Exiting...\n");
        return ;
    }
    if(this->pTexture != NULL) {
        SDL_DestroyTexture(this->pTexture);
    }
    this->pTexture = SDL_CreateTextureFromSurface((SDL_Renderer*)this->pRenderer, textSurface);
    SDL_FreeSurface(textSurface);
}

Text::Text(std::string text, SDL_Color color , TTF_Font *font, const SDL_Renderer *renderer)
{
    fprintf(stderr, "In the Text constructor.\n");
    this->pTexture = NULL;
    this->pText = text;
    this->pFont = font;
    this->pRect = (SDL_Rect*)malloc(sizeof(SDL_Rect));
    // TTF_SizeText(pFont, this->pText.c_str(), &this->pRect->w, &this->pRect->h);
    this->pRect->w = 100;
    this->pRect->h = 20;
    this->pColor = color;
    this->pRenderer = renderer;
    UpdateTexture();
}

SDL_Color Text::GetColor( void ) {
    return this->pColor;
}

void Text::SetColor(SDL_Color color) {
    this->pColor = color;
    UpdateTexture();
}

void Text::SetText(std::string newText) {
    this->pText = newText;
    TTF_SizeText(pFont, this->pText.c_str(), &this->pRect->w, &this->pRect->h);
    UpdateTexture();
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

SDL_Texture *Text::GetTexture( void ) {
    return this->pTexture;
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
    if(this->pTexture != NULL) {
        SDL_DestroyTexture(this->pTexture);
        this->pTexture = NULL;
    }
}
