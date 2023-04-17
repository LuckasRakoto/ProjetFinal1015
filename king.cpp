#include "King.hpp"

bool King::isValidMove(std::pair<int, int> newPosition, std::pair<int, int> currentPosition, const Board& board) /*override*/ {

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