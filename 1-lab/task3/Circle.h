#pragma once

#include "../task1/Letter/Color.h"
#include "../task1/Letter/Position.h"

class Circle
{
    float m_radius;
    Position m_position;
    Color m_fillColor;
    Color m_outlineColor;
public:
    Circle(float radius, Position position, Color fillColor, Color outlineColor)
        : m_radius(radius),
          m_position(position),
          m_fillColor(fillColor),
          m_outlineColor(outlineColor) {}

    int GetRadius() { return m_radius; }
    Position GetPosition() { return m_position; }
    Color GetFillColor() { return m_fillColor; }
    Color GetOutlineColor() { return m_outlineColor; }
};
