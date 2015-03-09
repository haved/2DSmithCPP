#ifndef DISPLAY_H
#define DISPLAY_H
#ifdef _WIN32
#include <windows.h>
#endif //_WIN32
#include <SDL2/SDL.h>

class Display
{
    public:
        Display(int width, int height, const char* title);
        virtual ~Display();
        void Resize(int width, int height);
        void Clear(float r, float g, float b, float a);
        void Update();
        void Close();
        bool isClosed();
        int getWidth();
        int getHeight();
    protected:
    private:
        SDL_Window* m_window;
        SDL_GLContext m_glContext;
        bool m_closed = false;
        int m_width;
        int m_height;
};

#endif // DISPLAY_H
