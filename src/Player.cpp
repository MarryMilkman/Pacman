#include "Player.hpp"
#include "PacmanGameController.hpp"
#include "IObject.hpp"

int			Player::setDirection() {
	PacmanGameController	controller = PacmanGameController::getInstance();

	this->dyrection = controller.getMoveReg();
	return 0;
}