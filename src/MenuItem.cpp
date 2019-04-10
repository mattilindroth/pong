#include "MenuItem.h"

SDL_Texture *CreateTextTexture(const char *label, SDL_Color color, SDL_Renderer *renderer) {
    SDL_Surface *textSurface;
    TTF_Font* Sans ;
    SDL_Texture *texture;

    Sans = TTF_OpenFont("ABeeZee-Regular.otf", 16);
    if(Sans == NULL ) {
        fprintf(stderr, "Font is null. Exiting...\n");
        return NULL;
    }

    textSurface = TTF_RenderText_Solid(Sans, label, color);
    if (textSurface == NULL) {
        printf("Could not create surface from text. Exiting...\n");
        return NULL;
    }

    SDL_Rect *textRect = (struct SDL_Rect*)malloc(sizeof(SDL_Rect));
    textRect->x = 0;
    textRect->y = 0;
    textRect->w = 100;
    textRect->h = 100;
    texture = SDL_CreateTextureFromSurface(renderer,textSurface);
    return texture;

}

MenuItem::MenuItem(std::string label, SDL_Renderer *renderer) : SceneObject((SDL_Rect*)malloc(sizeof(SDL_Rect)), CreateTextTexture(label.c_str() , {50,50, 255}, renderer))
{
    fprintf(stderr, "In the MenuItem constructor.\n");

    this->pTextureSelected = CreateTextTexture(label.c_str(), {25, 255, 25}, renderer);

    pLabel = label;
    this->GetRectangle()->x = 100;
    this->GetRectangle()->y = 100;
    this->GetRectangle()->h = 100;
    this->GetRectangle()->w = 100;
}

void MenuItem::SetLabel(std::string newLabel) {
    pLabel = newLabel;
}

std::string MenuItem::GetLabel( void ) {
    return pLabel;
}

bool MenuItem::IsSelected( void ) {
    return pIsSelected ;
}

void MenuItem::SetSelected( bool selected ) {
    if(selected) {
        pTemporaryTexture = pTexture;
        pTexture = pTextureSelected;
    } else {
        pTexture = pTemporaryTexture;
    }
    pIsSelected = selected;
}

MenuItem::~MenuItem()
{
    if(pTextureSelected != NULL) {
        SDL_DestroyTexture(pTextureSelected);
    }
}
