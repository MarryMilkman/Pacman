#include "Point.hpp"


Point::Point(int x, int y) {
	this->x = x;
	this->y = y;
	this->_type = ObjType::t_Point;
	this->_direction = Direction::None;
}


Point::Point(Point const &ref) {
	*this = ref;
}

Point::~Point() {

}

Point		&Point::operator=(Point const &ref) {
	this->x = ref.x;
	this->y = ref.y;
	return (*this);
}

int					Point::setDirection() {
	return 1;
}