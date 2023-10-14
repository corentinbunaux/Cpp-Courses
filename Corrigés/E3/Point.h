// Point.h

#pragma once

class Point
{
public:
    Point();
    Point(float x0, float y0);
    float getX() const          { return x; }
    float getY() const          { return y; }
    void setX(float nouvX)      { x = nouvX; }
    void setY(float nouvY)      { y = nouvY; }
    void afficher() const;
    bool egalA(const Point& point2) const;
    float distance(const Point& point2) const;

private:
    float x, y;
};
