#include "GhostPursuer.hpp"

GhostPursuer::GhostPursuer(int x, int y) {
	this->x = x;
	this->y = y;
	this->_type = ObjType::t_GhostPursuer;
	this->_direction = Direction::None; 
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

int					GhostPursuer::setDirection() {
	this->_algorithm_hunter();

	return 0;
}

void				GhostPursuer::_algorithm_hunter() {
	this->_direction = Direction::Right;
}