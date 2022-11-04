#include "Game.hpp"

int main()
{
	Game::Game g(10, 20, 20);
	while (true) {
		g.get_user_input();
		g.update_game_state();
		g.draw_game();
	}
}
