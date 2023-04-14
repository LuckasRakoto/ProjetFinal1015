#include <iostream>
#include <cassert>
#include "Board.hpp"
#include "King.hpp"
#include "Bishop.hpp"
#include "Knight.hpp"


void testBishop() {
	// Arrange
	Board board;
	Bishop* bishop1 = new Bishop(PieceColor::Black, 'B');
	Bishop* bishop2 = new Bishop(PieceColor::White, 'B');
	Bishop* bishop3 = new Bishop(PieceColor::White, 'B');
	Knight* knight = new Knight(PieceColor::White, 'k');

	// Act
	board.addPiece(bishop1, 0, 0);
	board.addPiece(bishop2, 0, 0);
	board.addPiece(knight, 1, 1);
	board.addPiece(bishop3, 6, 6);
	board.addPiece(new Knight(PieceColor::Black, 'k'), 7, 7);

	// Assert
	// Test isValidMove() for bishop1
	assert(bishop1->isValidMove({ 1, 7 }, { 0, 0 }) == false);

	// Test isValidMove() for bishop2
	/*assert(bishop2->isValidMove({2, 2}, {0, 0}) == false);*/

	// Test isValidMove() for bishop3
	assert(bishop3->isValidMove({ 7, 7 }, { 6, 6 }) == true);

	// Test movePiece() for bishop1
	board.movePiece({ 0, 0 }, { 7, 7 });

	// Test printPieceAtPosition() for various positions
	board.printPieceAtPosition({ 0, 0 });
	board.printPieceAtPosition({ 7, 7 });

	delete bishop1;
	delete bishop2;
	delete bishop3;
	delete knight;
}

//int main() {
//	testBishop();
//	return 0;
//}

//Test Piece
//int main() {
//	Board board;
//
//	// Test addPiece() method
//	// Add a piece to the board and check if it's added at the correct position
//	std::pair<int, int> position;
//	position.first = 0;
//	position.second = 0;
//
//	Piece* piece = new King(PieceColor::White, 'K');
//	board.addPiece(piece, 0, 0);
//	assert(board.boundaries(0, 0));
//	assert(board.isCheck(PieceColor::White) == false);
//	/*assert(board.isCheck(PieceColor::Black) == false);*/
//
//	// Test movePiece() method
//	// Move the piece to a new position and check if it's moved correctly
//	std::pair<int, int> fromPosition(0, 0);
//	std::pair<int, int> toPosition(1, 1);
//	board.movePiece(fromPosition, toPosition);
//	assert(board.boundaries(1, 1) == true);
//	assert(board.boundaries(8, 8) == false);
//	assert(board.isCheck(PieceColor::White) == false);
//	/*assert(board.isCheck(PieceColor::Black) == false);*/
//
//	// Test findKing() method
//	// Add a black king to the board and check if findKing() returns its correct position
//	Piece* blackKing = new King(PieceColor::Black, 'K');
//	board.addPiece(blackKing, 7, 7);
//	std::pair<int, int> kingPosition = board.findKing(PieceColor::Black);
//	assert(kingPosition.first == 7);
//	assert(kingPosition.second == 7);
//
//	//// Test isCheck() method
//	//// Add a white bishop attacking the black king and check if isCheck() returns true
//	Piece* whiteBishop = new Bishop(PieceColor::White, 'B');
//	board.addPiece(whiteBishop, 5, 5);
//	assert(board.isCheck(PieceColor::Black) == true);
//	assert(board.isCheck(PieceColor::White) == false);
//
//	//// Test boundaries() method
//	//// Check if the boundaries() method returns correct results for various positions
//	assert(board.boundaries(0, 0));
//	assert(board.boundaries(7, 7));
//	assert(board.boundaries(-1, 0) == false);
//	assert(board.boundaries(0, -1) == false);
//	assert(board.boundaries(8, 0) == false);
//	assert(board.boundaries(0, 8) == false);
//
//	//// Clean up dynamically allocated memory
//	delete piece;
//	delete blackKing;
//	delete whiteBishop;
//
//	std::cout << "All tests passed successfully!" << std::endl;
//}