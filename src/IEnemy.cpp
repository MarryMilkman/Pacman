#include "IEnemy.hpp"

void		IEnemy::_algorithm_victim() {
	this->_direction = Direction::Up;
	// Direction	linearDirection = _getLinearDirectionToPlayer();

	// if (linearDirection == Direction::None) {
	// 	this->direction = this->_getAnyDirection();
	// }
	// else
	// 	this->direction = this->_getDirection_victim(linearDirection);
}