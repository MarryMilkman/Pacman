#ifndef PACMAN_GAME_CONTROLLER_HPP
# define PACMAN_GAME_CONTROLLER_HPP

# include "lib.h"
# include "Sector.hpp"
class Player;
#include "IEnemy.hpp"

class PacmanGameController
{
public:
	PacmanGameController(PacmanGameController const & ref) = delete;
	virtual ~PacmanGameController();

	static PacmanGameController	*getInstance(std::string fileMap);

	// void					startGame();
	int						doCycle();
	int						endGame();

	Sector					**getMap();
	Direction				getMoveReg();

	int						getPlayerCoord_x();
	int						getPlayerCoord_y();
	int						get_max_x();
	int						get_max_y();

	PacmanGameController	&operator=(PacmanGameController const & ref) = delete;

private:
	PacmanGameController(std::string fileMap);

	int						_score;
	GameStatus				_gameStatus;
	Player					*_player;
	std::vector<IEnemy *>	_listEnemy;
	// std::vector<Pont>		_listPont;
	// std::vector<BigPoint>	_listBigPoint;
	Direction				_moveReg;
	Sector					**_map;

	int						_max_x;
	int						_max_y;
	int						_botCount;
	int						_max_botCount;

	void					_motionTracking();
	void					_moveObj(IObject *obj, Direction dir);
	int						_checkBorderInDirection(int x, int y, Direction dir);
	int						_checkConditionForWin(int x, int y, Direction dir);

	void					_checkCollision();

	void					_initGameData(std::string path_map);
	void					_parsMapAndInitGameObjects(std::string path_map);
	void					_parsLine_AndInit(std::string line, std::vector<Sector *> &horizontals, int y);
	IObject					*_parsLine_AndInit_createObj(char c, int x, int y);
	void					_addHorysontal(std::vector<Sector *> horisontals, int y);

	void					_drow();
};

#endif