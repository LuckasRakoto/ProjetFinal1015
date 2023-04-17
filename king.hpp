#pragma once
#include "Pieces.hpp"
//#include "Board.hpp"

class King : public Piece {
public:
	King(std::pair<int, int> position, PieceColor couleur) : Piece(position, 'K', couleur) {} // creation king (K)
	King(PieceColor color, char piece) : Piece(color, 'K') {}
	~King() = default;

	bool isValidMove(std::pair<int, int> newPosition, std::pair<int, int> currentPosition, const Board& board) /*override*/ {

		int diffRow = abs(newPosition.first - currentPosition.first);
		int diffColumn = abs(newPosition.second - currentPosition.second);

		/*if (board.boundaries(newPosition.first, newPosition.second)) {*/
		if (diffRow <= 1 && diffColumn <= 1) {
			//Simule si le roi bouge sur la nouvelle case
			/*Board boardCopy = board;
			boardCopy.movePiece(currentPosition, newPosition);
			if (!boardCopy.isCheck(getColor())) {*/
				return true;
			//}
		}
		else return false;
		/*}*/
		/*else {
			return false;
		}*/
	}
};