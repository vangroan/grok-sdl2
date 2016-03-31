
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "sdl204/SDL.h"


void assert(bool condition, const char* message) {
    if (!condition) {
        if (message == NULL) {
            printf("Assertion Failed\n");   
        } else {
            printf("%s\n", message);
        }
        SDL_Quit();
        exit(EXIT_FAILURE);
    }
}


int main(int argc, char *arg[]) {
    printf("Starting...\n");

    // Print Provided arguments
    for (int c = 0; c < argc; c++) {
        printf("%s\n", arg[c]);
    }

    assert(SDL_Init(SDL_INIT_VIDEO) == 0, SDL_GetError());

    SDL_Window *win = SDL_CreateWindow("Grok", 100, 100, 320, 240, SDL_WINDOW_SHOWN);
    assert(win != NULL, SDL_GetError());

    SDL_Renderer *ren = SDL_CreateRenderer(win, -1,  SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    assert(ren != NULL, SDL_GetError());

    SDL_RendererInfo renInfo;
    assert(SDL_GetRendererInfo(ren, &renInfo) == 0, SDL_GetError());
    printf("Renderer: %s\n", renInfo.name);

    SDL_Event evt;
    bool running = true;

    while (running) {
        while (SDL_PollEvent(&evt)) {
            switch(evt.type) {
                case SDL_QUIT: running = false; break;
            }
        }

        SDL_RenderClear(ren);

        // All drawing is done to a buffer. Present will do the actual
        // drawing to the window.
        SDL_RenderPresent(ren);
    }

    SDL_DestroyWindow(win);
    SDL_Quit();
    printf("Done...\n");
    return EXIT_SUCCESS;
}
