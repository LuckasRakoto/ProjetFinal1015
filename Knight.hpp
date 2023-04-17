#pragma once
#include "Pieces.hpp"
#include "Board.hpp"

class Knight : public Piece {
public:
	/*Horse(char color);*/ //positionner le cavalier à son endroit respectif pour sa couleur
	Knight(std::pair<int, int> position, PieceColor couleur) : Piece(position, 'k', couleur) {} // creation knight (small k)
	~Knight() = default;
	Knight(PieceColor color, char piece) : Piece(color, 'k') {}

	bool isValidMove(std::pair<int, int> newPosition, std::pair<int, int> currentPosition, const Board& board);
};
