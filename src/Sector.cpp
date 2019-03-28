#include "Sector.hpp"

Sector::Sector() {
		this->listObj = 0;
}
Sector::Sector(sed::vector<IObject *> listObj) {
	this->listObj = listObj;
}
Sector::Sector(Sector const &ref) {
	this = ref;
}
~Sector::Sector() {}



void		Sector::moveObj(IObject *obj, Sector &s1, Sector &s2) {
	int		iter = find_IterationToObj_inList(obj);

	s1.erise(s1.begin(), iter);
	s2.insert(s1.begin(), obj);
}

int			find_IterationToObj_inList(IObject const *checkObj) const {
	int		i;
	int		size;
	IObject	*obj;

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