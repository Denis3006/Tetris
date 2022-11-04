#include "PieceGenerator.hpp"

#include <algorithm>
#include <chrono>
namespace PieceGenerator
{
	PieceGenerator::PieceGenerator() : randomizer(std::chrono::system_clock::now().time_since_epoch().count())
	{
		fill_bag();
	}

	Piece::Piece PieceGenerator::generate_piece()
	{
		if (bag.empty()) {
			fill_bag();
		}

		Piece::Piece result(bag.front());
		bag.pop_front();
		return result;
	}

	std::vector<Piece::Piece> PieceGenerator::preview_pieces(int n)
	{
		if (bag.size() < n) {
			fill_bag();
		}

		std::vector<Piece::Piece> result;
		result.reserve(n);
		for (auto it = bag.begin(); it != std::next(bag.begin(), n); ++it) {
			result.emplace_back(Piece::Piece(*it));
		}
		return result;
	}

	void PieceGenerator::fill_bag()
	{
		std::shuffle(all_piece_types.begin(), all_piece_types.end(), randomizer);
		for (const auto& piece_type : all_piece_types) {
			bag.emplace_back(piece_type);
		}
	}
}
