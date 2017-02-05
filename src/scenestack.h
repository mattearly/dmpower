#include "sdl_graphics.h"
#include "texture.h"
#include <stack>

class SceneStack {

public:
    SceneStack(){}
    ~SceneStack(){}
    void mainscreen(SDL_graphics &graphics_engine);

private:


    int CycleRight_5(const int &, const int &);


//    std::stack<SceneStack> running_scenes;

};