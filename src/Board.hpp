#pragma once
#include "Piece.hpp"

#include <vector>

namespace Board
{
	class Board
	{
	public:
		Board() = default;
		Board(unsigned int board_width = 10, unsigned int board_height = 20);
		sf::Color block_color(unsigned int x, unsigned int y) const;
		bool block_is_full(unsigned int x, unsigned int y) const;
		bool block_in_board(int x, int y) const;
		bool first_row_has_blocks() const;
		void clear_full_lines();
		void store_piece(const Piece::Piece& piece);
		size_t get_width() const;
		size_t get_height() const;
	private:
		void clear_line(size_t line);
		bool line_is_full(size_t line) const;
		const sf::Color EMPTY_COLOR;
		std::vector<std::vector<sf::Color>> board;
	};
}

