#pragma once
#include <utility>
#include <string>
//#include <QObject>


enum class PieceColor {
	White,
	Black
};

class Board;

class Piece {
protected:
	std::pair<int, int> position_; //{row, col}
	char piece_;
	PieceColor color_;
	std::string image_;

public:
	explicit Piece(std::pair<int, int> position, char piece, PieceColor color) : position_(position), piece_(piece), color_(color) {}; //Constructeur; prk explicit? -> on veut pas de conversion pas explicite
	explicit Piece(PieceColor color, char piece) : color_(color), piece_(piece) {};
	virtual ~Piece() = default;

	virtual bool isValidMove(std::pair<int, int> newPosition, std::pair<int, int> currentPosition, Board& board) = 0; //Validation du move

	void moveTo(std::pair<int, int> newPosition);

	// GETTERS
	char getPiece() const { return piece_; }
	PieceColor getColor() const { return color_; }
	std::pair<int, int> getPosition() const { return position_; }

	std::string getImage() const { return image_; }
};