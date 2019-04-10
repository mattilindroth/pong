#ifndef INPUTLISTENER_H_INCLUDED
#define INPUTLISTENER_H_INCLUDED

#include <SDL.h>

class InputListener {
public:

    virtual void KeyboardInput(bool isDown) {};

};

#endif // INPUTLISTENER_H_INCLUDED
