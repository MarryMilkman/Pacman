#include "PacmanGameController.hpp"

#include "IObject.hpp"
#include "IEnemy.hpp"
#include "Sector.hpp"

#include "Border.hpp"
#include "GhostPursuer.hpp"
#include "GhostRandomer.hpp"
#include "Player.hpp"
#include "Point.hpp"
#include "BigPoint.hpp"

PacmanGameController::PacmanGameController(std::string fileMap) {
	// create map structure
	this->_score = 0;
	this->_moveReg = Direction::None;
	this->_botCount = 0;
	this->_max_botCount = 2;
	this->_gameStatus = GameStatus::Default;
	this->_initGameData(fileMap);
}

 PacmanGameController::~PacmanGameController() {

 }

PacmanGameController	*PacmanGameController::getInstance(std::string fileMap) {
	static PacmanGameController		*controller = new PacmanGameController(fileMap);

	return controller;
}
///////////////////////////////////////////////////////////////////////////////////



// MARK: - general cycle | end game
	//doCycle
int						PacmanGameController::doCycle() {
	int		i;

	if (this->_gameStatus != GameStatus::Default)
		return this->endGame();
	this->_player->setDirection();
	i = this->_listEnemy.size();
	while (i-- > 0)
		this->_listEnemy[i]->setDirection();
	this->_motionTracking();
	this->_checkCollision();
	// // for change enemy when player eat BigPoint
	// // this->_updateEnemy();
	this->_drow();
	return 0;
}
	//end Game
int						PacmanGameController::endGame() {
	if (this->_gameStatus == GameStatus::Lose) {
		std::cout << "You lose!\n";
		exit(0);
	}
	if (this->_gameStatus == GameStatus::Win){
		std::cout << "Win)))\n";
		exit(0);
	}
	return 1;
}



// MARK: - getMap | getMoveReg | getPlayerCoord_x | getPlayerCoord_y

Sector					**PacmanGameController::getMap() {
	return this->_map;
}

Direction				PacmanGameController::getMoveReg() {
	return this->_moveReg;
}

int						PacmanGameController::getPlayerCoord_x() {
	if (this->_player)
		return this->_player->x;
}

int						PacmanGameController::getPlayerCoord_y() {
	if (this->_player)
		return this->_player->y;
}

int						PacmanGameController::get_max_x() {
	return this->_max_x;
}

int						PacmanGameController::get_max_y() {
	return this->_max_y;
}



// MARK: - movement
	// _motionTraking
void					PacmanGameController::_motionTracking() {
	Player		*player = this->_player;
	IEnemy		*enemy;
	int			i;
	int			size;

	// for player
	this->_moveObj(player, player->getDirection());
	// for enemy
	i = -1;
	size = this->_listEnemy.size();
	while (++i < size) {
		enemy = this->_listEnemy[i];
		this->_moveObj(enemy, enemy->getDirection());
	}
}
	//move left/right/up/down + check condition for win - _moveObj
void					PacmanGameController::_moveObj(IObject *obj, Direction dir) {
	int		x = obj->x;
	int		y = obj->y;

	if (obj->getType() == ObjType::t_Player)
		if (this->_checkConditionForWin(x, y, dir))
			return ;
	if (this->_checkBorderInDirection(x, y, dir))
		return ;
	if (dir == Direction::Left && x > 0) {
		Sector::moveObj(obj, this->_map[y][x], this->_map[y][x - 1]);
		obj->x--;
	}
	else if (dir == Direction::Right && x < this->_max_x) {
		Sector::moveObj(obj, this->_map[y][x], this->_map[y][x + 1]);
		obj->x++;
	}
	else if (dir == Direction::Up && y > 0) {
		Sector::moveObj(obj, this->_map[y][x], this->_map[y - 1][x]);
		obj->y--;
	}
	else if (dir == Direction::Down && y < this->_max_y) {
		Sector::moveObj(obj, this->_map[y][x], this->_map[y + 1][x]);
		obj->y++;
	}
}
	//check for barriers in direction - _checkBorderInDirection
int						PacmanGameController::_checkBorderInDirection(int x, int y, Direction dir) {
	if (dir == Direction::Left && x > 0)
		x--;
	else if (dir == Direction::Right && x < this->_max_x)
		x++;
	else if (dir == Direction::Up && y > 0)
		y--;
	else if (dir == Direction::Down && y < this->_max_y) {
		y++;
	}
	if (x < 0 || x >= this->_max_x || y < 0 || y >= this->_max_y)
		return 1;
	if (this->_map[y][x].listObj.size() && 
		this->_map[y][x].listObj[0]->getType() == ObjType::t_Border)
		return 1;
	return 0;
}
	//check condition for win - _checkConditionForWin
int						PacmanGameController::_checkConditionForWin(int x, int y, Direction dir) {
	Sector		&sector = this->_map[y][x];

	if (dir == Direction::Left)
		x--;
	else if (dir == Direction::Right)
		x++;
	else if (dir == Direction::Up)
		y--;
	else if (dir == Direction::Down) {
		y++;
	}
	if (x < 0 || x >= this->_max_x || y < 0 || y >= this->_max_y) {
		std::cout << Sector::delite_fromSector_obj(sector, this->_player) << " Zalupa?\n";
		this->_player = 0;
		this->_gameStatus = GameStatus::Win;
		return 1;
	}
	return 0;
}



// MARK: - collision
	//check collision player with enemy/poin/bigPoint - _checkCollision
void					PacmanGameController::_checkCollision() {
	if (!this->_player)
		return ;

	int						i;
	int						size;
	int						x_player = this->_player->x;
	int						y_player = this->_player->y;
	Sector					&playerSector = this->_map[y_player][x_player];
	std::vector<IObject *>	&listObj = playerSector.listObj;
	IObject					*checkObj;
	ObjType					objType;

	std::cout << "Player coord: " << x_player << ":" << y_player << "\n";
	size = listObj.size();
	i = -1;
	if (i == 1)
		return ;
	while (++i < size) {
		checkObj = listObj[i];
		objType = checkObj->getType();
		if (checkObj == this->_player)
			continue;
		if (objType == ObjType::t_Point) {
			this->_score += 10;
			Sector::delite_fromSector_obj(playerSector, checkObj);
			size--;
			i = -1;
			continue;
		}
		if (objType == ObjType::t_BigPoint) {
			// add option for kill ghost
			this->_score += 100;
			Sector::delite_fromSector_obj(playerSector, checkObj);
			size--;
			i = -1;
			continue;
		}
		if (objType == ObjType::t_GhostRandomer || objType == ObjType::t_GhostPursuer)
			Sector::delite_fromSector_obj(playerSector, this->_player);
			this->_gameStatus = GameStatus::Lose;
	}
}



// MARK: - init game date

void				PacmanGameController::_initGameData(std::string path_map) {
	this->_parsMapAndInitGameObjects(path_map);
}
	//pars map and init game objects - _parsMapAndInitGameObjects
void				PacmanGameController::_parsMapAndInitGameObjects(std::string path_map) {
	int						y = -1;
	std::fstream			fd;
	std::string				line;
	std::vector<Sector *>	horizontals;	

	fd.open(path_map, std::fstream::in);
	while (std::getline(fd, line)) {
		this->_parsLine_AndInit(line, horizontals, ++y);
	}
	this->_addHorysontal(horizontals, y + 1);
	this->_max_y = y + 1;
	fd.close();
}
	// pars line and init horisintal with obj - _parsLine_AndInit
void				PacmanGameController::_parsLine_AndInit(std::string line, std::vector<Sector *> &horizontals, int y) {
	int						i = -1;
	int						size = line.size();
	IObject					*obj;
	Sector					*sector = new Sector[size];

	while (++i < size) {
		std::vector<IObject	*>	listObj;

		obj = this->_parsLine_AndInit_createObj(line[i], i, y);
		if (obj)
			listObj.insert(listObj.begin(), obj);
		sector[i] = Sector(listObj);
		// horizontal.insert(horizontal.begin(), sector);
	}
	horizontals.insert(horizontals.end(), sector);
	if (this->_max_x == 0)
		this->_max_x = i;
	else if (this->_max_x != i) {
		std::cout << "ERROR: invalid map (different number of fild)";
		exit(0);
	}
}
	// retarn IObject for init horisontal - _parsLine_AndInit_createObj
IObject				*PacmanGameController::_parsLine_AndInit_createObj(char c, int x, int y) {
	IObject		*rObject = 0;
	IEnemy		*enemy;

	if (c == '0')
		rObject = new Border(x, y);
	else if (c == 'E') {
		if (this->_botCount == 0) {
			enemy = new GhostRandomer(x, y);
			rObject = enemy;
			this->_listEnemy.insert(this->_listEnemy.begin(), enemy);
		}
		else if (this->_botCount == 1) {
			enemy = new GhostPursuer(x, y);
			rObject = enemy;
			this->_listEnemy.insert(this->_listEnemy.begin(), enemy);
		}
		this->_botCount++;
	}
	else if (c == 'P') {
		this->_player = new Player(x, y);
		rObject = this->_player;
	}
	else if (c == '.') {
		rObject = new Point(x, y);
	}
	else if (c == '*') {
		rObject = new BigPoint(x, y);
	}
	else if (c == '0') {
		rObject = new Border(x, y);
	}
	else if (c != ' ') {
		std::cout << "ERROR: invalid map (undefined symbol for map)";
		exit(0);
	}
	return rObject;
}
	//add horisontals with obj to _map - _addHorysontal
void			PacmanGameController::_addHorysontal(std::vector<Sector *> horisontals, int y) {
	int		i;
	int		j;
	int		size;

	i = -1;
	if (!this->_map)
		this->_map = new Sector* [y + 1];
	while (++i < y) {
		// size = horisontal.size();
		// j = -1;
		// while (++j < size) {
		// 	std::cerr << horisontal[i][j].listObj[0]->x << " : "
		// 		<< horisontal[i][j].listObj[0]->y << " -- " << y <<"\n";
		// }
		this->_map[i] = horisontals[i];
	}
	this->_map[i] = 0;
}



// MARK: - Drow Map

void			PacmanGameController::_drow() {
#ifdef TEST_MOD
	int			i;
	int			j;
	ObjType		type;
	char		c;
	std::string	str;

	i = -1;
	while (++i < this->_max_y) {
		j = -1;
		while (++j < this->_max_x) {
			if (!this->_map[i][j].listObj.size()) {
				std::cout << ' ';
				continue;
			}
			type = this->_map[i][j].listObj[0]->getType();
			if (type == ObjType::t_Player)
				std::cout << "P";
			else if (type == ObjType::t_GhostPursuer)
				std::cout << "E";
			else if (type == ObjType::t_GhostRandomer)
				std::cout << "R";
			else if (type == ObjType::t_Point)
				std::cout << ".";
			else if (type == ObjType::t_BigPoint)
				std::cout << "*";
			else if (type == ObjType::t_Border)
				std::cout << "#";
		}
		std::cout << "\n";
	}
	std::cout << "Score: " << this->_score << "\n";
	if (this->_gameStatus == GameStatus::Default) {
		std::cin >> str;
		c = str[0];
	}

	
	std::cout << c << "\n";
	if (c == 'a')
		this->_moveReg = Direction::Left;
	else if (c == 'w')
		this->_moveReg = Direction::Up;
	else if (c == 'd')
		this->_moveReg = Direction::Right;
	else if (c == 's')
		this->_moveReg = Direction::Down;
#endif
}





