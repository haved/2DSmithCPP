#ifndef GAME_H
#define GAME_H

class Game
{
    public:
        virtual ~Game();
        virtual void Update();
        virtual void Render();
    protected:
    private:
};

#endif // GAME_H
