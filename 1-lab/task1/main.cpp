#include <SFML/Graphics.hpp>

#include "Letter/Letter.h"
#include "Letter/Strategy/StrategyE.h"
#include "Letter/Strategy/StrategyT.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1200, 800), "1-lab");

    Letter T = Letter(
         Color(255, 0, 0),
         Position(100, 100),
         std::make_unique<StrategyT>()
     );

    Letter E = Letter(
         Color(0, 255, 0),
         Position(350, 100),
         std::make_unique<StrategyE>()
     );

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::Black);
        // рисовать
        T.Draw(window);
        E.Draw(window);
        window.display();
    }

    return 0;
}
