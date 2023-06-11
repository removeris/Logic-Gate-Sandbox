#include "Not.h"

Not::Not(sf::Vector2i mouse_position) {
	_start_color = sf::Color::Yellow;
	_sprite.setSize(sf::Vector2f(32, 32));
	_sprite.setOrigin(16, 16);
	_sprite.setFillColor(sf::Color::Yellow);

	_sprite.setPosition(mouse_position.x, mouse_position.y);

	nodes.in1.setFillColor(sf::Color::White);
	nodes.in1.setRadius(6);
	nodes.in1.setOrigin(3, 3);
	
	nodes.out1 = nodes.in1;

	nodes.in1.setPosition(_sprite.getPosition().x - _sprite.getSize().x / 2., _sprite.getPosition().y - 4);
	nodes.out1.setPosition(_sprite.getPosition().x + _sprite.getSize().x / 2. - 3, _sprite.getPosition().y - 4);

	v_nodes = { &nodes.in1, &nodes.in2, &nodes.out1 };

	_active = true;
}

void Not::Logic() {
	if (input.in1 == 0)
		output = 1;
	else
		output = 0;
}

void Not::Update() {
	Logic();
	if (_active) {
		_sprite.setPosition(_position);
		nodes.in1.setPosition(_sprite.getPosition().x - _sprite.getSize().x / 2., _sprite.getPosition().y - 4);
		nodes.out1.setPosition(_sprite.getPosition().x + _sprite.getSize().x / 2. - 3, _sprite.getPosition().y - 4);
	}
}

void Not::Draw(sf::RenderTarget& window) {
	window.draw(_sprite);
	window.draw(nodes.in1);
	window.draw(nodes.in2);
	window.draw(nodes.out1);
}