#pragma once
#include <memory>

#include "Board.hpp"
#include "Piece.hpp"
#include "Drawer.hpp"
#include "PieceGenerator.hpp"

namespace Game
{
	class Game
	{
	public:
		Game(int board_width, int board_heigth, int block_size);
		void get_user_input();
		void update_game_state();
		void draw_game();
		bool is_game_over() const;
		void move_piece(int dx, int dy);
		void hard_drop_piece();
		void rotate_piece(int r);
		void hold_piece();
		Board::Board get_board() const;
		Piece::Piece get_current_piece() const;
		Piece::Piece get_piece_on_hold() const;
		std::vector<Piece::Piece> preview_pieces(int n);
		bool current_piece_exists() const;
		bool piece_on_hold_exists() const;
		bool piece_movement_possible(int dx, int dy, int r);
	private:
		void create_new_piece();
		void drop_piece();
		bool piece_at_end_position();
		std::shared_ptr<Piece::Piece> current_piece;
		std::shared_ptr<Piece::Piece> piece_on_hold;
		Board::Board board;
		Drawer::Drawer drawer;
		PieceGenerator::PieceGenerator piece_generator;
		double frames_per_drop, frames_after_drop = 0;
		double lock_delay_frames = 180, frames_at_end_position = 0;
		bool hold_blocked = false, hard_drop_blocked = false;
	};
}
