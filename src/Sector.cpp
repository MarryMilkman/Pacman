#include "Sector.hpp"


Sector::Sector() {
		this->listObj = std::vector<IObject *>();
}
Sector::Sector(std::vector<IObject *> listObj) {
	this->listObj = listObj;
}
Sector::Sector(Sector const &ref) {
	*this = ref;
}
Sector::~Sector() {}



void		Sector::moveObj(IObject *obj, Sector &s1, Sector &s2) {
	if (!obj)
		return ;

	int		iter = s1._find_IterationToObj_inList(obj);

	if (iter == -1) {
		std::cout << "Cant find iteration: Sector.cpp moveObj\n";
		return ;
	}
	s1.listObj.erase(s1.listObj.begin() + iter);
	s2.listObj.insert(s2.listObj.begin(), obj);
}

int			Sector::delite_fromSector_obj(Sector &sector, IObject *obj) {
	int		pos = sector._find_IterationToObj_inList(obj);
	int		rValue = 0;

	if (obj)
		delete obj;
	else
		rValue = 1;
	obj = 0;
	if (pos >= 0)
		sector.listObj.erase(sector.listObj.begin() + pos);
	if (pos < 0)
		rValue = 2;
	return rValue;
}

int			Sector::_find_IterationToObj_inList(IObject const *checkObj) const {
	int		i;
	int		size;
	IObject	*obj;

	if (!checkObj)
		return -1;
	i = -1;
	size = this->listObj.size();
	while (++i < size) {
		obj = this->listObj[i];
		if (checkObj == obj)
			return i;
	}
	return -1;
}

Sector		&Sector::operator=(Sector const &ref) {
	this->listObj = ref.listObj;
	return *this;
}