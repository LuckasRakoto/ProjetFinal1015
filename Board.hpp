#pragma once

#include <iostream>
#include <QObject>
#include "Pieces.hpp"
#include "King.hpp"
#include "Knight.hpp"
#include "Bishop.hpp"

class Board: public QObject {
	Q_OBJECT
private:
	Piece* boardState[8][8];
	std::pair<int, int> selectedPiecePos;
	bool pieceSelected;
	bool whiteTurn;
public:
	Board();
	~Board();

	// Copy constructor
	Board(const Board& other) {
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				Piece* piece = other.boardState[i][j];
				if (piece != nullptr) {
					Piece* newPiece = piece->clone();
					boardState[i][j] = newPiece;
				}
				else {
					boardState[i][j] = nullptr;
				}
			}
		}
		selectedPiecePos = other.selectedPiecePos;
		pieceSelected = other.pieceSelected;
		whiteTurn = other.whiteTurn;
	}

	void addPiece(Piece* piece, int row, int col);
	void addPiecesOnBoard();
	void placePiece(Piece* piece, std::pair<int, int> tryPosition);
	void printPieceAtPosition(std::pair<int, int> position);
	void selectPiece(int i, int j);
	
	Piece* getPiece(int row, int col) const;

	bool boundaries(int row, int column);
	bool checkIfAbleToMove(std::pair<int, int> newPosition, std::pair<int, int> currentPosition);
	bool movePiece(std::pair<int, int> fromPosition, std::pair<int, int> toPosition);
	bool noPiecesOnPath(std::pair<int, int> newPosition, std::pair<int, int> currentPosition);
	bool isCheck(PieceColor color);
	bool stillInCheck(PieceColor color, std::pair<int, int> newKingPosition);
	bool isCheckmate(PieceColor color, std::pair<int, int> kingPosition);

	std::pair<int, int> findKing(PieceColor color) const;


public slots:
	void isClicked(int i, int j);

signals:
	void boardChanged();
};