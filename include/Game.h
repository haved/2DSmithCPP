#ifndef GAME_H
#define GAME_H

class Engine;

class Game
{
    public:
        Game(Engine* engine);
        virtual ~Game();
        virtual void Update();
        virtual void Render();
    protected:
        Engine* engine;
    private:
};

#endif // GAME_H
