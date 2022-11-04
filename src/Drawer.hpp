#pragma once
#include "Board.hpp"
#include "SFML/Graphics/RenderWindow.hpp"


namespace Game
{
	class Game;
}
namespace Drawer
{
	class Drawer
	{
	public:
		Drawer(int block_size);
		void draw_game(const Game::Game& game);
		sf::RenderWindow window;
	private:
		const int block_size;
		void draw_board(const Board::Board& b);
		void draw_piece(const Piece::Piece& p);
		void draw_borders();
	};
}


