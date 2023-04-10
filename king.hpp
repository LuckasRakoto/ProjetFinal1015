#include "Pieces.hpp"
#include "Board.hpp"

class King : public Piece {
	public:
		King(char color); //positionner le roi à son endroit respectif pour sa couleur
        King(std::pair<int, int> position, char couleur) : Piece(position, 'K', couleur) {} // creation king (K)
		~King(); //synonyme de fin de partie aussi !

        bool isValidMove(std::pair<int, int> newPosition, const Board& board) override { // verifie si deplacement = une case
            int diffRow = abs(get<0>(newPosition) - get<0>(position_));
            int diffColumn = abs(get<1>(newPosition) - get<1>(position_));

            if (diffRow <= 1 && diffColumn <= 1) return true;
            else return false;
        }
};