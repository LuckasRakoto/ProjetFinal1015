#include "Pieces.hpp"

class Board {
private:
	Piece* board_[8][8];
public:
	Board() {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				board_[i][j] = nullptr;
			}
		}
	}

	void addPiece(Piece* piece, int row, int column) {
		board_[row][column] = piece;
	}

	void movePiece(std::pair<int, int> fromPosition, std::pair<int, int> toPosition) {
		Piece* piece = board_[fromPosition.first][fromPosition.second];
		if((piece!=nullptr) && (piece->isValidMove(toPosition, *this))) {
			board_[toPosition.first][toPosition.second] = piece;
			board_[fromPosition.first][fromPosition.second] = nullptr; // a verifier que ca marche vraiment
		}
	}

	std::pair<int, int> findKing(PieceColor color) const {
		Piece* piece;
		std::pair<int, int> kingPosition;

		// trouve la position du roi sur le board
		for (int row = 0; row < 8; ++row) {
			for (int column = 0; column < 8; ++column) {
				piece = board_[row][column];
				if (piece->getPiece() == 'K' && piece->getColor() == color) {
					kingPosition.first = row;
					kingPosition.second = column;
					break; //devrait y avoir que un seul roi
				}
			}
		}
		return kingPosition;
	}

	bool isCheck(PieceColor color) const {
		Piece* piece;
		std::pair<int, int> kingPosition = findKing(color);
		
		// check les pieces qui peuvent attaquer le roi
		for (int row = 0; row < 8; ++row) {
			for (int column = 0; column < 8; ++column) {
				piece = board_[row][column];
				if (piece != nullptr && piece->getColor() != color && piece->isValidMove(kingPosition, *this)) {
					return true;
				}
			}
		}
		return false;
	}

	bool boundaries(int row, int column) {
		return (row >= 0 && row < 8 && column >= 0 && column < 8); // retourne vrai si la piece sort pas du plateau
	}

	bool isCheckmate(PieceColor color) {
		std::pair<int, int> kingPosition;
		std::pair<int, int> newPosition;
		std::pair<int, int> piecePosition;

		// trouve la position du roi
		if (isCheck(color)) { kingPosition = findKing(color); }
		else { return false; }

		int kingRow = kingPosition.first;
		int kingColumn = kingPosition.second;
		Piece* king = board_[kingRow][kingColumn];
		bool isStillInCheck;
		// check si le roi peut bouger
		for (int row = kingRow - 1; row < kingRow + 1; ++row) {
			for (int column = kingColumn - 1; column < kingColumn + 1; ++column) {
				if (boundaries(row, column) && (row != kingRow || column != kingRow)) {
					newPosition.first = row;
					newPosition.second = column;
					if (king->isValidMove(newPosition, *this)) {
						// If the king can move to the new position, return false
						movePiece(kingPosition, newPosition); //deplace roi temp pour voir si il est tjr en echec
						isStillInCheck = isCheck(color);
						// undoMove();
						if (!isStillInCheck) {
							return false;
						}
					}
				}
			}
		}

		Piece* piece;
		// check si une autre piece du joueur peut bloquer le check
		for (int row = 0; row < 8; ++row) {
			for (int column = 0; column < 8; ++column) {
				piece = board_[row][column];
				if (piece != nullptr && piece->getColor() == color) {
					for (int newRow = 0; newRow < 8; ++newRow) {
						for (int newColumn = 0; newColumn < 8; ++newColumn) {
							newPosition.first = newRow;
							newPosition.second = newColumn;
							if (piece->isValidMove(newPosition, *this)) {
								// If a piece can move to the new position to block the check
								piecePosition.first = row;
								piecePosition.second = column;
								movePiece(piecePosition, newPosition); //deplace piece temp pour voir si roi est tjr en echec
								isStillInCheck = isCheck(color);
								// undoMove();
								if (!isStillInCheck) { //si roi n'est plus en echec retourne faux
									return false;
								}
							}
						}
					}
				}
			}
		}
		return true;
	}



};
