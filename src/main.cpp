#include "lib.h"
#include "PacmanGameController.hpp"

int main(int argc, char **argv)
{
	PacmanGameController	*game = PacmanGameController::getInstance("./map/map1");
	while (true) {
		if (game->doCycle())
			break ;
	}
	return 0;
}