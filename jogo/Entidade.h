#pragma once
#include <SFML/Graphics.hpp>
namespace Entidades
{
	class Entidade
	{
	protected:
		sf::RectangleShape body;
		sf::RenderWindow* window;
	public:
		Entidade();
		~Entidade();
		void setWindow(sf::RenderWindow* window);
		void draw();
		sf::Vector2f getFronteiras();
	};
}