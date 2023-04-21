#pragma once
#include "Pieces.hpp"
#include "Board.hpp"

// Classe implementant le RAII: 
// pour qu’une fonction utilisant cette classe puisse mettre
// temporairement une pièce à un endroit sur l’échiquier, et que la pièce s’enlève automatiquement à la
// destruction de l’instance

class PiecePlacer {
public:
	PiecePlacer(Board& board, Piece* piece, std::pair<int, int> Position) : board_(board), tryPosition_(Position) {
		board_.placePiece(piece, tryPosition_);
	}

	~PiecePlacer() {
		board_.placePiece(nullptr, tryPosition_);
	}

private:
	Board& board_;
	std::pair<int, int> tryPosition_;
};
