#pragma once
#include <SFML/Graphics.hpp>
namespace Gerenciadores
{
	class GerenciadorGrafico
	{
	private:
		sf::RenderWindow window;
		static GerenciadorGrafico* pGrafico;
		GerenciadorGrafico();
	public:
		~GerenciadorGrafico();
		void desenharEntidades(sf::Sprite sp);
		sf::RenderWindow* getWindow();
		GerenciadorGrafico* getGgr();
		void limpaJanela();
		void displayJanela();
		const bool pegarJanela();
	};
}

