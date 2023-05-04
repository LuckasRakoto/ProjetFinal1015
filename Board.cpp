#include "Board.hpp"

Board::Board(): pieceSelected(false), whiteTurn(true) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			boardState[i][j] = nullptr;
		}
	}
};

void Board::placePiece(Piece* piece, std::pair<int, int> tryPosition) {
	Piece* p = boardState[tryPosition.first][tryPosition.second];

	if (p != nullptr) {
		throw std::runtime_error("A piece is already on this tile");
	}
	p = piece;
	//p->moveTo(tryPosition);
	addPiece(p, tryPosition.first, tryPosition.second);
}

Board::~Board() {
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			Piece* piece = boardState[i][j];
			if (piece != nullptr)
				delete piece;
		}
	}
}

void Board::addPiecesOnBoard() {
	addPiece(new King({ 0,4 }, PieceColor::White), 0, 4);
	addPiece(new Bishop({ 0,2 }, PieceColor::White), 0, 2);
	addPiece(new Bishop({ 0,5 }, PieceColor::White), 0, 5);
	addPiece(new Knight({ 0,1 }, PieceColor::White), 0, 1);
	addPiece(new Knight({ 0,6 }, PieceColor::White), 0, 6);

	addPiece(new King({ 7,4 }, PieceColor::Black), 7, 4);
	addPiece(new Bishop({ 7,2 }, PieceColor::Black), 7, 2);
	addPiece(new Bishop({ 7,5 }, PieceColor::Black), 7, 5);
	addPiece(new Knight({ 7,1 }, PieceColor::Black), 7, 1);
	addPiece(new Knight({ 7,6 }, PieceColor::Black), 7, 6);
}

void Board::addPiece(Piece* piece, int row, int col) {
	boardState[row][col] = piece;
}

void Board::printPieceAtPosition(std::pair<int, int> position) {
	int row = position.first;
	int col = position.second;
	Piece* piece = boardState[row][col];

	if (piece == nullptr) {
		std::cout << "No piece at position (" << row << ", " << col << ")" << std::endl;
	}
	else {
		std::cout << "Piece at position (" << row << ", " << col << "): ";
		std::cout << "Piece: " << piece->getPiece() << ", "; // K (King), B (Bishop) ou k (Knight)
		if (static_cast<int>(piece->getColor()) == 0) { // 0 pour White et 1 pour Black
			std::cout << "Color: White" << std::endl;
		}
		else {
			std::cout << "Color: Black" << std::endl;
		}
	}
}


Piece* Board::getPiece(int row, int col) const {
	return boardState[row][col];
}

bool Board::boundaries(int row, int column) {
	return (row >= 0 && row < 8 && column >= 0 && column < 8);
}

bool Board::checkIfAbleToMove(std::pair<int, int> newPosition, std::pair<int, int> currentPosition) {
	
	if ((boardState[currentPosition.first][currentPosition.second] != nullptr) && (boundaries(newPosition.first, newPosition.second))) {
		if (boardState[newPosition.first][newPosition.second] != nullptr) {
			PieceColor color = boardState[currentPosition.first][currentPosition.second]->getColor();
			if (boardState[newPosition.first][newPosition.second]->getColor() != color) {
				return true; // Valid move to capture opponent's piece
			}
		}
		else if (boardState[newPosition.first][newPosition.second] == nullptr) {
			return true; // Valid move to an empty square
		}
	}
	return false;
}

bool Board::noPiecesOnPath(std::pair<int, int> newPosition, std::pair<int, int> currentPosition) const {
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
		if (boardState[row][col] != nullptr /*|| !boundaries(row, col)*/) {
			std::cout << boardState[row][col]->getPiece();
			return false; // Path not clear

		}
	}
	return true; // Path clear
}

bool Board::movePiece(std::pair<int, int> fromPosition, std::pair<int, int> toPosition) {
	Piece* piece = boardState[fromPosition.first][fromPosition.second];
	if (!(piece->isValidMove(toPosition, fromPosition, *this))) return false;
	if (piece != nullptr) {
		piece->moveTo(toPosition);
		boardState[toPosition.first][toPosition.second] = piece;
		boardState[fromPosition.first][fromPosition.second] = nullptr; // a verifier que ca marche vraiment
		return true;
	}
	else {
		std::cout << "Don't move piece\n";
	}
}

std::pair<int, int> Board::findKing(PieceColor color) const {
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

bool Board::isCheck(PieceColor color) {
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

void Board::selectPiece(int row, int col) {
	if (boardState[row][col]->getColor() == PieceColor::White && whiteTurn) {
		pieceSelected = true;
		selectedPiecePos = { row, col };
		return;
	}
	else if ((boardState[row][col]->getColor() == PieceColor::Black && !whiteTurn)){
		pieceSelected = true;
		selectedPiecePos = { row, col };
		return;
	}
	else return;

}

void Board::isClicked(int i, int j) {
	if (!pieceSelected && boardState[i][j] != nullptr) {
		selectPiece(i,j);
		std::cout << "on selectionnne" << std::endl;
		return;
	}
	else if (pieceSelected) {
		if (!(movePiece(selectedPiecePos, { i,j }))) return;
		pieceSelected = false;
		std::cout << "on bouge" << std::endl;
		whiteTurn = !whiteTurn;
		emit boardChanged();
	}

}