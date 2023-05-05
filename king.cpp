#include "King.hpp"

King::King(std::pair<int, int> position, PieceColor couleur) : Piece(position, 'K', couleur) {
	count_++;
	std::cout << count_ << " C1 \n";
	if (couleur == PieceColor::White) {
		image_ = "pieces/wking.png";
	}
	else if (couleur == PieceColor::Black) {
		image_ = "pieces/bking.png";
	}
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

bool King::leaveSpaceBetweenKings(std::pair<int, int> toPosition, std::pair<int, int> kingPosition) {
	int diffRow = abs(kingPosition.first - toPosition.first);
	int diffColumn = abs(kingPosition.second - toPosition.second);
	if (diffRow <= 1 && diffColumn <= 1) {
		return true;
	}
	return false;
}

bool King::isValidMove(std::pair<int, int> newPosition, std::pair<int, int> currentPosition, Board& board) /*override*/ {

	int diffRow = abs(newPosition.first - currentPosition.first);
	int diffColumn = abs(newPosition.second - currentPosition.second);

	if (diffRow <= 1 && diffColumn <= 1) {

		//PiecePlacer placer(board, this, newPosition); //Simule si le roi bouge sur la nouvelle case
		//if (placer.isCancelled()) {
		//	std::cout << "Move king cancelled" << std::endl;
		//}
		//else {
		//	std::cout << "King moved" << std::endl;
		//}

		/*Board boardCopy = board;
		boardCopy.movePiece(currentPosition, newPosition);
		if (!boardCopy.isCheck(this->getColor())) {
			return board.checkIfAbleToMove(newPosition, currentPosition);
		}*/
		return board.checkIfAbleToMove(newPosition, currentPosition);
	}
	return false;
}