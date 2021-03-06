#include "Scene.h"
#include <iostream>

Scene::Scene(float width, float height)
{
    this->width = width;
    this->height = height;
}

Scene::~Scene()
{
    std::cout << "Scene was deconstructed" << std::endl;
}

void Scene::Update()
{
    for(unsigned int i = 0; i < entityList.size(); i++)
    {
        if(entityList.at(i).use_count() <= 0)
        {
            std::cout << "Removed empty Entity pointer from scene" << std::endl;
            entityList.erase(entityList.begin()+i);
            i--;
        }
        entityList.at(i)->Update(this);
        if(entityList.at(i)->isDead())
        {
            std::cout << "Removed dead Entity from scene" << std::endl;
            entityList.erase(entityList.begin()+i);
            i--;
        }
    }
}

void Scene::Render()
{
    for(unsigned int i = 0; i < entityList.size(); i++)
    {
        entityList.at(i)->Render(this);
    }
}

void Scene::AddEntity(std::shared_ptr<Entity> e)
{
    entityList.push_back(e);
}

std::vector<std::shared_ptr<Entity>>* Scene::GetEntityList()
{
    return &entityList;
}

int Scene::GetEntityAmount()
{
    return entityList.size();
}

Entity* Scene::GetEntityAt(int index)
{
    return entityList.at(index).get();
}
