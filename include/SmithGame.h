#ifndef SMITHGAME_H
#define SMITHGAME_H

#include "Game.h"
#include "Scene.h"
#include <memory>
#include "PlayerEntity.h"

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
        std::shared_ptr<PlayerEntity> player;
};

#endif // SMITHGAME_H
