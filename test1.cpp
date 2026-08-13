#include<SDL.h>
#include<iostream>

int main(int argc, char *argv[])
{
    if(SDL_Init(SDL_INIT_EVERYTHING)<0) //初始化SDL的子系统，初始成功返回0，否则返回负数
    {
        SDL_Log("%s",SDL_GetError());   //获取最近的错误并输出
        std::cout<<"yes"<<std::endl;
        return -1;
    }

    SDL_Window* win=SDL_CreateWindow    //创建一个窗口并返回其句柄(即用于管理窗口的指针)，创建失败返回NULL
    (
        "First SDL Program",            //窗口标题
        SDL_WINDOWPOS_CENTERED,         //窗口水平位置，以屏幕左上角为起点，从0开始
        SDL_WINDOWPOS_CENTERED,         //窗口垂直位置，以屏幕左上角为起点，从0开始
        500,                            //窗口的宽度，单位像素
        500,                            //窗口的高度，单位像素
        SDL_WINDOW_SHOWN                //窗口的标志位，默认SDL_WINDOW_SHOWN(显示窗口)
    );

    SDL_Delay(5000);                    //窗口延迟，单位毫秒，注意，会让窗口暂时陷入沉睡，无法响应事件

    SDL_DestroyWindow(win);             //销毁窗口(传入对应的窗口句柄)
    SDL_Quit();                         //退出SDL系统
    return 0;
}