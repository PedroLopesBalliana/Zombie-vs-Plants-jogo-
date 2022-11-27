#pragma once
#include "Ente.h"
#include "Floresta.h"
#include "Jogador.h"
#include "Masmorra.h"

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
			botao.setFillColor(sf::Color::Transparent);
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
	sf::Texture rankText;
	sf::Text posicoesRank;
	sf::Font posicoesFont;
	sf::Vector2i posi_mouse;
	sf::Vector2f mouse_coord;
	sf::Vector2f corrigir_coord;
	sf::Vector2f aux;
	Botao botaoFase1;
	Botao botaoFase2;
	Botao botaoRanking;
	Entidades::Personagens::Jogador *jogador1;
	Entidades::Personagens::Jogador* jogador2;
	Fases::Floresta* fase1;
	Fases::Masmorra* fase2;
	bool rankBool;
public:
	Menu(Gerenciadores::GerenciadorGrafico* ge);
	~Menu();
	void desenharBotoes();
	void executar();
	void mostrarRank();
};
