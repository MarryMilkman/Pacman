#ifndef LIB_H
# define LIB_H

# include <iostream>
# include <fstream>
# include <sstream>

enum ObjTyp {
	Border = 0,
	GhostRandomer,
	GhostPursuer,
	Player,
	Point,
	BigPoint
};

enum Direction {
	Left = 0,
	Right,
	Up,
	Down,
	Fixed
}

#endif