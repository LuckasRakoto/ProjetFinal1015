#include "King.hpp"
#include <iostream>

King::King(std::pair<int, int> position, PieceColor couleur) : Piece(position, 'K', couleur) {
	count_++;
	std::cout << count_ << " C1 \n";
	/*if (count_ > 2) {
		throw std::logic_error("Plus que 2 rois");
	}*/
}

King::King(PieceColor color) : Piece(color, 'K') {
	count_++;
	std::cout << count_ << " C2 \n";
	if (count_ > 2) {
		throw std::logic_error("Plus que 2 rois");
	}
}

King::~King() {
	count_--;
}

int King::count_ = 0;

bool King::isValidMove(std::pair<int, int> newPosition, std::pair<int, int> currentPosition, Board& board) /*override*/ {

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