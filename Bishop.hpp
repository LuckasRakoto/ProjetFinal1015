#include "Pieces.hpp"
#include "Board.hpp"
#include <cmath>

class Bishop : public Board, public Piece {
public:
	/*Bishop(char color);*/ //positionner le fou à son endroit respectif pour sa couleur
	Bishop(std::pair<int, int> position, PieceColor couleur) : Piece(position, 'B', couleur) {} // creation bishop (B)
	~Bishop() = default;
	Bishop(PieceColor color, char piece) : Piece(color, 'B') {}

	bool isValidMove(std::pair<int, int> newPosition, std::pair<int, int> currentPosition) override {
		int diffRow = abs(newPosition.first - currentPosition.first);
		int diffColumn = abs(newPosition.second - currentPosition.second);

		if ((diffRow == diffColumn) && noPiecesOnPath(newPosition, currentPosition)) {
			if (board_[newPosition.first][newPosition.second] != nullptr &&
				board_[newPosition.first][newPosition.second]->getColor() != this->getColor()) {
				return true; // Valid move to capture opponent's piece
			}
			else if (board_[newPosition.first][newPosition.second] == nullptr) {
				return true; // Valid move to an empty square
			}
		}
		else return false;
	}

	// Fonction qui verifie qu'il y a pas de piece qui bloque le passage en diagonale
	bool noPiecesOnPath(std::pair<int, int> newPosition, std::pair<int, int> currentPosition) {
		int rowDiff = abs(newPosition.first - currentPosition.first);
		int rowMove = 0;
		int columnMove = 0;

		// direction de mouvement de case (ligne)
		if (newPosition.first > currentPosition.first) rowMove = 1;
		else rowMove = -1;
		// direction de mouvement de case (colonne)
		if (newPosition.second > currentPosition.second) columnMove = 1;
		else columnMove = -1;

		int row, col;
		for (int i = 1; i < rowDiff; ++i) {
			row = currentPosition.first + i * rowMove;
			col = currentPosition.second + i * columnMove;
			std::cout << row << std::endl;
			std::cout << col << std::endl;
			if (board_[row][col] != nullptr /*|| !boundaries(row, col)*/) {
				std::cout << board_[row][col]->getPiece();
				return false; // Path not clear
			}
		}
		return true; // Path clear
	}
};
