#pragma once
#include "Piece.hpp"

#include <vector>

#include <boost/dynamic_bitset/dynamic_bitset.hpp>

namespace Board
{
	class Board
	{
	public:
		Board() = default;
		Board(unsigned int board_width, unsigned int board_height);
		bool block_is_full(unsigned int x, unsigned int y) const;
		bool block_in_board(int x, int y) const;
		bool is_game_over() const;
		bool first_row_has_blocks() const;
		void clear_full_lines();
		void store_piece(const Piece::Piece& piece);
		size_t get_width() const;
		size_t get_height() const;
	private:
		bool line_is_full(size_t line) const;
		std::vector<boost::dynamic_bitset<>> board;
	};
}

