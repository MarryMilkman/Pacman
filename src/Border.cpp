#include "Border.hpp"


Border::Border(int x, int y) {
	this->x = x;
	this->y = y;
	this->_type = ObjType::t_Border;
	this->_direction = Direction::None; 
}


Border::Border(Border const &ref) {
	*this = ref;
}

Border::~Border() {

}

Border		&Border::operator=(Border const &ref) {
	this->x = ref.x;
	this->y = ref.y;
	return (*this);
}

int					Border::setDirection() {
	return 1;
}