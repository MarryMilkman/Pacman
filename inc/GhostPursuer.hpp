#ifndef GHOST_PURSUER_HPP
# define GHOST_PURSUER_HPP

#include "IEnemy.hpp"

class GhostPursuer : virtual public IEnemy
{
public:
	GhostPursuer(int x, int y);
	GhostPursuer(GhostPursuer const &ref);
	~GhostPursuer();

	int		setDirection() override;

	GhostPursuer	&operator=(GhostPursuer const &ref);
private:
	
	void			_algorithm_hunter() override;
};

#endif