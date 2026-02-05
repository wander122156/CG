#pragma once
#include <memory>
#include <memory>

#include "Color.h"
#include "Position.h"
#include "Strategy/IDrawStrategy.h"
#include "Strategy/StrategyT.h"

class Letter {
    Color m_color;
    Position m_position;
    std::unique_ptr<IDrawStrategy> m_drawStrategy;
public:
    Letter(Color color, Position position, std::unique_ptr<IDrawStrategy> drawStrategy)
    : m_color(color), m_position(position), m_drawStrategy(std::move(drawStrategy))
    {

    }

    void SetColor(Color color)
    {
        m_color = color;
    }

    void SetPosition(Position position)
    {
        m_position = position;
    }

    void Draw(sf::RenderWindow& window)
    {
        m_drawStrategy->Draw(window, m_color, m_position);
    }
};
