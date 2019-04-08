#include "Player.hpp"
#include "PacmanGameController.hpp"
#include "IObject.hpp"

Player::Player(int x, int y) {
	this->x = x;
	this->y = y;
	this->_type = ObjType::t_Player;
	this->_direction = Direction::None;
}

Player::~Player() {
}

Player::Player(Player const & ref) {
	*this = ref;
}

Player		&Player::operator=(Player const & ref) {
	this->x = ref.x;
	this->y = ref.y;
	return *this;
}

int			Player::setDirection() {
	PacmanGameController	*controller = PacmanGameController::getInstance("./map/map1");

	this->_direction = controller->getMoveReg();
	return 0;
}