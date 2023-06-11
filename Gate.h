#pragma once

#include "SFML/Graphics.hpp"
#include <vector>
#include "Utils.h"

class Gate
{
protected:
	sf::Vector2f _position;
	sf::RectangleShape _sprite;
	sf::Color _start_color;

	struct Input {
		char in1;
		char in2;
	} input;

	char output;

	struct Nodes {
		sf::CircleShape in1;
		sf::CircleShape in2;
		sf::CircleShape out1;
	} nodes;

	std::vector<sf::CircleShape*> v_nodes;


	bool _active;
public:
	virtual void Logic() = 0;
	virtual void Update() = 0;
	virtual void Draw(sf::RenderTarget &window) = 0;

	sf::RectangleShape getSprite();
	sf::Vector2f getPosition();
	void setPosition(sf::Vector2i pos);
	void Deactivate();
	void invalidColor();
	void colorReset();
	sf::CircleShape* nodeIntersect(sf::Vector2i mouse_position);
};

