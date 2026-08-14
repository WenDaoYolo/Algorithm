#include<iostream>
#include<windows.h>
#include<SDL.h>
#include<SDL_ttf.h>
#define WIDTH 500
#define HEIGHT 500

bool stop=false;
SDL_Window* win;
SDL_Surface* win_surf;
SDL_Event event;
SDL_Rect rect={WIDTH/2-100/2,HEIGHT/2-100/2,50,50};

void Init()
{
    if(SDL_Init(SDL_INIT_EVERYTHING)<0)
    {
        SDL_Log("%s",SDL_GetError());
        stop=true;
    }

    win=SDL_CreateWindow
    (
        "BmpTest",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WIDTH,
        HEIGHT,
        SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE
    );  

    if(win==NULL)
    {
        stop=true;
    }

    win_surf=SDL_GetWindowSurface(win);

    if(win==NULL)
    {
        stop=true;
    }
}

void Destroy()
{
    SDL_FreeSurface(win_surf);
    SDL_DestroyWindow(win);
}

int main(int argc,char* argv[])
{
    Init();

    while(!stop)
    {
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_QUIT:
                    stop=true;
                    break;
            }
        }
    }

    Destroy();
    return 0;
}