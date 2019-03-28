#ifndef PACMAN_GAME_CONTROLLER_HPP
# define PACMAN_GAME_CONTROLLER_HPP

# include "lib.h"
# include "Sector.hpp"

class PacmanGameConroller
{
public:
	PacmanGameConroller() = delete;
	PacmanGameConroller(PacmanGameConroller const & ref) = delete;
	~PacmanGameConroller();

	static PacmanGameConroller	&getInstance();

	void					startGame();
	void					doCycle();
	void					endGame();

	const Sector			**getMap();
	int						getMoveReg();

	PacmanGameConroller		&operator=(PacmanGameConroller const & ref) = delete;

private:
	PacmanGameConroller(std::string	fileMap);

	int						_score;
	Player					*_player;
	std::vector<IEnemy *>	_listEnemy;
	// std::vector<Pont>		_listPont;
	// std::vector<BigPoint>	_listBigPoint;
	int						_moveReg;
	Sector					**_map;

	int						_max_x;
	int						_max_y;

	void					_moveObject();
	void					_checkCollision();
	void					_drow();

	void					_initGameData(std::string path_map);
};

#endif