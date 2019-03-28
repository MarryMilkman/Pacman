#include "BigPoint.hpp"


BigPoint::BigPoint(int x, int y) : x(x), y(y), _direction(Direction::None), _type(TypeObj::BigPoint) {

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

int					BigPoint::getDirection() {
	return 1;
}