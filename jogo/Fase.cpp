#include "Fase.h"

Fases::Fase::Fase():Ente()
{
	if (!pontuacaoFonte.loadFromFile("assets/Menu/calibri.ttf"))
	{
		std::cout << "falhou a textura :(" << std::endl;
	}
}
Fases::Fase::~Fase()
{
}
void Fases::Fase::inicializaElementos()
{
}
Listas::ListaEntidades* Fases::Fase::getListaEntidades()
{
	return listaEntidades;
}
void Fases::Fase::executar()
{

}
void Fases::Fase::setPontos()
{
	memoria.lerArquivo();
	int digito;
	string nome1, nome2;
	int flag=0;
	texto.setFont(pontuacaoFonte);
	texto.setPosition(300.f, 300.f);
	texto.setFillColor(sf::Color::Red);
	texto.setCharacterSize(40);
	std::cout << "Insira o nome do jogador 1:" << endl;
	while (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) || flag == 0)
	{
		if (geren_graf->getWindow()->pollEvent(evento))
		{
			if (evento.type == sf::Event::TextEntered)
			{
				digito = evento.text.unicode;
				if (evento.text.unicode < 128 && evento.text.unicode != 8)
				{
					nome1 += static_cast<char>(digito);
					texto.setString("digite nome do jogador 1  " + nome1);
					flag = 1;
					geren_graf->getWindow()->draw(texto);
					geren_graf->getWindow()->display();
				}
			}
		}
	}
	texto.setPosition(300.f, 400.f);
	pontuacoes.insert(pair<string, float>(nome1, j1->getPontuacao()));
	std::cout << "Insira o nome do jogador 2:" << endl;
	while (true)
	{
		if (geren_graf->getWindow()->pollEvent(evento))
		{
			if (evento.type == sf::Event::TextEntered)
			{
				digito = evento.text.unicode;
				if (evento.text.unicode < 128 && evento.text.unicode != 8)
				{
					nome2 += static_cast<char>(digito);
					texto.setString("digite nome do jogador 2" + nome2);
					geren_graf->getWindow()->draw(texto);
					geren_graf->getWindow()->display();
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && nome2.size() > 3)
				break;
		}
	}
	pontuacoes.insert(pair<string, float>(nome2, j2->getPontuacao()));
	std::cout << "volte a tela do jogo :)";
	for (map<string, float>::iterator it = pontuacoes.begin();
		it != pontuacoes.end(); it++)
	{
		memoria.salvarPontos((*it).first, (*it).second);
	}
	//inserir função de salvamento de arquivo
	memoria.atualizaArq();
}