#ifndef I_ENEMY_HPP
#define I_ENEMY_HPP

#include "IObject.hpp"

class IEnemy: virtual public IObject
{
public:
	virtual ~IEnemy() {}
	
	virtual int			setDirection() = 0;

protected:
	virtual void			_algorithm_hunter() = 0;

	void					_algorithm_victim();

	bool					_isDirBlocked(Direction dir);
	std::vector<Direction>	_getList_priorityDirection();
	Direction				_getRandomDirection();

private:
	bool					_isDir_inList(Direction dir, std::vector<Direction> list);
};

#endif




