#ifndef COLLIDER_H
#define COLLIDER_H


class Collider
{
    public:
        float getX1() =0;
        float getX2() =0;
        float getY1() =0;
        float getY2() =0;
        bool isSolid() =0;
    protected:
    private:
};

#endif // COLLIDER_H
