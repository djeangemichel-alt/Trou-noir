
#include <SFML/Graphics.hpp>
#include "2D_lensing.hpp"
#include <optional>

int main()
{
    sf::RenderWindow window(
        sf::VideoMode({800u, 600u}),
        "Simulation de trou noir"
    );

    sf::CircleShape cercle(50.f);
    cercle.setFillColor(sf::Color::Red);
    cercle.setPosition({350.f,250.f});

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event-> is<sf::Event::Closed>())
            {
                window.close();
            }
        }
        window.clear(sf::Color::Black);

        window.draw(cercle);
    
        window.display();
    }

    return 0;
}
