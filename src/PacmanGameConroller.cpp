#include "PacmanGameController.hpp"


PacmanGameController::PacmanGameController(std::string fileMap) {
	// create map structure
	this->_botCount = 0;
	this->_max_botCount = 2;
	this->_initGameData(fileMap);
}

PacmanGameController	&PacmanGameController::getInstance() {
	static PacmanGameController		controller("./map/map1");

	return controller;
}

// MARK: - general cycle
void					PacmanGameController::doCycle() {
	int		i;

	this->_player->setDirection();
	i = this->_listEnemy.size();
	while (i-- > 0)
		this->_listEnemy[i]->setDirection;
	this->_moveObject();
	this->_checkCollision();
	this->_updateEnemy();
	this->_drow();
}

// MARK: - movement
void					PacmanGameController::_motionTracking() {
	Player		*player = this->_player;
	IEnemy		*enemy;
	int			i;
	int			size;

	// for player
	this->_moveObj(player, player->getDirection());
	i = -1;
	size = ths->_listEnemy.size();
	while (++i < size) {
		enemy = this->_listEnemy[i];
		this->_moveObj(enemy, enemy->getDirection());
	}
}

	// move  left/right/up/down
void					PacmanGameController::_moveObj(IObject *obj, Direction dir) {
	int		x = obj->x;
	int		y = obj->y;

	if (dir == Direction::Left && x > 0) {
		Sector::moveSector(obj, this->map[y][x], this->map[y - 1][x]);
		obj.y--;
	}
	if (dir == Direction::Right && x < this->_max_y) {
		Sector::moveSector(obj, this->map[y][x], this->map[y + 1][x]);
		obj.y++;
	}
	if (dir == Direction::Up && x > 0) {
		Sector::moveSector(obj, this->map[y][x], this->map[y][x - 1]);
		obj.x--;
	}
	if (dir == Direction::Down && x < this->_max_x) {
		Sector::moveSector(obj, this->map[y][x], this->map[y][x + 1]);
		obj.x++;
	}
}

// MARK: - collision
void					PacmanGameController::_checkCollision() {
	int						i;
	int						size;
	int						x_player = this->_player->x;
	int						y_player = this->_player->y;
	Sector					&playerSector = this->_map[x][y];
	std::vector<IObject *>	&listObj = playerSector.listObj;
	Object					*checkObj;
	ObjType					objType;

	size = checkObj.size();
	i = -1;
	if (i = 1)
		return ;
	while (++i < size) {
		checkObj = listObj[i];
		objType = checkObj.getType();
		if (checkObj == this->_player)
			continue;
		if (objType == ObjType::Point) {
			this->score += 10;
			delete checkObj;
			checkObj = 0;
			listObj.erase(listObj.begin() + i);
			size--;
			i = -1;
			continue;
		}
		// if (objType == ObjType::BigPoint)
		if (objType == ObjType::EnemyRandomer || objType == ObjType::EnemyPursuer) {
			this->endGame();
		}
	}
}



// MARK: - init game date

void				PacmanGameController::_initGameDate(std::string path_map) {
	// pars map and init game objects
	this->_parsMapAndInitGameObjects(path_map);

}

void				PacmanGameController::_parsMapAndInitGameObjects(std::string path_map) {
	int						y = 0;
	std::fstream			fd;
	std::string				line;
	std::vector<Sector *>	horizontal;	

	fd.open(path_map, std::fstream::in);
	while (std::getline(fd, line))
		this->_parsLine_AndInit(line, horizontal, y++);
	fd.close();
}

void				PacmanGameController::_parsLine_AndInit(std::string line, std::vector<Sector *> horizontal, int y) {
	int		i = -1;
	int		size = line.size();
	IObject	*obj;
	Sector	*sector;

	while (++i < size) {
		obj = this->_parsLine_AndInit_createObj(line[i], i, y);
		sector = new Sector(obj)
	}
}

IObject				*PacmanGameController::_parsLine_AndInit_createObj(char c, int x, int y) {
	IObject		*rObject = 0;
	IEnemy		*enemy;

	if (c == '0')
		rObject = new Border(x, y);
	else if (c == 'E') {
		if (this->_botCount == 0) {
			enemy = new GhostRandomer(x, y);
			rObject = enemy;
			this->_listEnemy.insert(this->_listEnemy.begin(), enemy)
		}
		else if (this->_botCount == 1) {
			enemy = new GhostPursuer(x, y);
			rObject = enemy;
			this->_listEnemy.insert(this->_listEnemy.begin(), enemy)
		}
	}
	else if (c == 'P') {
		this->_player = new Player(x, y)
		rObject = this->_player;
	}
	else if (c == '.') {
		rObject = new Point(x, y);
	}
	return rObject;
}












