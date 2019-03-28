#ifndef POINT_HPP
#define POINT_HPP

class Point
{
public:
	Point(int x, int y);
	~Point();
	
	int			setDirection() override;
};
#endif