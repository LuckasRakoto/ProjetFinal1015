#include "King.hpp"

King::King(char color) { // verif heritage pas sûr de comment ça marche
    if (color == 'w') {
        position_ = { 4,0 };
    }
    else if (color == 'b') {
        position_ = { 4,7 };
    }
}

bool King::isValidMove(std::pair<int, int> newPosition, const Board& board) override { // methode verifiant si deplacement = une case
    if (newPosition.first >= 0 && newPosition.first < 8 && newPosition.second >= 0 && newPosition.second < 8) {
        int diffRow = abs(newPosition.first - position_.first);
        int diffColumn = abs(newPosition.second - position_.second);

        if (diffRow <= 1 && diffColumn <= 1) return true;
        else return false;
    }
    else {
        return false;
    }
}

