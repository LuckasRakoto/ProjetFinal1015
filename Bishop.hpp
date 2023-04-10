#include "Pieces.hpp"
#include "Board.hpp"

class Bishop : public Piece {
public:
    /*Bishop(char color);*/ //positionner le fou à son endroit respectif pour sa couleur
    Bishop(std::pair<int, int> position, char couleur) : Piece(position, 'B', couleur) {} // creation bishop (B)
    /*~Bishop() { ; }*/ // besoin du destructeur??

    bool isValidMove(std::pair<int, int> newPosition, const Board& board) override { // verifie si deplacement = une case
        int diffRow = abs(get<0>(newPosition) - get<0>(position_));
        int diffColumn = abs(get<1>(newPosition) - get<1>(position_));

        if (diffRow == diffColumn) return true;
        //TODO: creer une fonction qui verifie qu'il y a pas de piece qui bloque le passage en diagonale
        else return false;
    }
};
