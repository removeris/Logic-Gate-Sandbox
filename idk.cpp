#include <iostream>
#include <vector>
#include <math.h>
#include "SFML/Graphics.hpp"
#include "And.h"
#include "Or.h"
#include "Not.h"
#define _USE_MATH_DEFINES

void pollEvents(sf::RenderWindow& window);

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Test");
	window.setFramerateLimit(60);

	sf::Clock clock;

	std::vector<Gate*> gates;
	// 0 - NONE, 1 - AND, 2 - OR, 3 - NOT
	int current_gate_type = 0;

	bool first_selection = true;

	sf::CircleShape* first_selected_node = nullptr;

	std::vector<sf::RectangleShape> connectivity_lines;

	while (window.isOpen()) {


		pollEvents(window);
		
		window.clear(sf::Color::Black);

		if (current_gate_type == 0) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
				current_gate_type = 1;
				gates.push_back(new And(sf::Mouse::getPosition()));
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
				current_gate_type = 2;
				gates.push_back(new Or(sf::Mouse::getPosition()));
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
				current_gate_type = 3;
				gates.push_back(new Not(sf::Mouse::getPosition()));
			}
		}
		else {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
				current_gate_type = 0;
				gates.erase(gates.end() - 1);
			}
		}

		unsigned short int intersects = 0;

		for (auto gate : gates) {
			if (gates[gates.size() - 1]->getSprite().getGlobalBounds().intersects(gate->getSprite().getGlobalBounds()))
				intersects++;
		}

		if (intersects > 1 && gates.size() != 0) {
			gates[gates.size() - 1]->invalidColor();
		}
		else if (intersects == 1 && gates.size() != 0)
			gates[gates.size() - 1]->colorReset();

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && current_gate_type != 0 && intersects == 1) {
			gates[gates.size() - 1]->Deactivate();
			current_gate_type = 0;	
		}

		for (auto gate : gates) {
			gate->Update();
			gate->setPosition(sf::Mouse::getPosition(window));

			sf::CircleShape* selected_node = gate->nodeIntersect(sf::Mouse::getPosition(window));

			if (selected_node != nullptr && clock.getElapsedTime().asMilliseconds() > 500) {
				clock.restart();
				if (first_selection == true) {
					first_selected_node = selected_node;
					first_selection = false;
				}
				else if(selected_node != first_selected_node) {

					sf::RectangleShape rect;

					float distance = distanceBetweenPoints(
						first_selected_node->getPosition().x,
						first_selected_node->getPosition().y,
						selected_node->getPosition().x,
						selected_node->getPosition().y);

					sf::Vector2f mid_point;

					mid_point.x = (first_selected_node->getPosition().x + selected_node->getPosition().x) / 2.;
					mid_point.y = (first_selected_node->getPosition().y + selected_node->getPosition().y) / 2.;

					rect.setSize(sf::Vector2f(distance, 4));

					float pos1 = first_selected_node->getPosition().y;
					float pos2 = selected_node->getPosition().y;

					float height = fabs(first_selected_node->getPosition().y - selected_node->getPosition().y);
					
					float sinAlpha = height / distance;

					float alpha = asin(sinAlpha) * 180 / (atan(1) * 4);

					std::cout << alpha << "\n";

					if (pos1 > pos2)
						rect.setRotation(-alpha);
					else
						rect.setRotation(alpha);


					rect.setPosition(first_selected_node->getPosition());

					rect.setFillColor(sf::Color::White);

					connectivity_lines.push_back(rect);

					first_selection = true;
					first_selected_node = nullptr;
					selected_node = nullptr;
				}
			}
			gate->Draw(window);
		}


		for (auto line : connectivity_lines)
			window.draw(line);
		window.display();
	}

	

	return 0;
}

void pollEvents(sf::RenderWindow &window) {
	sf::Event event;
	
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window.close();
	}
}
