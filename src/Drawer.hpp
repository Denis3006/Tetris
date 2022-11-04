#pragma once
#include <functional>

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
		Drawer(int block_size, int fps);
		void draw_game(Game::Game& game);
		sf::RenderWindow window;
	private:
		const int block_size;
		int board_y_offset = 7;
		void draw_board(const Board::Board& board);
		void draw_piece(const Piece::Piece& piece, int x_pos, int y_pos, std::function<bool(int x, int y)> draw_block);
		void draw_piece_preview(const std::vector<Piece::Piece>& piece_preview);
		void draw_borders();
	};
}


