#include "Pieces.hpp"
#include "Board.hpp"
#include <cmath>

class Bishop : public Piece {
public:
    /*Bishop(char color);*/ //positionner le fou à son endroit respectif pour sa couleur
    Bishop(std::pair<int, int> position, char couleur) : Piece(position, 'B', couleur) {} // creation bishop (B)
    /*~Bishop() { ; }*/ // besoin du destructeur??

    bool isValidMove(std::pair<int, int> newPosition, const Board& board) override { // verifie si deplacement = une case
        int diffRow = abs(newPosition.first - position_.first);
        int diffColumn = abs(newPosition.second - position_.second);

        if ((diffRow == diffColumn) && noPiecesOnPath(newPosition, board)) return true;
        else return false;
    }

    // Fonction qui verifie qu'il y a pas de piece qui bloque le passage en diagonale
    bool noPiecesOnPath(std::pair<int, int> newPosition, const Board& board) {
        int rowDiff = abs(newPosition.first - position_.first);
        int rowMove, columnMove;
        
        // direction de mouvement de case (ligne)
        if (newPosition.first > position_.first) rowMove = 1;
        else rowMove = -1;
        // direction de mouvement de case (colonne)
        if (newPosition.second > position_.second) rowMove = 1;
        else rowMove = -1;

        int row, col;
        for (int i = 1; i < rowDiff; i++) {
            row = this->position_.first + i * rowMove;
            col = this->position_.second + i * columnMove;
            if (board[row][col] != nullptr) {
                return false; // Path not clear
            }
        }
        return true; // Path clear
    }
};
