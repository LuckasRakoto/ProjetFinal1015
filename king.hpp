#pragma once
#include "Pieces.hpp"
#include "Board.hpp"
#include <stdexcept>
#include <iostream>

class King : public Piece {
private:
	static int count_;
public:
	King(std::pair<int, int> position, PieceColor couleur); // creation king (K)
	King(PieceColor color);
	~King();

	bool isValidMove(std::pair<int, int> newPosition, std::pair<int, int> currentPosition, Board& board) override;
};
