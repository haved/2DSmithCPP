#include "Display.h"
#include <GL/glew.h>
#include <GL/gl.h>
#include <iostream>

Display::Display(int width, int height, const char* title)
{
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    Display::m_window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
    Display::m_glContext = SDL_GL_CreateContext(Display::m_window);

    GLenum status = glewInit();

    if(status != GLEW_OK)
    {
        std::cerr << "Failed to initialize GL/glew!" << std::endl;
        SDL_Quit();
    }

    Display::Resize(width, height);

    std::cout << "Display was constructed" << std::endl;
}

Display::~Display()
{
    SDL_GL_DeleteContext(Display::m_glContext);
    SDL_DestroyWindow(Display::m_window);
    std::cout << "Display was deconstructed" << std::endl;
}

void Display::Resize(int width, int height)
{
    Display::m_width = width;
    Display::m_height = height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION_MATRIX);
    glLoadIdentity();
    glOrtho(0, width, height, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW_MATRIX);
}

void Display::Clear(float r, float g, float b, float a)
{
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Display::Update()
{
    SDL_GL_SwapWindow(Display::m_window);
}

void Display::Close()
{
    Display::m_closed = true;
}

bool Display::isClosed()
{
    return Display::m_closed;
}

int Display::getWidth()
{
    return Display::m_width;
}

int Display::getHeight()
{
    return Display::m_height;
}
