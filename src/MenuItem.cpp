#include "MenuItem.h"

MenuItem::MenuItem(std::string label, const SDL_Renderer *renderer) : Renderable()
{
    fprintf(stderr, "In the MenuItem constructor.\n");
    SDL_Color color;
    color.r = 50; color.g = 50; color.b = 255;
    TTF_Font *font = TTF_OpenFont("ABeeZee-Regular.otf", 16);
    this->pText = new Text(label, color, font, renderer);

    this->pIsSelected = false;
    fprintf(stderr, "Exiting MenuItem constructor.\n");
}

void MenuItem::SetLabel(std::string newLabel) {
    this->pText->SetText(newLabel);
}

std::string MenuItem::GetLabel( void ) {
    return this->pText->GetText();
}

bool MenuItem::IsSelected( void ) {
    return pIsSelected ;
}

SDL_Rect *MenuItem::GetRectangle( void )  {
    return this->pText->GetRectangle();
}

SDL_Texture *MenuItem::GetTexture( void )  {
    return this->pText->GetTexture();
}

void MenuItem::SetSelected( bool selected ) {
    SDL_Color color;
    if(selected) {
        color.r = 255; color.g = 255; color.b = 255;
    } else {
        color.r = 50; color.g = 50; color.b = 255;
    }
    this->pText->SetColor(color);
}

MenuItem::~MenuItem()
{
    if(pText != NULL) {
        delete pText;
    }
}
