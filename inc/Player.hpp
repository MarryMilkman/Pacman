#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "IObject.hpp"

class Player: public IObject
{
public:
	Player(int x, int y);
	~Player();
	
	int			setDirection() override;

private:



};

#endif