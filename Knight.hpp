#include "Pieces.hpp"
#include "Board.hpp"

class Knight : public Piece {
public:
	/*Horse(char color);*/ //positionner le cavalier à son endroit respectif pour sa couleur
	Knight(std::pair<int, int> position, PieceColor couleur) : Piece(position, 'k', couleur) {} // creation knight (small k)
	~Knight() = default;
	Knight(PieceColor color, char piece) : Piece(color, 'k') {}

	bool isValidMove(std::pair<int, int> newPosition, std::pair<int, int> currentPosition) override { // verifie si deplacement = une case
		int diffRow = abs(newPosition.first - position_.first);
		int diffColumn = abs(newPosition.second - position_.second);

		if ((diffRow == 2 && diffColumn == 1) || (diffRow == 1 && diffColumn == 2)) return true;
		else return false;
	}
};
