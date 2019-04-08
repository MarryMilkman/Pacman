#ifndef BORDER_HPP
#define BORDER_HPP

#include "IObject.hpp"

class Border : public IObject
{
public:
	Border(int x, int y);
	Border(Border const &ref);
	~Border();
	
	int			setDirection() override;

	Border		&operator=(Border const &ref);
};

#endif