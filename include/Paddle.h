#ifndef PADDLE_H
#define PADDLE_H

//How inheritance works in C++?
class Paddle : GameItem(surface, rectangle, "Paddle")
{
    public:
        Paddle(SDL_Surface surface, SDL_Rect &rectangle);
        virtual ~Paddle();

    protected:

    private:
};

#endif // PADDLE_H
