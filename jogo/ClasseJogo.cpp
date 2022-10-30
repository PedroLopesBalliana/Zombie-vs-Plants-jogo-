#include "ClasseJogo.h"

ClasseJogo::ClasseJogo():
	window(sf::VideoMode(1000, 800), "SFML works!")
{
    jogador1 = new Jogador();
    jogador1->setWindow(&window);
    fase1 = new Fase(jogador1);
    LEs = fase1->getListaEntidades();
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

        jogador1->move();
        window.clear();
        for (int i = 0; i < LEs->LEs.getLen(); i++)
        {
            Entidade* temp = LEs->LEs.getItem(i);
            temp->draw();
        }
        window.display();
    }
}
ClasseJogo::~ClasseJogo()
{

}
