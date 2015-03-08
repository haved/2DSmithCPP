#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/gl.h>
#include <string>

class Texture
{
    public:
        Texture(std::string path);
        virtual ~Texture();
        void Bind();
    protected:
    private:
        GLuint texture_id;
};

#endif // TEXTURE_H
