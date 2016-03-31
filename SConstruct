
env = Environment(
        tools=['mingw'],
        CPPPATH='include',
        CFLAGS='-m32 -Wall -Wpedantic -Wextra --std=c99',
        LIBS=['mingw32', 'SDL2main', 'SDL2'],
        LIBPATH='lib/sdl204'
    )

env.Program(
        'build/grok', 
        source=['src/main.c'],
    )