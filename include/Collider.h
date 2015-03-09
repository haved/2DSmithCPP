#ifndef COLLIDER_H
#define COLLIDER_H

class Collider
{
    public:
        virtual float getX1() =0;
        virtual float getX2() =0;
        virtual float getY1() =0;
        virtual float getY2() =0;
        virtual bool isSolid() =0;
    protected:
    private:
};

#endif // COLLIDER_H
