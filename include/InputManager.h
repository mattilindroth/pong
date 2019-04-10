#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "InputListener.h"
#include <map>
#include <vector>

typedef void(InputListener::*funcPtr)(bool);

class InputManager
{
    public:
        InputManager();

        void RegisterInputListener(InputListener listener, SDL_Scancode code);
        void UnRegisterInputListener(InputListener listener);

        virtual ~InputManager();

    protected:

    private:
        //Monstrosity below is:
        //A map of key value pairs, where key is scancode and value is a list of function pointers
        std::map<int, std::vector<funcPtr> > pMap;
};

#endif // INPUTMANAGER_H
