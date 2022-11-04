#include "Drawer.hpp"

#include "Game.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
namespace Drawer
{
	Drawer::Drawer(int block_size) : window(sf::VideoMode(800, 600), "Tetris"), block_size(block_size)
	{
		window.setFramerateLimit(60);
		draw_borders();
		window.display();
	}

	void Drawer::draw_game(const Game::Game& game)
	{
		window.clear(sf::Color::Black);
		draw_borders();
		draw_board(game.get_board());
		if (game.current_piece_exists())
			draw_piece(game.get_current_piece());
		window.display();
	}

	void Drawer::draw_board(const Board::Board& board)
	{
		sf::RectangleShape rect(sf::Vector2f(block_size - 1, block_size - 1));
		for (int y = 0; y < board.get_height(); y++) {
			for (int x = 0; x < board.get_width(); x++) {
				if (board.block_is_full(x, y)) {
					rect.setPosition((x + 1) * block_size, (y + 1) * block_size);
					window.draw(rect);
				}
			}
		}
	}

	void Drawer::draw_piece(const Piece::Piece& piece)
	{
		sf::RectangleShape rect(sf::Vector2f(block_size - 1, block_size - 1));
		for (int y = 0; y < piece.get_height(); y++) {
			for (int x = 0; x < piece.get_width(); x++) {
				if (piece.block_is_full(x, y)) {
					rect.setFillColor(piece.get_color());
					rect.setPosition((x + piece.get_x_pos() + 1) * block_size, (y + piece.get_y_pos() + 1) * block_size);
					window.draw(rect);
				}
			}
		}
	}

	void Drawer::draw_borders()
	{
		sf::RectangleShape left_border(sf::Vector2f(block_size, 21 * block_size));
		sf::RectangleShape bot_border(sf::Vector2f(12 * block_size, block_size));
		sf::RectangleShape right_border(sf::Vector2f(block_size, 21 * block_size));
		bot_border.setPosition(0, 21 * block_size);
		right_border.setPosition(11 * block_size, 0);
		left_border.setFillColor(sf::Color(128, 128, 128));
		right_border.setFillColor(sf::Color(128, 128, 128));
		bot_border.setFillColor(sf::Color(128, 128, 128));
		window.draw(left_border);
		window.draw(bot_border);
		window.draw(right_border);
	}
}

