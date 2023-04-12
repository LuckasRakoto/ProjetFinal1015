#include "Pieces.hpp"
#include "Board.hpp"

class Knight : public Piece {
public:
    /*Horse(char color);*/ //positionner le cavalier à son endroit respectif pour sa couleur
    Knight(std::pair<int, int> position, char couleur) : Piece(position, 'H', couleur) {} // creation horse (H)
    /*~Horse() { ; }*/ // besoin du destructeur??

    bool isValidMove(std::pair<int, int> newPosition, const Board& board) override { // verifie si deplacement = une case
        int diffRow = abs(get<0>(newPosition) - get<0>(position_));
        int diffColumn = abs(get<1>(newPosition) - get<1>(position_));

        if ((diffRow == 2 && diffColumn == 1) || (diffRow == 1 && diffColumn == 2)) return true;
        else return false;
    }
};
