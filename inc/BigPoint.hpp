#ifndef BIG_POINT_HPP
#define BIG_POINT_HPP

#include "IObject.hpp"

class BigPoint : public IObject
{
public:
	BigPoint(int x, int y);
	BigPoint(BigPoint const &ref);
	~BigPoint();
	
	int			setDirection() override;

	BigPoint		&operator=(BigPoint const &ref);
};
#endif