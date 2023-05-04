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

	std::pair<int, int> findKing(PieceColor color) const;


public slots:
	void isClicked(int i, int j);

signals:
	void boardChanged();

	// A TESTER
	//bool isCheckmate(PieceColor color) {
	//	std::pair<int, int> kingPosition;
	//	std::pair<int, int> newPosition;
	//	std::pair<int, int> piecePosition;

	//	// trouve la position du roi
	//	if (isCheck(color)) { kingPosition = findKing(color); }
	//	else { return false; }

	//	int kingRow = kingPosition.first;
	//	int kingColumn = kingPosition.second;
	//	Piece* king = board_[kingRow][kingColumn];
	//	bool isStillInCheck;
	//	// check si le roi peut bouger
	//	for (int row = kingRow - 1; row < kingRow + 1; ++row) {
	//		for (int column = kingColumn - 1; column < kingColumn + 1; ++column) {
	//			if (boundaries(row, column) && (row != kingRow || column != kingRow)) {
	//				newPosition.first = row;
	//				newPosition.second = column;
	//				if (king->isValidMove(newPosition, kingPosition)) {
	//					// If the king can move to the new position, return false
	//					movePiece(kingPosition, newPosition); //deplace roi temp pour voir si il est tjr en echec
	//					isStillInCheck = isCheck(color);
	//					// undoMove();
	//					if (!isStillInCheck) {
	//						return false;
	//					}
	//				}
	//			}
	//		}
	//	}

	//	Piece* piece;
	//	// check si une autre piece du joueur peut bloquer le check
	//	for (int row = 0; row < 8; ++row) {
	//		for (int column = 0; column < 8; ++column) {
	//			piece = board_[row][column];
	//			if (piece != nullptr && piece->getColor() == color) {
	//				for (int newRow = 0; newRow < 8; ++newRow) {
	//					for (int newColumn = 0; newColumn < 8; ++newColumn) {
	//						newPosition.first = newRow;
	//						newPosition.second = newColumn;
	//						if (piece->isValidMove(newPosition, piecePosition)) {
	//							// If a piece can move to the new position to block the check
	//							piecePosition.first = row;
	//							piecePosition.second = column;
	//							movePiece(piecePosition, newPosition); //deplace piece temp pour voir si roi est tjr en echec
	//							isStillInCheck = isCheck(color);
	//							// undoMove();
	//							if (!isStillInCheck) { //si roi n'est plus en echec retourne faux
	//								return false;
	//							}
	//						}
	//					}
	//				}
	//			}
	//		}
	//	}
	//	return true;
	//}
};