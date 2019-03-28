#ifndef LIB_H
# define LIB_H

# include <iostream>
# include <fstream>
# include <sstream>
# include <vector>

#define TESTMOD 1
#define LEFT 37
#define RIGHT 39
#define	UP 38
#define DOWN 40


# ifdef __APPLE__
char	_getch();
# endif


# ifdef _WIN32
#  include <conio.h>
#  define INT_MAX 2147483647
#  define INT_MIN -2147483648
# endif

enum ObjType {
	t_Border = 0,
	t_GhostRandomer,
	t_GhostPursuer,
	t_Player,
	t_Point,
	t_BigPoint
};

enum Direction {
	Left = 0,
	Right,
	Up,
	Down,
	None
};

#endif