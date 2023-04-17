#pragma once
#include "Pieces.hpp"
//#include "Board.hpp"

class King : public Piece {
public:
	King(std::pair<int, int> position, PieceColor couleur) : Piece(position, 'K', couleur) {} // creation king (K)
	King(PieceColor color) : Piece(color, 'K') {}
	~King() = default;

	bool isValidMove(std::pair<int, int> newPosition, std::pair<int, int> currentPosition, Board& board);
};