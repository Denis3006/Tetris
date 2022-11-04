#include "Board.hpp"
#include <vector>

namespace Board
{
	Board::Board(unsigned int board_width, unsigned int board_height) : EMPTY_COLOR(20, 23, 79)
	{
		board.resize(board_height);
		for (auto& row : board) {
			row.resize(board_width, EMPTY_COLOR);
		}
	}

	sf::Color Board::block_color(unsigned x, unsigned y) const
	{
		return board[y][x];
	}

	bool Board::block_is_full(unsigned int x, unsigned int y) const
	{
		return board[y][x] != EMPTY_COLOR;
	}


	bool Board::first_row_has_blocks() const
	{
		return std::any_of(board[0].begin(), board[0].end(), [this](sf::Color c) { return c != this->EMPTY_COLOR; });
	}

	void Board::clear_full_lines()
	{
		std::vector<size_t> full_lines;
		for (size_t line = get_height() - 1; line > 0; line--) {
			if (line_is_full(line)) {
				full_lines.push_back(line);
			}
		}
		int n_cleared_lines = 0;
		for (size_t full_line : full_lines) {
			for (size_t line = full_line + n_cleared_lines; line > 0; line--) {
				if (line - 1 > 0) {
					board[line] = board[line - 1];
				}
				else {
					clear_line(line);
				}
			}
			++n_cleared_lines;
		}
	}

	void Board::store_piece(const Piece::Piece& piece)
	{
		for (int piece_y = 0; piece_y < static_cast<int>(Piece::Piece::get_height()); piece_y++) {
			for (int piece_x = 0; piece_x < static_cast<int>(Piece::Piece::Piece::get_width()); piece_x++) {
				if (piece.block_is_full(piece_x, piece_y)) {
					int board_y = piece_y + piece.get_y_pos();
					int board_x = piece_x + piece.get_x_pos();
					if (block_in_board(board_x, board_y)) {
						board[board_y][board_x] = piece.get_color();
						//board[board_y][board_x].a = 128;
					}
				}
			}
		}
	}

	size_t Board::get_width() const
	{
		return board[0].size();
	}

	size_t Board::get_height() const
	{
		return board.size();
	}

	void Board::clear_line(size_t line)
	{
		for (auto& c : board[line])
			c = EMPTY_COLOR;
	}

	bool Board::line_is_full(size_t line) const
	{
		return std::all_of(board[line].begin(), board[line].end(), [this](sf::Color c) { return c != this->EMPTY_COLOR; });
	}

	bool Board::block_in_board(int x, int y) const
	{
		return (x >= 0 && y >= 0 && x < get_width() && y < get_height());
	}
}
