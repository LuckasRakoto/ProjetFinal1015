#include <utility>
#include <QObject>


class Piece: public QObject {
		Q_OBJECT
	private:
		std::pair<int, int> position_;
		char piece_;
		char color_;

	public:
		explicit Piece(char piece, char color) : piece_(piece), color_(color) {};
		virtual ~Piece() = default;

	public slots:
		

	signals:
		void positionChanged(std::pair<int, int> newPos);
		
};