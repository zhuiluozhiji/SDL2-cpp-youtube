#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

#include <iostream>
using namespace std;

class Game{
public:
    Game();
    ~Game();
    void loop();
    void update(){}
    void input(){}
    void render();
private:
    SDL_Renderer* ren;
    SDL_Window* win;
    bool running;
    int count;// 记录游戏运行的秒数
    int frameCount , timerFPS , lastFrame;
/*
frameCount: 用于记录当前秒内渲染的帧数。
timerFPS: 用于计算当前帧的渲染时间。ms
lastFrame: 用于记录上一次渲染的时间戳，ms

*/
};



#endif // GAME_H