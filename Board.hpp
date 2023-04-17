#pragma once
#include "Pieces.hpp"
#include <iostream>
#include <QObject>

class Board: public QObject {
	Q_OBJECT
private:
	Piece* boardState[8][8];
	void addPiece(Piece* piece, int row, int col);
	bool boundaries(int row, int column);
public:
	Board();
	Piece* getPiece(int row, int col) const;


	void printPieceAtPosition(std::pair<int, int> position) const {
		int row = position.first;
		int col = position.second;
		Piece* piece = boardState[row][col];

		if (piece == nullptr) {
			std::cout << "No piece at position (" << row << ", " << col << ")" << std::endl;
		}
		else {
			std::cout << "Piece at position (" << row << ", " << col << "): ";
			std::cout << "Piece: " << piece->getPiece() << ", "; // K (King), B (Bishop) ou k (Knight)
			std::cout << "Color: " << static_cast<int>(piece->getColor()) << std::endl; // imprime 0 pour White et 1 pour Black
		}
	}

	bool checkIfPieceOnTile(std::pair<int, int> newPosition, std::pair<int, int> currentPosition) const {
		if (boardState[newPosition.first][newPosition.second] != nullptr &&
			boardState[newPosition.first][newPosition.second]->getColor() != boardState[currentPosition.first][currentPosition.second]->getColor()) {
			return true; // Valid move to capture opponent's piece
		}
		else if (boardState[newPosition.first][newPosition.second] == nullptr) {
			return true; // Valid move to an empty square
		}
		return false;
	}

	bool noPiecesOnPath(std::pair<int, int> newPosition, std::pair<int, int> currentPosition) const {
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
			if (boardState[row][col] != nullptr /*|| !boundaries(row, col)*/) {
				std::cout << boardState[row][col]->getPiece();
				return false; // Path not clear
			}
		}
		return true; // Path clear
	}

	void addPiece(Piece* piece, int row, int column) {
		boardState[row][column] = piece;
	}

	void movePiece(std::pair<int, int> fromPosition, std::pair<int, int> toPosition) {
		Piece* piece = boardState[fromPosition.first][fromPosition.second];
		if ((piece != nullptr) && (piece->isValidMove(toPosition, fromPosition, *this))) {
			piece->moveTo(toPosition);
			boardState[toPosition.first][toPosition.second] = piece;
			boardState[fromPosition.first][fromPosition.second] = nullptr; // a verifier que ca marche vraiment
		}
	}

	std::pair<int, int> findKing(PieceColor color) const {
		Piece* piece = nullptr;
		std::pair<int, int> kingPosition;

		// trouve la position du roi sur le board
		for (int row = 0; row < 8; row++) {
			for (int column = 0; column < 8; column++) {
				piece = boardState[row][column];
				if (piece != nullptr && piece->getPiece() == 'K' && piece->getColor() == color) {
					kingPosition.first = row;
					kingPosition.second = column;
					return kingPosition;
				}
			}
		}/*
		throw ErrorNoPieceFound("No king found");*/
	}

	bool isCheck(PieceColor color) const {
		Piece* piece = nullptr;
		std::pair<int, int> kingPosition = findKing(color);

		/*try { std::pair<int, int> kingPosition = findKing(color); }
		catch (ErrorNoPieceFound& e) {
			Board board;
			Piece* piece = new King(PieceColor::White, 'K');
			board.addPiece(piece, 7, 7);
			std::cout << "Erreur: " << e.what() << std::endl;
		}*/
		std::pair<int, int> piecePosition;
		// check les pieces qui peuvent attaquer le roi
		for (int row = 0; row < 8; ++row) {
			for (int column = 0; column < 8; ++column) {
				piece = boardState[row][column];
				piecePosition.first = row;
				piecePosition.second = column;
				if (piece != nullptr && piece->getColor() != color && piece->isValidMove(kingPosition, piecePosition, *this)) {
					return true;
				}
			}
		}
		return false;
	}

	bool boundaries(int row, int column) const {
		return (row >= 0 && row < 8 && column >= 0 && column < 8); // retourne vrai si la piece sort pas du plateau
	}
	public slots:
		void movePiece();
	signals:
	void pieceSelected();

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
