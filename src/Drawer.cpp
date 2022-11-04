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

	void Drawer::draw_game(Game::Game& game)
	{
		window.clear(sf::Color::Black);
		draw_borders();
		draw_board(game.get_board());
		if (game.current_piece_exists())
			draw_piece(game.get_current_piece(), game.get_current_piece().get_x_pos() + 1, game.get_current_piece().get_y_pos() + board_y_offset, 
				[&game](int x, int y) { return game.get_board().block_in_board(x + game.get_current_piece().get_x_pos(), y + game.get_current_piece().get_y_pos()); });
		if (game.piece_on_hold_exists()) {
			draw_piece(game.get_piece_on_hold(), 14, 8, [](int, int) { return true; });
		}
		draw_piece_preview(game.preview_pieces(3));
		window.display();
	}

	void Drawer::draw_board(const Board::Board& board)
	{
		sf::RectangleShape rect(sf::Vector2f(block_size - 1, block_size - 1));
		for (int y = 0; y < board.get_height(); y++) {
			for (int x = 0; x < board.get_width(); x++) {
				if (board.block_is_full(x, y)) {
					rect.setFillColor(sf::Color::White);
				}
				else {
					rect.setFillColor(sf::Color(20, 23, 79));
				}
				rect.setPosition((x + 1) * block_size, (board_y_offset + y) * block_size);
				window.draw(rect);
			}
		}
	}	

	void Drawer::draw_piece(const Piece::Piece& piece, int x_pos, int y_pos, std::function<bool(int x, int y)> draw_block)
	{
		sf::RectangleShape rect(sf::Vector2f(block_size - 1, block_size - 1));
		for (int y = 0; y < piece.get_height(); y++) {
			for (int x = 0; x < piece.get_width(); x++) {
				if (piece.block_is_full(x, y) && draw_block(x, y)) {
					rect.setFillColor(piece.get_color());
					rect.setPosition((x + x_pos) * block_size, (y + y_pos) * block_size);
					window.draw(rect);
				}
			}
		}
	}

	void Drawer::draw_piece_preview(const std::vector<Piece::Piece>& piece_preview)
	{
		int x_offset = 3;
		for (const auto& piece : piece_preview) {
			draw_piece(piece, x_offset, 1, [](int, int) { return true; });
			x_offset += 6;
		}
	}

	void Drawer::draw_borders()
	{
		sf::Color border_color(128, 128, 128);
		// preview panel
		sf::RectangleShape preview_left_border(sf::Vector2f(block_size, 5 * block_size));
		sf::RectangleShape preview_right_border(sf::Vector2f(block_size, 5 * block_size));
		sf::RectangleShape preview_top_border(sf::Vector2f(20 * block_size, block_size));
		sf::RectangleShape preview_bot_border(sf::Vector2f(20 * block_size, block_size));
		preview_left_border.setPosition(0, block_size);
		preview_right_border.setPosition(19 * block_size, block_size);
		preview_top_border.setPosition(0, 0);
		preview_bot_border.setPosition(0, 5 * block_size);
		preview_left_border.setFillColor(border_color);
		preview_right_border.setFillColor(border_color);
		preview_top_border.setFillColor(border_color);
		preview_bot_border.setFillColor(border_color);
		window.draw(preview_left_border);
		window.draw(preview_right_border);
		window.draw(preview_top_border);
		window.draw(preview_bot_border);

		// hold panel
		sf::RectangleShape hold_left_border(sf::Vector2f(block_size, 6 * block_size));
		sf::RectangleShape hold_right_border(sf::Vector2f(block_size, 6 * block_size));
		sf::RectangleShape hold_top_border(sf::Vector2f(7 * block_size, block_size));
		sf::RectangleShape hold_bot_border(sf::Vector2f(7 * block_size, block_size));
		hold_left_border.setPosition(13 * block_size, 7 * block_size);
		hold_right_border.setPosition(19 * block_size, 7 * block_size);
		hold_top_border.setPosition(13 * block_size, 7 * block_size);
		hold_bot_border.setPosition(13 * block_size, 13 * block_size);
		hold_left_border.setFillColor(border_color);
		hold_right_border.setFillColor(border_color);
		hold_top_border.setFillColor(border_color);
		hold_bot_border.setFillColor(border_color);
		window.draw(hold_left_border);
		window.draw(hold_right_border);
		window.draw(hold_top_border);
		window.draw(hold_bot_border);

		// board
		sf::RectangleShape left_border(sf::Vector2f(block_size, 21 * block_size));
		sf::RectangleShape right_border(sf::Vector2f(block_size, 21 * block_size));
		sf::RectangleShape bot_border(sf::Vector2f(12 * block_size, block_size));
		left_border.setPosition(0, board_y_offset * block_size);
		right_border.setPosition(11 * block_size, board_y_offset * block_size);
		bot_border.setPosition(0, (20 + board_y_offset) * block_size);
		left_border.setFillColor(border_color);
		right_border.setFillColor(border_color);
		bot_border.setFillColor(border_color);
		window.draw(left_border);
		window.draw(bot_border);
		window.draw(right_border);
	}
}

