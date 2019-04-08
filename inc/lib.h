#ifndef LIB_H
# define LIB_H

# include <iostream>
# include <fstream>
# include <sstream>
# include <vector>

#define TEST_MOD 1
#define LEFT 75
#define RIGHT 77
#define	UP 72
#define DOWN 80


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
	Left = 4,
	Right = 6,
	Up = 8,
	Down = 2,
	None = 0
};

enum GameStatus {
	Lose = 0,
	Win,
	Default
};

#endif