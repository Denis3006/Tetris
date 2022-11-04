#include "Game.hpp"

int main()
{
	Game::Game g(10, 20, 40);
	while (!g.is_game_over()) {
		g.get_user_input();
		g.update_game_state();
		g.draw_game();
	}
}
