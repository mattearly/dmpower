#include "sdl_graphics.h"
#include "texture.h"
#include <stack>

class SceneStack {

public:
    SceneStack(){}
    ~SceneStack(){}
    void mainscreen(SDL_graphics &graphics_engine);

private:

    void menuScene1_characters(SDL_graphics &graphics_engine);
    void menuScene2_magic_items(SDL_graphics &graphics_engine);
    void menuScene3_(SDL_graphics &graphics_engine);
    void menuScene4(SDL_graphics &graphics_engine);
    void menuScene5(SDL_graphics &graphics_engine);


    int CycleRight_5(const int &, const int &);
    bool newSceneProcced = false;

//    std::stack<SceneStack> running_scenes;

};