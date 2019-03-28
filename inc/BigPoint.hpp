#ifndef BIG_POINT_HPP
#define BIG_POINT_HPP

class BigPoint
{
public:
	BigPoint(int x, int y);
	~BigPoint();
	
	int			setDirection() override;
};
#endif