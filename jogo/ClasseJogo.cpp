#include "ClasseJogo.h"

ClasseJogo::ClasseJogo():
	window(sf::VideoMode(1000, 800), "SFML works!")
{
    jogador1 = new Jogador();
    jogador1->setWindow(&window);
    fase1 = new Fase(jogador1, &window);
    LEs = fase1->getListaEntidades();
    LOs = fase1->getListaObstaculos();
    LIs = fase1->getListaInimigos();
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

        fase1Prin();
    }
}
void ClasseJogo::fase1Prin()
{
    window.clear();
    for (int i = 0; i < LEs->LEs.getLen(); i++)
    {
        Entidade* temp = LEs->LEs.getItem(i);
        temp->draw();
    }
    int flag = 0;
    for (int i = 0; i < LOs->LOs.getLen(); i++)
    {
        Obstaculo* temp = LOs->LOs.getItem(i);
        if (jogador1->getFronteiras() == temp->getFronteiras())
        {
            flag = 1;
        }
    }
    jogador1->move();
    if (flag == 0)
    {
        jogador1->gravidade();
    }
    window.display();
}
ClasseJogo::~ClasseJogo()
{

}
