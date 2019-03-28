#include "GhostPursuer.hpp"

GhostPursuer::GhostPursuer(int x, int y) : x(x), y(y), _type(ObjType::GhostPursuer), _direction(Direction::None) {
}

GhostPursuer::GhostPursuer(GhostPursuer const &ref) {
	*this = ref;
}

GhostPursuer::~GhostPursuer() {

}

GhostPursuer		&GhostPursuer::operator=(GhostPursuer const &ref) {
	this->x = ref.x;
	this->y = ref.y;
	return (*this);
}

int					GhostPursuer::getDirection() {
	this->_algorithm_humter();

	return 0;
}

void				GhostPursuer::_algorithm_humter() {
	this->_direction = Direction::Right;