#include "BoardWindow.hpp"

BoardWindow::BoardWindow(QWidget* parent) : QMainWindow(parent) {
	auto widgetPrincipal = new QWidget(this);
	auto layoutPrincipal = new QGridLayout(widgetPrincipal);

	board = new Board;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			QLabel* button = addSquare(QString::number(i), i, j);
			layoutPrincipal->addWidget(button, i, j);
		}
	}
}

BoardWindow::~BoardWindow() {
	delete board;
}

QLabel* BoardWindow::addSquare(const QString& text, int col, int row) {
	QLabel* square = new ClickableLabel();

	square->setFixedHeight(71);
	square->setFixedWidth(71);

	(col + row) % 2 == 0 ? square->setStyleSheet("background-color: rgb(31,85,6);") : square->setStyleSheet("background-color:rgb(213,255,208);");


	if (board->getPiece(col, row) == nullptr) return square;
	return nullptr;
}
