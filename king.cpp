#include "King.hpp"

King::King(char color) { // verif heritage pas sûr de comment ça marche
    if (color == 'w') {
        position_ = { 4,0 };
    }
    else if (color == 'b') {
        position_ = { 4,7 };
    }
}

bool King::isValidMove(std::pair<int, int> newPosition, const Board& board) { // verifie si deplacement = une case
    int diffRow = abs(newPosition.first - position_.first);
    int diffColumn = abs(newPosition.second - position_.second);

    if (diffRow <= 1 && diffColumn <= 1) return true;
    else return false;
}