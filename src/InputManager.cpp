#include "InputManager.h"

InputManager::InputManager()
{
    this->pMap = std::map<int, std::vector<funcPtr> >();
}

void InputManager::RegisterInputListener(InputListener listener, SDL_Scancode keyCode)
{
    std::vector<funcPtr> functionHandlers;
    funcPtr ptr = &(listener.KeyboardInput);

    std::map<int, std::vector<funcPtr> >::iterator it = this->pMap.find((int)keyCode);
    if(it == pMap.end()) {

        functionHandlers.push_back(ptr);
        pMap.insert(std::pair<SDL_Keycode, std::vector<funcPtr> >((int)keyCode, functionHandlers));
    } else {
        it->second.push_back(ptr);
    }
}

void InputManager::UnRegisterInputListener(InputListener listener)
{

}


InputManager::~InputManager()
{

}
