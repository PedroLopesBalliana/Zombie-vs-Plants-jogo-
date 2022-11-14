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
	Botao botaoFase1;
	Botao botaoFase2;
	Botao botaoRanking;
public:
	Menu(GerenciadorGrafico* ge);
	~Menu();
	void executar();
};
