#ifndef SECTOR_HPP
# define SECTOR_HPP

# include "lib.h"

class Sector
{
public:
	Sector();
	Sector(IObject *obj);
	Sector(Sector const &ref);
	~Sector();

	sed::vector<IObject *>		listObj;

	static void	moveObj(IObject *obj, Sector &s1, Sector &s2);

	Sector		&operator=(Sector const &ref);
	void		operator>>(Sector &ref);

private:
	int			find_IterationToObj_inList(IObject const *obj) const;
};

#endif