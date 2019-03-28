#ifndef I_ENEMY_HPP
#define I_ENEMY_HPP

class IObject;

class IEnemy: public IObject
{
public:
	virtual ~IEnemy() {};
	
	virtual int			getDirection() = 0;

private:
	void				_algorithm_victim();
	virtual void		_algorithm_hunter() = 0;
};

#endif