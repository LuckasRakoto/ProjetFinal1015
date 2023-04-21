#include "BoardWindow.hpp"

GI::BoardWindow::BoardWindow(QWidget* parent) : QMainWindow(parent) {
	auto widgetPrincipal = new QWidget(this);
	widgetPrincipal->resize(400, 400);
	auto layoutPrincipal = new QGridLayout(widgetPrincipal);

	board = new Board;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			QLabel* button = addSquare(QString::number(i), i, j);
			layoutPrincipal->addWidget(button, i, j);
		}
	}
}

GI::BoardWindow::~BoardWindow() {
	delete board;
}

QLabel* GI::BoardWindow::addSquare(const QString& text, int col, int row) {
	QLabel* square = new CW::ClickableLabel(col, row);

	square->setFixedSize(50,50);

	(col + row) % 2 == 0 ? square->setStyleSheet("background-color: rgb(42, 68, 102);") : square->setStyleSheet("background-color:rgb(222, 222, 222);");
	

	if (board->getPiece(col, row) != nullptr) {

	};
	
	return square;
}
