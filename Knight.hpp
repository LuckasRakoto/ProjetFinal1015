#pragma once
#include "Pieces.hpp"
#include "Board.hpp"

class Knight : public Piece {
public:
	/*Horse(char color);*/ //positionner le cavalier à son endroit respectif pour sa couleur
	Knight(std::pair<int, int> position, PieceColor couleur); // creation knight (small k)
	~Knight() = default;
	Knight(PieceColor color) : Piece(color, 'k') {}

	bool isValidMove(std::pair<int, int> newPosition, std::pair<int, int> currentPosition, Board& board) override;
};
