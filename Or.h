#pragma once

#include "Gate.h"

class Or : public Gate
{
private:

public:
	Or(sf::Vector2i mouse_position);
	void Logic();
	void Update();
	void Draw(sf::RenderTarget &window);


};

