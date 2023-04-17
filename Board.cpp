#include "Board.hpp"

Board::Board() {

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			boardState[i][j] = nullptr;
		}
	}

	addPiece(new King({ 0,5 }, 'w'), 0, 5);
	addPiece(new Bishop({ 0,2 }, 'w'), 0, 2);
	addPiece(new Bishop({ 0,5 }, 'w'), 0, 5);
	addPiece(new Knight({ 0,1 }, 'w'), 0, 1);
	addPiece(new Knight({ 0,6 }, 'w'), 0, 6);

	addPiece(new King({ 7,5 }, 'b'), 0, 5);
	addPiece(new Bishop({ 7,2 }, 'b'), 7, 2);
	addPiece(new Bishop({ 7,5 }, 'b'), 7, 5);
	addPiece(new Knight({ 7,1 }, 'b'), 7, 1);
	addPiece(new Knight({ 7,6 }, 'b'), 7, 6);
};

void Board::addPiece(Piece* piece, int row, int col) {
	boardState[row][col] = piece;
}

Piece* Board::getPiece(int row, int col) const {
	return boardState[row][col];;
}

bool Board::boundaries(int row, int column) {
	return (row >= 0 && row < 8 && column >= 0 && column < 8);
}