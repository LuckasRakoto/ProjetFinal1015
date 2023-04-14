#include "Pieces.hpp"
#include "Board.hpp"

class King : public Piece {
public:
	King(std::pair<int, int> position, PieceColor couleur) : Piece(position, 'K', couleur) {} // creation king (K)
	King(PieceColor color, char piece) : Piece(color, 'K') {}
	~King() = default;

	bool isValidMove(std::pair<int, int> newPosition, std::pair<int, int> currentPosition) override {
		if (newPosition.first >= 0 && newPosition.first < 8 && newPosition.second >= 0 && newPosition.second < 8) {
			int diffRow = abs(newPosition.first - currentPosition.first);
			int diffColumn = abs(newPosition.second - currentPosition.second);

			if (diffRow <= 1 && diffColumn <= 1) return true;
			else return false;
		}
		else {
			return false;
		}
	}
};