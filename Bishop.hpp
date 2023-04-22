#pragma once
#include "Pieces.hpp"
#include "Board.hpp"
#include <cmath>

class Bishop : /*public Board,*/ public Piece {
public:
	/*Bishop(char color);*/ //positionner le fou à son endroit respectif pour sa couleur
	Bishop(std::pair<int, int> position, PieceColor couleur); // creation bishop (B)
	~Bishop() = default;
	Bishop(PieceColor color) : Piece(color, 'B') {}

	bool isValidMove(std::pair<int, int> newPosition, std::pair<int, int> currentPosition, Board& board) override;
};
