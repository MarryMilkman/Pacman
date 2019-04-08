#include "IEnemy.hpp"
#include "PacmanGameController.hpp"

void					IEnemy::_algorithm_victim() {
	Direction				dir;
	std::vector<Direction>	listDir = this->_getList_priorityDirection();
	int						i = listDir.size();

	while (i-- > 0) {
		dir = listDir[i];
		if (!this->_isDirBlocked(dir)) {
			this->_direction = dir;
			return ;
		}
	}
	this->_direction = Direction::Up;
	// Direction	linearDirection = _getLinearDirectionToPlayer();

	// if (linearDirection == Direction::None) {
	// 	this->direction = this->_getAnyDirection();
	// }
	// else
	// 	this->direction = this->_getDirection_victim(linearDirection);
}

bool					IEnemy::_isDirBlocked(Direction dir) {
	PacmanGameController	*controller = PacmanGameController::getInstance("");
	Sector					**map = controller->getMap();
	int						x = this->x;
	int						y = this->y;
	Sector					&sector = map[y][x];

	if (dir == Direction::Left && x > 0)
		x--;
	else if (dir == Direction::Right && x < controller->get_max_x())
		x++;
	else if (dir == Direction::Up && y > 0)
		y--;
	else if (dir == Direction::Down && y < controller->get_max_y())
		y++;
	if (x == this->x && y == this->y)
		return true;
	if (map[y][x].listObj.size() && map[y][x].listObj[0]->getType() == ObjType::t_Border)
		return true;
	return false;
}

std::vector<Direction>	IEnemy::_getList_priorityDirection() {
	std::vector<Direction>	listDir;
	// std::vector<Direction>	defaultListDir;
	PacmanGameController	*controller = PacmanGameController::getInstance("");
	int						x = this->x;
	int						y = this->y;
	int						palyer_x = controller->getPlayerCoord_x();
	int						palyer_y = controller->getPlayerCoord_y();
	char					count = 4;

	// defaultListDir.insetr()
	while (count > 0) {
		if ((x > palyer_x  || (count < 3 && count > 0)) && !this->_isDir_inList(Left, listDir)) {
			count--;
			listDir.insert(listDir.end(), Left);
		}
		else if ((x != palyer_x  || (count < 4 && count > 0)) && !this->_isDir_inList(Right, listDir)) {
			count--;
			listDir.insert(listDir.end(), Right);
		}
		if ((y > palyer_y ||  (count < 3 && count > 0)) && !this->_isDir_inList(Up, listDir)) {
			count--;
			listDir.insert(listDir.end(), Up);
		}
		else if ((y != palyer_y || (count < 4 && count > 0)) && !this->_isDir_inList(Down, listDir)) {
			count--;
			listDir.insert(listDir.end(), Down);
		}
	}
	int i = -1;
	while (++i < 4) {
		std::cout << listDir[i] << " Alala\n";
	}
	return listDir;
}

bool						IEnemy::_isDir_inList(Direction dir, std::vector<Direction> list) {
	int		i;
	int		size;

	size = list.size();
	i = -1;
	while (++i < size) {
		if (dir == list[i])
			return true;
	}
	return false;
}