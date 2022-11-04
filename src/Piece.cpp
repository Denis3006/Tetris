#include "Piece.hpp"

namespace Piece
{
	constexpr std::bitset<5> to_bitset(std::initializer_list<bool> il)
	{
		using ul = unsigned long;
		auto bits = ul(0);
		if (il.size()) {
			auto mask = ul(1) << (il.size() - 1);

			for (auto b : il) {
				if (b) {
					bits |= mask;
				}
				mask >>= 1;
			}
		}
		return std::bitset<5> { bits };
	}

	Piece::Piece(piece_type pt)
	{
		switch (pt) {
		case SQUARE:
			piece_data = square_data;
			x_pos = init_positions_square[rotation].first;
			y_pos = init_positions_square[rotation].second;
			color = square_color;
			break;
		case I:
			piece_data = I_data;
			x_pos = init_positions_I[rotation].first;
			y_pos = init_positions_I[rotation].second;
			color = I_color;
			break;
		case L:
			piece_data = L_data;
			x_pos = init_positions_L[rotation].first;
			y_pos = init_positions_L[rotation].second;
			color = L_color;
			break;
		case L_MIRRORED:
			piece_data = L_mirrored_data;
			x_pos = init_positions_L_mirrored[rotation].first;
			y_pos = init_positions_L_mirrored[rotation].second;
			color = L_mirrored_color;
			break;
		case N:
			piece_data = N_data;
			x_pos = init_positions_N[rotation].first;
			y_pos = init_positions_N[rotation].second;
			color = N_color;
			break;
		case N_MIRRORED:
			piece_data = N_mirrored_data;
			x_pos = init_positions_N_mirrored[rotation].first;
			y_pos = init_positions_N_mirrored[rotation].second;
			color = N_mirrored_color;
			break;
		case T:
			piece_data = T_data;
			x_pos = init_positions_T[rotation].first;
			y_pos = init_positions_T[rotation].second;
			color = T_color;
			break;
		}
		x_pos_init = x_pos;
		y_pos_init = y_pos;
	}

	void Piece::rotate(uint8_t r)
	{
		rotation = (rotation + r) % MAX_ROTATION;
	}

	void Piece::move(int x, int y)
	{
		x_pos += x;
		y_pos += y;
	}

	void Piece::reset_position()
	{
		x_pos = x_pos_init;
		y_pos = y_pos_init;
		rotation = 0;
	}

	bool Piece::block_is_full(unsigned int x, unsigned int y) const
	{
		return piece_data[rotation][y][x];
	}

	int Piece::get_x_pos() const
	{
		return x_pos;
	}

	int Piece::get_y_pos() const
	{
		return y_pos;
	}

	sf::Color Piece::get_color() const
	{
		return color;
	}
}
