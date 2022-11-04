#pragma once
#include <cstdint>
#include <utility>
#include <array>
#include <bitset>

#include "SFML/Graphics.hpp"

namespace Piece
{
	using piece_rotation = std::array<std::bitset<5>, 5>;
	enum piece_type {SQUARE, I, L, L_MIRRORED, N, N_MIRRORED, T};
	constexpr std::bitset<5> to_bitset(std::initializer_list<bool> il);

	class Piece
	{
	public:
		Piece(piece_type pt);
		void rotate(uint8_t rotation=1);
		void move(int x, int y);
		void reset_position();
		bool block_is_full(unsigned int x, unsigned int y) const;

		int get_x_pos() const;
		int get_y_pos() const;
		sf::Color get_color() const;
		static constexpr size_t get_width()
		{
			return 5;
		}
		static constexpr size_t get_height()
		{
			return 5;
		}
	private:
		sf::Color color;
		const uint8_t MAX_ROTATION = 4;
		uint8_t rotation = 0;
		int x_pos, y_pos;
		int x_pos_init, y_pos_init;
		std::array<piece_rotation, 4> piece_data;
	};

	const std::array<piece_rotation, 4> square_data = {{
		{{
			to_bitset({false, false, false, false, false}),
			to_bitset({false, false, false, false, false}),
			to_bitset({false, false, true , true , false}),
			to_bitset({false, false, true , true , false}),
			to_bitset({false, false, false, false, false})
		}},
		{{
			to_bitset({false, false, false, false, false}),
			to_bitset({false, false, false, false, false}),
			to_bitset({false, false, true , true , false}),
			to_bitset({false, false, true , true , false}),
			to_bitset({false, false, false, false, false})
		}},
		{{
			to_bitset({false, false, false, false, false}),
			to_bitset({false, false, false, false, false}),
			to_bitset({false, false, true , true , false}),
			to_bitset({false, false, true , true , false}),
			to_bitset({false, false, false, false, false})
		}},
		{{
			to_bitset({false, false, false, false, false}),
			to_bitset({false, false, false, false, false}),
			to_bitset({false, false, true , true , false}),
			to_bitset({false, false, true , true , false}),
			to_bitset({false, false, false, false, false})
		}}
	}};



	const std::array<piece_rotation, 4> I_data = { {
		{{
			to_bitset({false, false, false, false, false}),
			to_bitset({false, false, false, false, false}),
			to_bitset({false, true , true , true , true }),
			to_bitset({false, false, false, false, false}),
			to_bitset({false, false, false, false, false})
		}},
		{{
			to_bitset({false, false, false, false, false}),
			to_bitset({false, false, true , false, false}),
			to_bitset({false, false, true , false, false}),
			to_bitset({false, false, true , false, false}),
			to_bitset({false, false, true , false, false})
		}},
		{{
			to_bitset({false, false, false, false, false}),
			to_bitset({false, false, false, false, false}),
			to_bitset({true , true , true , true , false}),
			to_bitset({false, false, false, false, false}),
			to_bitset({false, false, false, false, false})
		}},
		{{
			to_bitset({false, false, true , false, false}),
			to_bitset({false, false, true , false, false}),
			to_bitset({false, false, true , false, false}),
			to_bitset({false, false, true , false, false}),
			to_bitset({false, false, false, false, false})
		}}
	}};


	
	const std::array<piece_rotation, 4> L_data = { {
		{{
			to_bitset({false, false, false, false, false}),
			to_bitset({false, false, true , false, false}),
			to_bitset({false, false, true , false, false}),
			to_bitset({false, false, true , true , false}),
			to_bitset({false, false, false, false, false})
		}},
		{{
			to_bitset({false, false, false, false, false}),
			to_bitset({false, false, false, false, false}),
			to_bitset({false, true , true , true , false}),
			to_bitset({false, true , false, false, false}),
			to_bitset({false, false, false, false, false})
		}},
		{{
			to_bitset({false, false, false, false, false}),
			to_bitset({false, true , true , false, false}),
			to_bitset({false, false, true , false, false}),
			to_bitset({false, false, true , false, false}),
			to_bitset({false, false, false, false, false})
		}},
		{{
			to_bitset({false, false, false, false, false}),
			to_bitset({false, false, false, true , false}),
			to_bitset({false, true , true , true , false}),
			to_bitset({false, false, false, false, false}),
			to_bitset({false, false, false, false, false})
		}}
	}};



	const std::array<piece_rotation, 4> L_mirrored_data = {{
		{{
			to_bitset({false, false, false, false, false}),
			to_bitset({false, false, true , false, false}),
			to_bitset({false, false, true , false, false}),
			to_bitset({false, true , true , false, false}),
			to_bitset({false, false, false, false, false})
		}},
		{{
			to_bitset({false, false, false, false, false}),
			to_bitset({false, true , false, false, false}),
			to_bitset({false, true , true , true , false}),
			to_bitset({false, false, false, false, false}),
			to_bitset({false, false, false, false, false})
		}},
		{{
			to_bitset({false, false, false, false, false}),
			to_bitset({false, false, true , true , false}),
			to_bitset({false, false, true , false, false}),
			to_bitset({false, false, true , false, false}),
			to_bitset({false, false, false, false, false})
		}},
		{{
			to_bitset({false, false, false, false, false}),
			to_bitset({false, false, false, false, false}),
			to_bitset({false, true , true , true , false}),
			to_bitset({false, false, false, true , false}),
			to_bitset({false, false, false, false, false})
		}}
	}};


	
	const std::array<piece_rotation, 4> N_data = {{
		{{
			to_bitset({false, false, false, false, false}),
			to_bitset({false, false, false, true , false}),
			to_bitset({false, false, true , true , false}),
			to_bitset({false, false, true , false, false}),
			to_bitset({false, false, false, false, false})
		}},
		{{
			to_bitset({false, false, false, false, false}),
			to_bitset({false, false, false, false, false}),
			to_bitset({false, true , true , false, false}),
			to_bitset({false, false, true , true , false}),
			to_bitset({false, false, false, false, false})
		}},
		{{
			to_bitset({false, false, false, false, false}),
			to_bitset({false, false, true , false, false}),
			to_bitset({false, true , true , false, false}),
			to_bitset({false, true , false, false, false}),
			to_bitset({false, false, false, false, false})
		}},
		{{
			to_bitset({false, false, false, false, false}),
			to_bitset({false, true , true , false, false}),
			to_bitset({false, false, true , true , false}),
			to_bitset({false, false, false, false, false}),
			to_bitset({false, false, false, false, false})
		}}
	}};

	
	const std::array<piece_rotation, 4> N_mirrored_data = {{
		{{
			to_bitset({false, false, false, false, false}),
			to_bitset({false, false, true , false, false}),
			to_bitset({false, false, true , true , false}),
			to_bitset({false, false, false, true , false}),
			to_bitset({false, false, false, false, false})
		}},
		{{
			to_bitset({false, false, false, false, false}),
			to_bitset({false, false, false, false, false}),
			to_bitset({false, false, true , true , false}),
			to_bitset({false, true , true , false, false}),
			to_bitset({false, false, false, false, false})
		}},
		{{
			to_bitset({false, false, false, false, false}),
			to_bitset({false, true , false, false, false}),
			to_bitset({false, true , true , false, false}),
			to_bitset({false, false, true , false, false}),
			to_bitset({false, false, false, false, false})
		}},
		{{
			to_bitset({false, false, false, false, false}),
			to_bitset({false, false, true , true , false}),
			to_bitset({false, true , true , false, false}),
			to_bitset({false, false, false, false, false}),
			to_bitset({false, false, false, false, false})
		}}
	}};


	const std::array<piece_rotation, 4> T_data = {{
		{{
			to_bitset({false, false, false, false, false}),
			to_bitset({false, false, true , false, false}),
			to_bitset({false, false, true , true , false}),
			to_bitset({false, false, true , false, false}),
			to_bitset({false, false, false, false, false})
		}},
		{{
			to_bitset({false, false, false, false, false}),
			to_bitset({false, false, false, false, false}),
			to_bitset({false, true , true , true , false}),
			to_bitset({false, false, true , false, false}),
			to_bitset({false, false, false, false, false})
		}},
		{{
			to_bitset({false, false, false, false, false}),
			to_bitset({false, false, true , false, false}),
			to_bitset({false, true , true , false, false}),
			to_bitset({false, false, true , false, false}),
			to_bitset({false, false, false, false, false})
		}},
		{{
			to_bitset({false, false, false, false, false}),
			to_bitset({false, false, true , false, false}),
			to_bitset({false, true , true , true , false}),
			to_bitset({false, false, false, false, false}),
			to_bitset({false, false, false, false, false})
		}}
	}};

	const std::array<std::pair<int, int>, 4> init_positions_square = {
		std::make_pair(2, -3),
		std::make_pair(2, -3),
		std::make_pair(2, -3),
		std::make_pair(2, -3),
	};

	const std::array<std::pair<int, int>, 4> init_positions_I = {
		std::make_pair(2, -2),
		std::make_pair(2, -3),
		std::make_pair(2, -2),
		std::make_pair(2, -3),
	};

	const std::array<std::pair<int, int>, 4> init_positions_L = {
		std::make_pair(2, -3),
		std::make_pair(2, -3),
		std::make_pair(2, -2),
		std::make_pair(2, -2),
	};



	const std::array<std::pair<int, int>, 4> init_positions_L_mirrored = {
		std::make_pair(2, -3),
		std::make_pair(2, -2),
		std::make_pair(2, -3),
		std::make_pair(2, -3),
	};

	const std::array<std::pair<int, int>, 4> init_positions_N = {
		std::make_pair(2, -3),
		std::make_pair(2, -3),
		std::make_pair(2, -3),
		std::make_pair(2, -2),
	};

	const std::array<std::pair<int, int>, 4> init_positions_N_mirrored = {
		std::make_pair(2, -3),
		std::make_pair(2, -3),
		std::make_pair(2, -3),
		std::make_pair(2, -2),
	};

	const std::array<std::pair<int, int>, 4> init_positions_T = {
		std::make_pair(2, -3),
		std::make_pair(2, -3),
		std::make_pair(2, -3),
		std::make_pair(2, -2),
	};

	const sf::Color square_color = sf::Color::Yellow;
	const sf::Color I_color = sf::Color::Cyan;
	const sf::Color L_color(255, 134, 0);  // orange
	const sf::Color L_mirrored_color = sf::Color::Blue;
	const sf::Color N_color = sf::Color::Red;
	const sf::Color N_mirrored_color = sf::Color::Green;
	const sf::Color T_color = sf::Color::Magenta;

}
