#include "Pieces.hpp"

void Piece::moveTo(std::pair<int, int> newPosition) { //Deplacement de position (apres validation)
	 position_.first = newPosition.first;
	 position_.second = newPosition.second;
	 std::cout << "New Postion: " << position_.first << ", " << position_.second << std::endl;
}