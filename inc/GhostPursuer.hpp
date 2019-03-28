#ifndef GHOST_PURSUER_HPP
# define GHOST_PURSUER_HPP

class GhostPursuer
{
public:
	GhostPursuer(int x, int y);
	~GhostPursuer();

	int		getDirection() override;

private:

	void	_algorithm_hunter() override;
};

#endif