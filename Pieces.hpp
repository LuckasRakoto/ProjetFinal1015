#include <utility>
#include <QObject>


class Piece: public QObject {
		Q_OBJECT
	private:
		std::pair<int, int> position_;
		char piece_;
		char couleur_;

	public:
		explicit Piece(char piece, char couleur) : piece_(piece), couleur_(couleur) {};
		virtual ~Piece() = default;

	public slots:
		

	signals:
		void positionChanged(std::pair<int, int> nouvellePos);
		
};