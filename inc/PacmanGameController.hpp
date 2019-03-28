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

	void					startGame();
	void					doCycle();
	void					endGame();

	const Sector			**getMap();
	int						getMoveReg();

	PacmanGameController		&operator=(PacmanGameController const & ref) = delete;

private:
	PacmanGameController(std::string fileMap);

	int						_score;
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
	void					_checkCollision();
	void					_drow();

	void					_initGameData(std::string path_map);
};

#endif