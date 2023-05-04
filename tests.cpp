#include <iostream>
#include "Board.hpp"
#include "King.hpp"
#include "Bishop.hpp"
#include "Knight.hpp"

#if __has_include("gtest/gtest.h")
#include "gtest/gtest.h"
#endif
#ifdef TEST

TEST(King, everyAngles) {
	Board board; // create an empty chessboard
	King* king = new King({ 3, 3 }, PieceColor::White); // create a white king at position (3, 3)
	board.addPiece(king, 0, 4); // add the king to the board at its initial position
	EXPECT_EQ(king->isValidMove({ 3, 2 }, { 3, 3 }, board), true); // move left
	EXPECT_EQ(king->isValidMove({ 3, 4 }, { 3, 3 }, board), true); // move right
	EXPECT_EQ(king->isValidMove({ 2, 3 }, { 3, 3 }, board), true); // move up
	EXPECT_EQ(king->isValidMove({ 4, 3 }, { 3, 3 }, board), true); // move down
	EXPECT_EQ(king->isValidMove({ 2, 2 }, { 3, 3 }, board), true); // move top-left
	EXPECT_EQ(king->isValidMove({ 2, 4 }, { 3, 3 }, board), true); // move top-right
	EXPECT_EQ(king->isValidMove({ 4, 2 }, { 3, 3 }, board), true); // move bottom-left
	EXPECT_EQ(king->isValidMove({ 4, 4 }, { 3, 3 }, board), true); // move bottom-right
	delete king;
}

TEST(King, moreThanOneStep) {
	Board board; // create an empty chessboard
	King* king = new King({ 3, 3 }, PieceColor::White); // create a white king at position (3, 3)
	board.addPiece(new King({ 3,3 }, PieceColor::White), 0, 4); // add the king to the board at its initial position
	EXPECT_EQ(king->isValidMove({ 3, 1 }, { 3, 3 }, board), false); //move two steps left
	EXPECT_EQ(king->isValidMove({ 3, 5 }, { 3, 3 }, board), false); // move two steps right
	EXPECT_EQ(king->isValidMove({ 1, 3 }, { 3, 3 }, board), false); // move two steps up
	EXPECT_EQ(king->isValidMove({ 5, 3 }, { 3, 3 }, board), false); // move two steps down
	EXPECT_EQ(king->isValidMove({ 1, 1 }, { 3, 3 }, board), false); // move two steps top-left
	EXPECT_EQ(king->isValidMove({ 1, 5 }, { 3, 3 }, board), false); // move two steps top-right
	EXPECT_EQ(king->isValidMove({ 5, 1 }, { 3, 3 }, board), false); // move two steps bottom-left
	EXPECT_EQ(king->isValidMove({ 5, 5 }, { 3, 3 }, board), false); // move two steps bottom-right
	delete king;
}

TEST(Knight, moveToEmptyTile) {
	Board board; // create an empty chessboard
	Knight knight({ 3, 3 }, PieceColor::White); // create a white knight at the center of the board
	board.addPiece(&knight, 3, 3); // add the knight to the board at its initial position
	
	// Move the knight to a valid position
	bool result = knight.isValidMove({ 1, 2 }, { 3, 3 }, board);
	EXPECT_EQ(result, true);
}

TEST(Knight, occupiedBySameTeam) {
	Board board; // create an empty chessboard
	Knight knight1({ 3, 3 }, PieceColor::White); // create a white knight at the center of the board
	Knight knight2({ 1, 2 }, PieceColor::White); // create another white knight at a valid destination
	board.addPiece(&knight1, 3, 3); // add the first knight to the board at its initial position
	board.addPiece(&knight2, 1, 2); // add the second knight to the board at the destination position
	
	// Try to move the first knight to the position of the second knight
	bool result = knight1.isValidMove({ 1, 2 }, { 3, 3 }, board);
	EXPECT_EQ(result, false);
}

TEST(Knight, capture) {
	Board board; // create an empty chessboard
	Knight knight1({ 3, 3 }, PieceColor::White); // create a white knight at the center of the board
	Knight knight2({ 1, 2 }, PieceColor::Black); // create a black knight at a valid destination
	board.addPiece(&knight1, 3, 3); // add the first knight to the board at its initial position
	board.addPiece(&knight2, 1, 2); // add the second knight to the board at the destination position
	
	// Move the first knight to capture the second knight
	bool result = knight1.isValidMove({ 1, 2 }, { 3, 3 }, board);
	EXPECT_EQ(result, true); // expected result: true
}

TEST(Bishop, tests) {
	// Arrange
	Board board;
	Bishop* bishop1 = new Bishop(PieceColor::Black);
	Bishop* bishop2 = new Bishop(PieceColor::White);
	Bishop* bishop3 = new Bishop(PieceColor::White);
	Knight* knight = new Knight(PieceColor::White);

	// Act
	board.addPiece(bishop1, 0, 0);
	board.addPiece(bishop2, 0, 0);
	board.addPiece(knight, 1, 1);
	board.addPiece(bishop3, 6, 6);
	board.addPiece(new Knight(PieceColor::Black), 7, 7);

	// Assert
	// Test isValidMove() for bishop1
	EXPECT_EQ(bishop1->isValidMove({ 1, 7 }, { 0, 0 }, board), false);

	// Test isValidMove() for bishop2
	EXPECT_EQ(bishop2->isValidMove({ 2, 2 }, { 0, 0 }, board), false);

	// Test isValidMove() for bishop3
	EXPECT_EQ(bishop3->isValidMove({ 7, 7 }, { 6, 6 }, board), true);

	// Test movePiece() for bishop1
	board.movePiece({ 0, 0 }, { 7, 7 });

	// Test printPieceAtPosition() for various positions
	board.printPieceAtPosition({ 0, 0 });
	board.printPieceAtPosition({ 1, 1 });
	board.printPieceAtPosition({ 6, 6 });
	board.printPieceAtPosition({ 7, 7 });

	delete bishop1;
	delete bishop2;
	delete bishop3;
	delete knight;
}

TEST(Piece, idk){
	Board board;
	
	// Test addPiece() method
	// Add a piece to the board and check if it's added at the correct position
	std::pair<int, int> position;
	position.first = 0;
	position.second = 0;
	
	Piece* piece = new King(PieceColor::White);
	board.addPiece(piece, 0, 0);
	EXPECT_EQ(board.isCheck(PieceColor::White), false);
	/*assert(board.isCheck(PieceColor::Black) == false);*/
	
	// Test movePiece() method
	// Move the piece to a new position and check if it's moved correctly
	std::pair<int, int> fromPosition(0, 0);
	std::pair<int, int> toPosition(1, 1);
	board.movePiece(fromPosition, toPosition);
	EXPECT_EQ(board.boundaries(1, 1), true);
	EXPECT_EQ(board.boundaries(8, 8), false);
	EXPECT_EQ(board.isCheck(PieceColor::White), false);
	/*assert(board.isCheck(PieceColor::Black) == false);*/
	
	// Test findKing() method
	// Add a black king to the board and check if findKing() returns its correct position
	Piece* blackKing = new King(PieceColor::Black);
	board.addPiece(blackKing, 7, 7);
	std::pair<int, int> kingPosition = board.findKing(PieceColor::Black);
	EXPECT_EQ(kingPosition.first, 7);
	EXPECT_EQ(kingPosition.second, 7);
	
	//// Test isCheck() method
	//// Add a white bishop attacking the black king and check if isCheck() returns true
	Piece* whiteBishop = new Bishop(PieceColor::White);
	board.addPiece(whiteBishop, 5, 5);
	EXPECT_EQ(board.isCheck(PieceColor::Black), true);
	EXPECT_EQ(board.isCheck(PieceColor::White), false);
	
	//// Test boundaries() method
	//// Check if the boundaries() method returns correct results for various positions
	EXPECT_EQ(board.boundaries(-1, 0), false);
	EXPECT_EQ(board.boundaries(0, -1), false);
	EXPECT_EQ(board.boundaries(8, 0), false);
	EXPECT_EQ(board.boundaries(0, 8), false);
	
	//// Clean up dynamically allocated memory
	delete piece;
	delete blackKing;
	delete whiteBishop;

	
}

//int main() {
//	testKnight();
//	return 0;
//}
//


#endif