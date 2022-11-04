#include "Game.hpp"

#include "SFML/Window.hpp"

namespace Game
{
	Game::Game(int board_width, int board_heigth, int block_size, int fps) : board(board_width, board_heigth), drawer(block_size, fps), frames_per_drop(1 / 0.01667)
	{
	}

	void Game::get_user_input()
	{
		sf::Event event;
		if (current_piece_exists() && drawer.window.pollEvent(event)) {
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left) {
					if (piece_movement_possible(-1, 0, 0))
						move_piece(-1, 0);
				}
				if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down) {
					if (piece_movement_possible(0, 1, 0))
						move_piece(0, 1);
				}
				if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right) {
					if (piece_movement_possible(1, 0, 0))
						move_piece(1, 0);
				}
				if (event.key.code == sf::Keyboard::Z) {
					if (piece_movement_possible(0, 0, -1))
						rotate_piece(-1);
				}
				if (event.key.code == sf::Keyboard::X) {
					if (piece_movement_possible(0, 0, 1))
						rotate_piece(1);
				}
				if (event.key.code == sf::Keyboard::C || event.key.code == sf::Keyboard::LControl) {
					if (current_piece_exists())
						hold_piece();
				}
				if (event.key.code == sf::Keyboard::Space && !hard_drop_blocked) {
					hard_drop_piece();
					frames_at_end_position = lock_delay_frames;
					hard_drop_blocked = true;
				}
			}
			if (event.type == sf::Event::KeyReleased) {  // unblock hard drop
				if (event.key.code == sf::Keyboard::Space) {
					hard_drop_blocked = false;
				}
			}
		}
	}

	void Game::update_game_state()
	{
		if (!current_piece_exists()) {
			create_new_piece();
			frames_at_end_position = 0;
		}
		
		if (piece_at_end_position()) {
			++frames_at_end_position;
			if ((!piece_movement_possible(1, 0, 0) && !piece_movement_possible(-1, 0, 0) &&
				 !piece_movement_possible(0, 0, 1) && !piece_movement_possible(0, 0, -1)) ||
				 frames_at_end_position >= lock_delay_frames) {
				board.store_piece(*current_piece);
				board.clear_full_lines();
				current_piece = nullptr;
				hold_blocked = false;
			}			
		}
		else {
			++frames_after_drop;
			if (frames_after_drop > frames_per_drop) {
				drop_piece();
				frames_after_drop = 0;
			}
		}
	}

	void Game::draw_game()
	{
		drawer.draw_game(*this);
	}

	bool Game::is_game_over() const
	{
		return board.first_row_has_blocks();
	}

	void Game::move_piece(int dx, int dy)
	{
		current_piece->move(dx, dy);
	}

	void Game::hard_drop_piece()
	{
		while (piece_movement_possible(0, 1, 0)) {
			move_piece(0, 1);
		}
	}

	void Game::rotate_piece(int r)
	{
		current_piece->rotate(r);
	}

	void Game::hold_piece()
	{
		if (!hold_blocked) {
			if (piece_on_hold == nullptr) {
				piece_on_hold = current_piece;
				create_new_piece();
			}
			else {
				piece_on_hold.swap(current_piece);
				current_piece->reset_position();
			}
			hold_blocked = true;
		}
	}

	Board::Board Game::get_board() const
	{
		return board;
	}

	Piece::Piece Game::get_current_piece() const
	{
		return *current_piece;
	}

	Piece::Piece Game::get_piece_on_hold() const
	{
		return *piece_on_hold;
	}

	std::vector<Piece::Piece> Game::preview_pieces(int n)
	{
		return piece_generator.preview_pieces(n);
	}

	bool Game::current_piece_exists() const
	{
		return current_piece != nullptr;
	}

	bool Game::piece_on_hold_exists() const
	{
		return piece_on_hold != nullptr;
	}

	bool Game::piece_movement_possible(int dx, int dy, int r)
	{
		// try movement
		move_piece(dx, dy);
		rotate_piece(r);
		bool movement_possible = true;
		for (int piece_y = 0; piece_y < current_piece->get_height(); piece_y++) {
			for (int piece_x = 0; piece_x < current_piece->get_width(); piece_x++) {
				if (current_piece->block_is_full(piece_x, piece_y)) {
					int board_x = piece_x + current_piece->get_x_pos();
					int board_y = piece_y + current_piece->get_y_pos();
					if (board.block_in_board(board_x, board_y) && board.block_is_full(board_x, board_y)) {
						// block collision
						movement_possible = false;
						break;
					}
					if (!board.block_in_board(board_x, board_y) && board_y >= 0) {
						// block out of bounds
						movement_possible = false;
						break;
					}

				}
			}
		}
		// undo movement
		move_piece(-dx, -dy);
		rotate_piece(-r);
		return movement_possible;
	}

	void Game::create_new_piece()
	{
		current_piece = std::make_shared<Piece::Piece>(piece_generator.generate_piece());
	}

	void Game::drop_piece()
	{
		if (piece_movement_possible(0, 1, 0))
			move_piece(0, 1);
	}

	bool Game::piece_at_end_position()
	{
		return !piece_movement_possible(0, 1, 0);
	}



}
