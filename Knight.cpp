#include "Knight.hpp"

Knight::Knight(std::pair<int, int> position, PieceColor couleur) : Piece(position, 'N', couleur) {
	if (couleur == PieceColor::White) {
		image_ = "pieces/wknight.png";
	}
	else if (couleur == PieceColor::Black) {
		image_ = "pieces/bknight.png";
	}
}

bool Knight::isValidMove(std::pair<int, int> newPosition, std::pair<int, int> currentPosition, Board& board) /*override*/ {

	int diffRow = abs(newPosition.first - currentPosition.first);
	int diffColumn = abs(newPosition.second - currentPosition.second);

	if (board.boundaries(newPosition.first, newPosition.second)) {
		if ((diffRow == 2 && diffColumn == 1) || (diffRow == 1 && diffColumn == 2)) {
			return board.checkIfAbleToMove(newPosition, currentPosition);
			}
		else {
			return false;
		}
	}
	else return false;

}