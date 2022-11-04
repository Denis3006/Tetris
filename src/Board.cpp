#include "Board.hpp"
#include <vector>

namespace Board
{
	Board::Board(unsigned int board_width, unsigned int board_height)
	{
		board.resize(board_height);
		for (auto& row : board)
			row.resize(board_width);
	}

	bool Board::block_is_full(unsigned int x, unsigned int y) const
	{
		return board[y][x];
	}

	bool Board::is_game_over() const
	{
		return board[0].any();
	}

	bool Board::first_row_has_blocks() const
	{
		return board[0].any();
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
					board[line].reset();
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
						board[board_y][board_x] = true;
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

	bool Board::line_is_full(size_t line) const
	{
		return board[line].all();
	}

	bool Board::block_in_board(int x, int y) const
	{
		return (x >= 0 && y >= 0 && x < get_width() && y < get_height());
	}
}
