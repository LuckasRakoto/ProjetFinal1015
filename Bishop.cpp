#include "Bishop.hpp"

bool Bishop::isValidMove(std::pair<int, int> newPosition, std::pair<int, int> currentPosition, Board& board) /*override*/ {
	int diffRow = abs(newPosition.first - currentPosition.first);
	int diffColumn = abs(newPosition.second - currentPosition.second);

	if ((diffRow == diffColumn) && board.noPiecesOnPath(newPosition, currentPosition)) {
		return board.checkIfAbleToMove(newPosition, currentPosition);
	}
	else return false;
}