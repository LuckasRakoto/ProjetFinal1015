#include <utility>
#include <QObject>

class Piece : public QObject, public Board {
	Q_OBJECT
protected:
	std::pair<int, int> position_; // current position (row, column)
	char piece_;
	char color_;

public:
	explicit Piece(std::pair<int, int> position, char piece, char color) : position_(position), piece_(piece), color_(color) {}; //Constructeur; prk explicit?
	virtual ~Piece() = default; //Destructeur; prk virtual?

	virtual bool isValidMove(std::pair<int, int> newPosition, const Board& board) = 0; //Validation du move
		
	void moveTo(std::pair<int, int> newPosition) { //Deplacement de position (apres validation)
		get<0>(position_) = get<0>(newPosition);
		get<1>(position_) = get<1>(newPosition);
	}

	char getPiece() const { return piece_; }
	char getColor() const { return color_; }
	
/*public slots:
signals:
	void positionChanged(std::pair<int, int> newPos);*/
};