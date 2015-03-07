#ifndef SCENE_H
#define SCENE_H

#include <string>
#include <vector>
#include <memory>

#include "Entity.h"

class Scene
{
    public:
        Scene();
        virtual ~Scene();
        void AddEntity(std::shared_ptr<Entity> e);
        void RemoveEntity(std::shared_ptr<Entity> e);
        void Update();
        void Render();
        std::string GetState() const {return state;};
    protected:
    private:
        std::string state;
        std::vector<std::shared_ptr<Entity>> entityList;
};

#endif // SCENE_H
