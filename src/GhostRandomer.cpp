#include "GhostRandomer.hpp"

GhostRandomer::GhostRandomer(int x, int y) : x(x), y(y), _type(ObjType::GhostRandomer), _direction(Direction::None) {
}

GhostRandomer::GhostRandomer(GhostRandomer const &ref) {
	*this = ref;
}

GhostRandomer::~GhostRandomer() {

}

GhostRandomer		&GhostRandomer::operator=(GhostRandomer const &ref) {
	this->x = ref.x;
	this->y = ref.y;
	return (*this);
}

int					GhostRandomer::getDirection() {
	this->_algorithm_humter();

	return 0;
}

void				GhostRandomer::_algorithm_humter() {
	this->_direction = Direction::Down;
}