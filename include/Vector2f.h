#ifndef VECTOR2F_H
#define VECTOR2F_H


class Vector2f
{
    public:
        Vector2f();
        Vector2f(float x, float y);
        void xy(float x, float y);
        float x=0,y=0;
        bool IsNull();
        void Normalize();
        float GetLength();

        void Multiply(float f);
        void Multiply(float x2, float y2);
        void Multiply(Vector2f v);
        void Add(float x2, float y2);
        void Add(Vector2f v);
        void Divide(float d);
        void Divide(float x2, float y2);
        void Divide(Vector2f v);
    protected:
    private:
};

#endif // VECTOR2F_H
