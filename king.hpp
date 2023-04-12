#include "Pieces.hpp"

class King : public Piece {
	public:
		King(char color); //positionner le roi à son endroit respectif pour sa couleur
        King(std::pair<int, int> position, char couleur) : Piece(position, 'K', couleur) {} // creation king (K)
		~King(); //synonyme de fin de partie aussi !

		bool isValidMove(std::pair<int, int> newPosition, const Board& board);
};