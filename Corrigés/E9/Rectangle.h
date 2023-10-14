// Rectangle.h

#pragma once
#include "Forme.h"
#include "Segment.h"

class Rectangle : public Forme
{
public:
    Rectangle(const Segment& segLarg, double haut);
    double perimetre() const;
    double surface() const;
    void afficherType() const;

private:
    Segment segLargeur;
    double hauteur;

};
