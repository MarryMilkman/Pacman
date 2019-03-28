#ifndef GHOST_RANDOMER_HPP
#define GHOST_RANDOMER_HPP

class GhostRandomer
{
public:
	GhostRandomer(int x, int y);
	~GhostRandomer();
	
	int		getDirection() override;

private:

	void	_algorithm_hunter() override;
};
#endif