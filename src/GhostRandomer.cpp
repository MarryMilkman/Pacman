#include "GhostRandomer.hpp"

GhostRandomer::GhostRandomer(int x, int y){
	this->x = x;
	this->y = y;
	this->_type = ObjType::t_GhostRandomer;
	this->_direction = Direction::None; 
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

int					GhostRandomer::setDirection() {
	this->_algorithm_hunter();

	return 0;
}

void				GhostRandomer::_algorithm_hunter() {
	std::vector<Direction>	listDirection;
	Direction				dir;
	int						i;
	int						size;

	// if (!this->_isDirBlocked(this->_direction))
	// 	return ;
	listDirection = this->_getList_priorityDirection();
	size = listDirection.size();
	i = -1;
	while (++i < size) {
		dir = listDirection[i];
		if (!this->_isDirBlocked(dir)) {
			this->_direction = dir;
			return ;
		}
	}
	// this->_direction = this->_getRandomDirection();
}