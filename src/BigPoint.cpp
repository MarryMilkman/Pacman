#include "BigPoint.hpp"


BigPoint::BigPoint(int x, int y) {
	this->x = x;
	this->y = y;
	this->_type = ObjType::t_BigPoint;
	this->_direction = Direction::None; 
}


BigPoint::BigPoint(BigPoint const &ref) {
	*this = ref;
}

BigPoint::~BigPoint() {

}

BigPoint		&BigPoint::operator=(BigPoint const &ref) {
	this->x = ref.x;
	this->y = ref.y;
	return (*this);
}

int					BigPoint::setDirection() {
	return 1;
}