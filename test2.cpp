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
        SDL_WINDOWPOS_CENTERED,         //窗口水平位置，以屏幕左上角为起点，从0开始（所有矩形的坐标都为左上角顶点的坐标）
        SDL_WINDOWPOS_CENTERED,         //窗口垂直位置，以屏幕左上角为起点，从0开始
        500,                            //窗口的宽度，单位像素
        500,                            //窗口的高度，单位像素
        SDL_WINDOW_SHOWN                //窗口的标志位，默认SDL_WINDOW_SHOWN(显示窗口)
    );
    ///////////////////////////////////////////////////////////////////////////////////////////
    
    bool stop=false;
    SDL_Event event;                    //消息事件
    while(!stop)
    {
        if(SDL_PollEvent(&event))       //向消息队列中取出一个事件并写回，有事件返回1否则返回0
        {
            if(event.type==SDL_QUIT)    //事件结构体的type成员表示事件类型，SDL_QUIT为窗口退出    
            {
                stop=true;
            }
        }
    }
    
    


    ///////////////////////////////////////////////////////////////////////////////////////////
    SDL_DestroyWindow(win);             //销毁窗口(传入对应的窗口句柄)
    SDL_Quit();                         //退出SDL系统
    return 0;
}