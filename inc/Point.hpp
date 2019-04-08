#ifndef POINT_HPP
#define POINT_HPP

#include "IObject.hpp"

class Point : public IObject
{
public:
	Point(int x, int y);
	Point(Point const &ref);
	~Point();
	
	int			setDirection() override;

	Point		&operator=(Point const &ref);
};
#endif