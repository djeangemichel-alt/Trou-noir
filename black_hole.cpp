
#include <SFML/Graphics.hpp>
#include <optional>

int main()
{
    sf::RenderWindow window(
        sf::VideoMode({800u, 600u}),
        "Simulation de trou noir"
    );
    sf::CircleShape cercle(50.f);

    cercle.setFillColor(sf::Color::Red);

    cercle.setPosition({350.f, 250.f});
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())// pollEvent la method recupere les event en attente,causé par l'homme ou le systeme 
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }
        
        window.clear(sf::Color::White);
        window.draw(cercle);
        window.display();
    }

    return 0;
}


   

    
    

   