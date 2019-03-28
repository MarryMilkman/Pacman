#include "Point.hpp"


Point::Point(int x, int y) : x(x), y(y), _direction(Direction::None), _type(TypeObj::Point) {

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

int					Point::getDirection() {
	return 1;
}