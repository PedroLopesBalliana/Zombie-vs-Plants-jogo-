#pragma once
#include "Ente.h"

class Menu : public Ente
{
private:
	class Botao
	{
	private:
		sf::RectangleShape botao;
	public:
		Botao()
		{
			botao.setSize(sf::Vector2f(300.f, 100.f));
			botao.setFillColor(sf::Color::Blue);
		}
		void mudarPosi(int x, int y)
		{
			botao.setPosition(x, y);
		}
		sf::RectangleShape getRect()
		{
			return botao;
		}
		~Botao()
		{

		}
	};
	sf::Vector2i posi_mouse;
	sf::Vector2f mouse_coord;
	sf::Vector2f corrigir_coord;
	Botao botaoFase1;
	Botao botaoFase2;
	Botao botaoRanking;
public:
	Menu(GerenciadorGrafico* ge);
	~Menu();
	void desenharBotoes();
	void executar();
};
