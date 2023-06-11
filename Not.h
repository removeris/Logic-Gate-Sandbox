#pragma once

#include "Gate.h"

class Not : public Gate
{
private:

public:
	Not(sf::Vector2i mouse_position);
	void Logic();
	void Update();
	void Draw(sf::RenderTarget& window);
};

