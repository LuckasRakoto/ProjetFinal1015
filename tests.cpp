//#include <iostream>
//#include <cassert>
//#include "Board.hpp"
//#include "King.hpp"
//#include "Bishop.hpp"
//#include "Knight.hpp"
//
//
//
//void testKing() {
//	Board board; // create an empty chessboard
//	King* king = new King({ 3, 3 }, PieceColor::White); // create a white king at position (3, 3)
//	board.addPiece(new King({ 0,4 }, PieceColor::White), 0, 4); // add the king to the board at its initial position
//
//	// Test case 1: King can move one step in any direction
//
//	// Test move to valid positions
//	/*assert(king->isValidMove({ 3, 2 }, { 3, 3 }, board) == true);*/ // move left
//	//assert(king.isValidMove({ 3, 4 }, { 3, 3 }, board) == true); // move right
//	//assert(king.isValidMove({ 2, 3 }, { 3, 3 }, board) == true); // move up
//	//assert(king.isValidMove({ 4, 3 }, { 3, 3 }, board) == true); // move down
//	//assert(king.isValidMove({ 2, 2 }, { 3, 3 }, board) == true); // move top-left
//	//assert(king.isValidMove({ 2, 4 }, { 3, 3 }, board) == true); // move top-right
//	//assert(king.isValidMove({ 4, 2 }, { 3, 3 }, board) == true); // move bottom-left
//	//assert(king.isValidMove({ 4, 4 }, { 3, 3 }, board) == true); // move bottom-right
//
//
//	// Test case 2: King cannot move more than one step
//
//	// Test move to invalid positions
//	//assert(king.isValidMove({ 3, 1 }, { 3, 3 }, board) == false); // move two steps left
//	//assert(king.isValidMove({ 3, 5 }, { 3, 3 }, board) == false); // move two steps right
//	//assert(king.isValidMove({ 1, 3 }, { 3, 3 }, board) == false); // move two steps up
//	//assert(king.isValidMove({ 5, 3 }, { 3, 3 }, board) == false); // move two steps down
//	//assert(king.isValidMove({ 1, 1 }, { 3, 3 }, board) == false); // move two steps top-left
//	//assert(king.isValidMove({ 1, 5 }, { 3, 3 }, board) == false); // move two steps top-right
//	//assert(king.isValidMove({ 5, 1 }, { 3, 3 }, board) == false); // move two steps bottom-left
//	//assert(king.isValidMove({ 5, 5 }, { 3, 3 }, board) == false); // move two steps bottom-right
//}
//
//void testKnight() {
//	// Test case 1: Knight can make a valid move to an empty tile
//	{
//		Board board; // create an empty chessboard
//		Knight knight({ 3, 3 }, PieceColor::White); // create a white knight at the center of the board
//		board.addPiece(&knight, 3, 3); // add the knight to the board at its initial position
//
//		// Move the knight to a valid position
//		bool result = knight.isValidMove({ 1, 2 }, { 3, 3 }, board);
//		assert(result); // expected result: true
//	}
//
//	// Test case 2: Knight cannot move to an occupied tile with same color piece
//	//{
//	//	Board board; // create an empty chessboard
//	//	Knight knight1({ 3, 3 }, PieceColor::White); // create a white knight at the center of the board
//	//	Knight knight2({ 1, 2 }, PieceColor::White); // create another white knight at a valid destination
//	//	board.addPiece(&knight1, 3, 3); // add the first knight to the board at its initial position
//	//	board.addPiece(&knight2, 1, 2); // add the second knight to the board at the destination position
//
//	//	// Try to move the first knight to the position of the second knight
//	//	bool result = knight1.isValidMove({ 1, 2 }, { 3, 3 }, board);
//	//	assert(!result); // expected result: false
//	//}
//
//	// Test case 3: Knight can capture an opponent's piece
//	{
//		Board board; // create an empty chessboard
//		Knight knight1({ 3, 3 }, PieceColor::White); // create a white knight at the center of the board
//		Knight knight2({ 1, 2 }, PieceColor::Black); // create a black knight at a valid destination
//		board.addPiece(&knight1, 3, 3); // add the first knight to the board at its initial position
//		board.addPiece(&knight2, 1, 2); // add the second knight to the board at the destination position
//
//		// Move the first knight to capture the second knight
//		bool result = knight1.isValidMove({ 1, 2 }, { 3, 3 }, board);
//		assert(result); // expected result: true
//	}
//}
//
//void testBishop() {
//	// Arrange
//	Board board;
//	Bishop* bishop1 = new Bishop(PieceColor::Black, 'B');
//	Bishop* bishop2 = new Bishop(PieceColor::White, 'B');
//	Bishop* bishop3 = new Bishop(PieceColor::White, 'B');
//	Knight* knight = new Knight(PieceColor::White, 'k');
//
//	// Act
//	board.addPiece(bishop1, 0, 0);
//	board.addPiece(bishop2, 0, 0);
//	board.addPiece(knight, 1, 1);
//	board.addPiece(bishop3, 6, 6);
//	board.addPiece(new Knight(PieceColor::Black, 'k'), 7, 7);
//
//	// Assert
//	// Test isValidMove() for bishop1
//	assert(bishop1->isValidMove({ 1, 7 }, { 0, 0 }, board) == false);
//
//	// Test isValidMove() for bishop2
//	assert(bishop2->isValidMove({ 2, 2 }, { 0, 0 }, board) == false);
//
//	// Test isValidMove() for bishop3
//	assert(bishop3->isValidMove({ 7, 7 }, { 6, 6 }, board) == true);
//
//	// Test movePiece() for bishop1
//	board.movePiece({ 0, 0 }, { 7, 7 });
//
//	// Test printPieceAtPosition() for various positions
//	board.printPieceAtPosition({ 0, 0 });
//	board.printPieceAtPosition({ 1, 1 });
//	board.printPieceAtPosition({ 6, 6 });
//	board.printPieceAtPosition({ 7, 7 });
//
//	delete bishop1;
//	delete bishop2;
//	delete bishop3;
//	delete knight;
//}
//
//int main() {
//	testKnight();
//	return 0;
//}
//
//void testPiece() {
//	//	Board board;
//	//
//	//	// Test addPiece() method
//	//	// Add a piece to the board and check if it's added at the correct position
//	//	std::pair<int, int> position;
//	//	position.first = 0;
//	//	position.second = 0;
//	//
//	//	Piece* piece = new King(PieceColor::White, 'K');
//	//	board.addPiece(piece, 0, 0);
//	//	assert(board.boundaries(0, 0));
//	//	assert(board.isCheck(PieceColor::White) == false);
//	//	/*assert(board.isCheck(PieceColor::Black) == false);*/
//	//
//	//	// Test movePiece() method
//	//	// Move the piece to a new position and check if it's moved correctly
//	//	std::pair<int, int> fromPosition(0, 0);
//	//	std::pair<int, int> toPosition(1, 1);
//	//	board.movePiece(fromPosition, toPosition);
//	//	assert(board.boundaries(1, 1) == true);
//	//	assert(board.boundaries(8, 8) == false);
//	//	assert(board.isCheck(PieceColor::White) == false);
//	//	/*assert(board.isCheck(PieceColor::Black) == false);*/
//	//
//	//	// Test findKing() method
//	//	// Add a black king to the board and check if findKing() returns its correct position
//	//	Piece* blackKing = new King(PieceColor::Black, 'K');
//	//	board.addPiece(blackKing, 7, 7);
//	//	std::pair<int, int> kingPosition = board.findKing(PieceColor::Black);
//	//	assert(kingPosition.first == 7);
//	//	assert(kingPosition.second == 7);
//	//
//	//	//// Test isCheck() method
//	//	//// Add a white bishop attacking the black king and check if isCheck() returns true
//	//	Piece* whiteBishop = new Bishop(PieceColor::White, 'B');
//	//	board.addPiece(whiteBishop, 5, 5);
//	//	assert(board.isCheck(PieceColor::Black) == true);
//	//	assert(board.isCheck(PieceColor::White) == false);
//	//
//	//	//// Test boundaries() method
//	//	//// Check if the boundaries() method returns correct results for various positions
//	//	assert(board.boundaries(0, 0));
//	//	assert(board.boundaries(7, 7));
//	//	assert(board.boundaries(-1, 0) == false);
//	//	assert(board.boundaries(0, -1) == false);
//	//	assert(board.boundaries(8, 0) == false);
//	//	assert(board.boundaries(0, 8) == false);
//	//
//	//	//// Clean up dynamically allocated memory
//	//	delete piece;
//	//	delete blackKing;
//	//	delete whiteBishop;
//	//
//	//	std::cout << "All tests passed successfully!" << std::endl;
//	//
//}