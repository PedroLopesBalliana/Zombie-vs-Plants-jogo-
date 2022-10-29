#include "ClasseJogo.h"

ClasseJogo::ClasseJogo():
	window(sf::VideoMode(1000, 800), "SFML works!")
{
    jogador1.setWindow(&window);
    Executar();
}
void ClasseJogo::Executar()
{
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        jogador1.move();
        window.clear();
        jogador1.draw();
        window.display();
    }
}
ClasseJogo::~ClasseJogo()
{

}
