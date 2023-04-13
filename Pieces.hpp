#include <utility>
#include <QObject>


enum class PieceColor {
	White,
	Black
};

class Piece : public QObject, public Board {
	Q_OBJECT
protected:
	std::pair<int, int> position_; //{row, col}
	char piece_;
	PieceColor color_;

public:
	explicit Piece(std::pair<int, int> position, char piece, PieceColor color) : position_(position), piece_(piece), color_(color) {}; //Constructeur; prk explicit? -> on veut pas de conversion pas explicite
	
	virtual ~Piece() = default; //Destructeur; prk virtual? 

	virtual bool isValidMove(std::pair<int, int> newPosition, const Board& board) = 0; //Validation du move
		
	void moveTo(std::pair<int, int> newPosition) { //Deplacement de position (apres validation)
		position_.first = newPosition.first;
		position_.second = newPosition.second;
	}



	char getPiece() const { return piece_; }
	PieceColor getColor() const { return color_; }
	
/*public slots:
signals:
	void positionChanged(std::pair<int, int> newPos);*/
};