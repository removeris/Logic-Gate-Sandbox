#include "And.h"

And::And(sf::Vector2i mouse_position) {
	_start_color = sf::Color::Blue;
	_sprite.setSize(sf::Vector2f(32, 32));
	_sprite.setOrigin(16, 16);
	_sprite.setFillColor(sf::Color::Blue);

	_sprite.setPosition(mouse_position.x, mouse_position.y);

	nodes.in1.setFillColor(sf::Color::White);
	nodes.in1.setRadius(6);
	nodes.in1.setOrigin(3, 3);

	nodes.in2 = nodes.in1;
	nodes.out1 = nodes.in1;

	nodes.in1.setPosition(_sprite.getPosition().x - _sprite.getSize().x / 2., _sprite.getPosition().y - 10);
	nodes.in2.setPosition(_sprite.getPosition().x - _sprite.getSize().x / 2., _sprite.getPosition().y + 6);
	nodes.out1.setPosition(_sprite.getPosition().x + _sprite.getSize().x / 2. - 3, _sprite.getPosition().y - 4);

	v_nodes = { &nodes.in1, &nodes.in2, &nodes.out1 };

	_active = true;
}

void And::Logic() {
	if (input.in1 == 1 && input.in2 == 1)
		output = 1;
	else
		output = 0;
}

void And::Update() {
	Logic();
	if (_active) {
		_sprite.setPosition(_position);
		nodes.in1.setPosition(_sprite.getPosition().x - _sprite.getSize().x / 2., _sprite.getPosition().y - 10);
		nodes.in2.setPosition(_sprite.getPosition().x - _sprite.getSize().x / 2., _sprite.getPosition().y + 6);
		nodes.out1.setPosition(_sprite.getPosition().x + _sprite.getSize().x / 2. - 3, _sprite.getPosition().y - 4);
	}
}

void And::Draw(sf::RenderTarget& window) {
	window.draw(_sprite);
	window.draw(nodes.in1);
	window.draw(nodes.in2);
	window.draw(nodes.out1);
}