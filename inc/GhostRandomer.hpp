#ifndef GHOST_RANDOMER_HPP
# define GHOST_RANDOMER_HPP

#include "IEnemy.hpp"

class GhostRandomer : public IEnemy
{
public:
	GhostRandomer(int x, int y);
	GhostRandomer(GhostRandomer const &ref);
	~GhostRandomer();
	
	int		setDirection() override;

	GhostRandomer	&operator=(GhostRandomer const &ref);
private:
	void	_algorithm_hunter() override;
};

#endif