# include "game.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
Game::Game() {
    SDL_Init(0);
    SDL_CreateWindowAndRenderer(360, 240, 0, &win, &ren);
    SDL_SetWindowTitle(win, "Our first game!!!");
    running = true;
    count = 0;
    loop(); 
}

Game::~Game() {
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}

void Game::loop() {
    while (running) {

/*
frameCount: 用于记录当前秒内渲染的帧数。
timerFPS: 用于计算当前帧的渲染时间。ms
lastFrame: 用于记录上一次渲染的时间戳，ms

*/
        lastFrame = SDL_GetTicks();// ms
        static int lastTime;
        if(lastFrame >= (lastTime + 1000)) {
            lastTime = lastFrame;
            frameCount = 0;
            count++;
        }
        render();
        input();
        update();

        if(count > 3) running = false; // 运行3秒后退出
        
    }
}


void Game::render(){
    SDL_SetRenderDrawColor(ren,255,0,0,255);
    /*
255, 0, 0: 表示颜色的 RGB 值，这里是红色（R=255，G=0，B=0）。
255: 表示颜色的 alpha 值（透明度），255 表示完全不透明。
    */
    SDL_Rect rect;
    rect.x = 0; // 矩形的左上角 x 坐标
    rect.y = 0; // 矩形的左上角 y 坐标
    rect.w = 360; // 矩形的宽度
    rect.h = 240; // 矩形的高度
    SDL_RenderFillRect(ren, &rect);//  使用当前渲染器ren的绘制颜色填充一个矩形区域。

    frameCount++;
    int timerFPS = SDL_GetTicks() - lastFrame; // 计算当前帧的渲染时间。ms
    if (timerFPS < (1000 / 60)) { // 如果渲染时间小于 60 FPS 的时间间隔，则延迟以保持帧率。
        SDL_Delay((1000 / 60) - timerFPS);
    }

    SDL_RenderPresent(ren); // 更新屏幕显示:将渲染器的内容更新到屏幕上。
// 将之前通过渲染器绘制的所有内容（如矩形、线条等）显示到窗口中。没有这行代码，绘制的内容不会实际显示在屏幕上。
}
