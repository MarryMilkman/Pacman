#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "IObject.hpp"

class Player: public IObject
{
public:
	Player(int x, int y);
	Player(Player const & ref);
	~Player();
	
	int			setDirection() override;

	Player		&operator=(Player const & ref);

};

#endif