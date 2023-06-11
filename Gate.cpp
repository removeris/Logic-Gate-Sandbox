#include "Gate.h"

sf::RectangleShape Gate::getSprite() { return _sprite; }
sf::Vector2f Gate::getPosition() { return _position; }
void Gate::setPosition(sf::Vector2i pos) {
	_position.x = pos.x;
	_position.y = pos.y;
}
void Gate::Deactivate() {
	_active = false;
}
void Gate::invalidColor() {
	_sprite.setFillColor(sf::Color::Red);
}
void Gate::colorReset() {
	_sprite.setFillColor(_start_color);
}

sf::CircleShape* Gate::nodeIntersect(sf::Vector2i mouse_position) {

	for (auto node : v_nodes) {
		if (node->getGlobalBounds().contains(sf::Vector2f(mouse_position))) {
			node->setOutlineColor(sf::Color::Magenta);
			node->setOutlineThickness(3.5);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				return node;
			}
		}
		else {
			node->setOutlineColor(sf::Color::Transparent);
		}
	}
	return nullptr;
}