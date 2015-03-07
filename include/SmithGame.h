#ifndef SMITHGAME_H
#define SMITHGAME_H

#include "Game.h"
#include "Scene.h"

class SmithGame : public Game
{
    public:
        SmithGame();
        virtual ~SmithGame() override;
        void Update() override;
        void Render() override;
    protected:
    private:
        Scene* currentScene;
};

#endif // SMITHGAME_H
