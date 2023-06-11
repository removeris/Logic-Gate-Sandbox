#pragma once
#include "Gate.h"
class And : public Gate
{
private:
	
public:
	And(sf::Vector2i mouse_position);
	void Logic();
	void Update();
	void Draw(sf::RenderTarget& window);
};

