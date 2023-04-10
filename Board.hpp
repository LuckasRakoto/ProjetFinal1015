#include "Pieces.hpp"

class Board {
private:
    Piece* board_[8][8];

public:
    Board() { //initialise ttes les positions du board a nullptr
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                board_[i][j] = nullptr;
            }
        }
    }

    void addPiece(Piece* piece, std::pair<int, int > position) { //rajoute la piece au board
        board_[get<0>(position)][get<1>(position)] = piece;
    }

    //TODO: movePiece()
};