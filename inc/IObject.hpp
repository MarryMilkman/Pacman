#ifndef I_OBJECT_HPP
#define I_OBJECT_HPP

#include "lib.h"

class IObject
{
public:
	virtual ~IObject() {}

	virtual int	setDirection() = 0;
	void		updateCoord(int	x, int y);

	
	int			x;
	int			y;

	Direction	getDirection();
	ObjType		getType();

protected:

	ObjType		_type;
	Direction	_direction;
};

#endif