#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
namespace Entidades
{
	class Entidade
	{
	protected:
		// sf::RectangleShape body;
		sf::Texture texture;
		sf::Sprite sprite;
		sf::RenderWindow* window;
	public:
		Entidade();
		~Entidade();
		void setWindow(sf::RenderWindow* window);
		void draw();
		sf::Vector2f getFronteiras();
	};
}