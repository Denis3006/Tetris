#pragma once

#include <list>
#include <array>
#include <vector>
#include <random>

#include "Piece.hpp"

namespace PieceGenerator
{
	class PieceGenerator
	{
	public:
		PieceGenerator();
		Piece::Piece generate_piece();
		std::vector<Piece::Piece> preview_pieces(int n);
	private:
		std::array<Piece::piece_type, 7> all_piece_types = { Piece::SQUARE, Piece::piece_type::I, Piece::piece_type::L, Piece::piece_type::L_MIRRORED, Piece::piece_type::N, Piece::N_MIRRORED, Piece::T };
		std::list<Piece::piece_type> bag;
		std::default_random_engine randomizer;
		void fill_bag();
	};
}
