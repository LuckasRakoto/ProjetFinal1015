#pragma once
#include "Pieces.hpp"
#include "Board.hpp"

// Classe implementant le RAII: 
// pour qu�une fonction utilisant cette classe puisse mettre
// temporairement une pi�ce � un endroit sur l��chiquier, et que la pi�ce s�enl�ve automatiquement � la
// destruction de l�instance

class PiecePlacer {
public:
	PiecePlacer(Board& board, Piece* piece, std::pair<int, int> newPosition) : board_(board), tryPosition_(newPosition) {
		std::pair<int, int> currentPosition = piece->getPosition();
		if (!piece->isValidMove(newPosition, currentPosition, board)) {
			cancelled_ = true;
		}
		else {
			board_.placePiece(piece, tryPosition_);
			cancelled_ = false;
		}
	}

	~PiecePlacer() {
		if (cancelled_ == false) {
			board_.placePiece(nullptr, tryPosition_);
		}
	}

private:
	Board& board_;
	std::pair<int, int> tryPosition_;
	bool cancelled_;
};
