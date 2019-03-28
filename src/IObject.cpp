#include "IObject.hpp"

void		IObject::updateCoord(int x, int y) {
	this->x = x;
	this->y = y;
}

Direction	IObject::getDirection() {
	return (this->direction);
}

ObjType		getType() {
	return (this->_type);
}