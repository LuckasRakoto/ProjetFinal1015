#pragma once
#include "Pieces.hpp"
#include "Board.hpp"
#include <cmath>

class Bishop : /*public Board,*/ public Piece {
public:
	/*Bishop(char color);*/ //positionner le fou à son endroit respectif pour sa couleur
	Bishop(std::pair<int, int> position, PieceColor couleur) : Piece(position, 'B', couleur) {} // creation bishop (B)
	~Bishop() = default;
	Bishop(PieceColor color, char piece) : Piece(color, 'B') {}

	bool isValidMove(std::pair<int, int> newPosition, std::pair<int, int> currentPosition, Board& board) /*override*/ {
		int diffRow = abs(newPosition.first - currentPosition.first);
		int diffColumn = abs(newPosition.second - currentPosition.second);

		if ((diffRow == diffColumn) && board.noPiecesOnPath(newPosition, currentPosition)) {
			return board.checkIfPieceOnTile(newPosition, currentPosition);
		}
		else return false;
	}
};
