#include <iostream>
#include <cstdlib>
#include <string>
#include <conio.h>

#include "GameCore.h"
#include "Input.h"

void initPlayer(Player &tmpPlayer);

int main() {

	GameCore core;
	Player player;
	Input input;

	bool gameIsRunning = true;
	int levelWidth;
	int levelHeight;

	initPlayer(player);

	std::cout << "\n\n\n\n";

	core.prepareLevel(1);
	core.printLevel(player);
	core.resetLevel();

	levelHeight = core.getLevelHeight();

	std::cout << "\n\n" << player.getPlayerX() << "\t" << player.getPlayerY() << "\n\n";

	while (gameIsRunning) {

		switch (input.getKeypress()) {

		case 'a':
			if (player.getPlayerX() != 0) {

				player.setPlayerX(player.getPlayerX() - 1);

			}
			break;
		case 'w':
			if (player.getPlayerY() != 0) {

				player.setPlayerY(player.getPlayerY() - 1);

			}
			break;
		case 's':
			if (player.getPlayerY() != core.getLevelHeight() - 1) {

				player.setPlayerY(player.getPlayerY() + 1);

			}
			break;
		case 'd':
			if (player.getPlayerX() != core.getLevelWidth(player.getPlayerY())) {

				player.setPlayerX(player.getPlayerX() + 1);

			}
			break;

		}

		core.clearScreen();
		core.printLevel(player);
		core.resetLevel();
		
		std::cout << "\n\n" << player.getPlayerX() << "\t" << player.getPlayerY() << "\n\n";
				
	}

	system("PAUSE");
	return 0;

}

void initPlayer(Player &tmpPlayer) {

	tmpPlayer.setPlayerX(2);
	tmpPlayer.setPlayerY(2);

}