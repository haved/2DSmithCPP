#ifndef RESOURCES_H
#define RESOURCES_H

class Resources
{
    public:
    #ifdef _WIN32
        static char split = '\\'
    #else
        static char split = '/'
    #endif
}

#endif //RESOURCES_H
