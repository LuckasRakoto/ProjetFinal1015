#pragma once
#include "Pieces.hpp"
#include "Board.hpp"

// Classe implementant le RAII: 
// pour qu�une fonction utilisant cette classe puisse mettre
// temporairement une pi�ce � un endroit sur l��chiquier, et que la pi�ce s�enl�ve automatiquement � la
// destruction de l�instance

class PiecePlacer {
public:
	PiecePlacer(Board& board, Piece* piece, std::pair<int, int> newPosition) : boardCopy_(board), tryPosition_(newPosition) {
		currentPosition_ = piece->getPosition();
		if (!piece->isValidMove(newPosition, currentPosition_, board) && (newPosition != currentPosition_)) {
			cancelled_ = true;
		}
		else {
			boardCopy_.placePiece(piece, currentPosition_, tryPosition_);
			cancelled_ = false;
		}
	}

	~PiecePlacer() {
		if (!cancelled_) {
			boardCopy_.placePiece(nullptr, currentPosition_, tryPosition_);
		}
	}


private:
	Board& boardCopy_;
	std::pair<int, int> currentPosition_;
	std::pair<int, int> tryPosition_;
	bool cancelled_;
};
