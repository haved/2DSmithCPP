#include "Texture.h"
#include "stb_image.h"
#include "RenderHelper.h"
#include <iostream>

Texture::Texture(std::string path)
{
    RenderHelper::EnableTextures();
    int width, height, numComponents;

    unsigned char* data = stbi_load(path.c_str(), &width, &height, &numComponents, 4);

    if(data == NULL)
    {
        std::cerr << "The image " << path << "failed to load!" << std::endl;
        return;
    }

    glGenTextures(1, &texture_id);
    glBindTexture(GL_TEXTURE_2D, texture_id);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );

    glTexImage2D(GL_TEXTURE_2D, 0, numComponents, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    stbi_image_free(data);
}

Texture::~Texture()
{
    glDeleteTextures(1, &texture_id);
    std::cout << "Unloaded texture" << std::endl;
}

void Texture::Bind()
{
    glBindTexture(GL_TEXTURE_2D, texture_id);
}
