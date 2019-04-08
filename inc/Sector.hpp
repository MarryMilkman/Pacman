#ifndef SECTOR_HPP
# define SECTOR_HPP

# include "lib.h"

#include "IObject.hpp"

class Sector
{
public:
	Sector();
	Sector(std::vector<IObject *> listObj);
	Sector(Sector const &ref);
	~Sector();

	std::vector<IObject *>		listObj;

	static void	moveObj(IObject *obj, Sector &s1, Sector &s2);
	static int	delite_fromSector_obj(Sector &sector, IObject *obj);

	Sector		&operator=(Sector const &ref);
	void		operator>>(Sector &ref);

private:
	int			_find_IterationToObj_inList(IObject const *obj) const;
};

#endif