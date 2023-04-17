#include "Knight.hpp"

bool Knight::isValidMove(std::pair<int, int> newPosition, std::pair<int, int> currentPosition, Board& board) /*override*/ { // verifie si deplacement = une case

	int diffRow = abs(newPosition.first - position_.first);
	int diffColumn = abs(newPosition.second - position_.second);

	if (board.boundaries(newPosition.first, newPosition.second)) {
		if ((diffRow == 2 && diffColumn == 1) || (diffRow == 1 && diffColumn == 2)) return true;
		else return false;
	}
	else return false;
}