#pragma once

#include <thread>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Circle.h"


class Canvas
{
    sf::RenderWindow &m_window;


    void DrawPixel(int x, int y, Color color)
    {
        sf::Vertex point(
            sf::Vector2f(x, y),
            sf::Color(color.r, color.g, color.b));
        m_window.draw(&point, 1, sf::PrimitiveType::Points);
    }

    void Add8Points(int xc, int yc, int x, int y, Color color)
    {
        DrawPixel(xc + x, yc + y, color);
        DrawPixel(xc - x, yc + y, color);
        DrawPixel(xc + x, yc - y, color);
        DrawPixel(xc - x, yc - y, color);
        DrawPixel(xc + y, yc + x, color);
        DrawPixel(xc - y, yc + x, color);
        DrawPixel(xc + y, yc - x, color);
        DrawPixel(xc - y, yc - x, color);
    }

    void DrawCircleBresenham(Circle circle)
    {
        int xc = circle.GetPosition().m_x; // центр круга
        int yc = circle.GetPosition().m_y;

        int x = 0;
        int y = circle.GetRadius();
        int d = 3 - 2 * circle.GetRadius();

        Add8Points(xc, yc, x, y, circle.GetOutlineColor());
        while (y >= x)
        {
            if (d > 0)
            {
                y--;
                d = d + 4 * (x - y) + 10;
            } else
                d = d + 4 * x + 6;

            x++;

            Add8Points(xc, yc, x, y, circle.GetOutlineColor());

            // std::this_thread::sleep_for(std::chrono::milliseconds(50));
            // m_window.display();
        }
    }

public:
    Canvas(sf::RenderWindow &window)
        : m_window(window) {}

    void Draw(Circle circle)
    {
        DrawCircleBresenham(circle);
    }
};
