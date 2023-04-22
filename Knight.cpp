#include "Knight.hpp"

Knight::Knight(std::pair<int, int> position, PieceColor couleur) : Piece(position, 'N', couleur) {
	if (couleur == PieceColor::White) {
		image_ = "./pieces/wknight.png";
	}
	else if (couleur == PieceColor::Black) {
		image_ = "./pieces/bknight.png";
	}
}

bool Knight::isValidMove(std::pair<int, int> newPosition, std::pair<int, int> currentPosition, Board& board) /*override*/ {

	int diffRow = abs(newPosition.first - position_.first);
	int diffColumn = abs(newPosition.second - position_.second);
	std::cout << "diff row " << diffRow << "diff col " << diffColumn << std::endl;
	std::cout << "1.\n";
	if (board.boundaries(newPosition.first, newPosition.second)) {
		std::cout << "2.\n";
		if ((diffRow == 2 && diffColumn == 1) || (diffRow == 1 && diffColumn == 2)) {
			std::cout << "3.\n";
			return true;
			}
		else {
			std::cout << "4.\n";
			return false;
		}
	}
	else return false;
}