#include "BoardWindow.hpp"

GI::BoardWindow::BoardWindow(QWidget* parent) : QMainWindow(parent) {
	auto widgetPrincipal = new QWidget(this);
	widgetPrincipal->resize(320, 320);
	auto layoutPrincipal = new QGridLayout(widgetPrincipal);
	mainLayout = layoutPrincipal;

	board = new Board;
	board->addPiecesOnBoard();

	connect(board, &Board::boardChanged, this, &GI::BoardWindow::hasChanged);

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			CW::ClickableLabel* ClickLabel = addSquare(QString::number(i), i, j);
			ClickLabel->setObjectName(QString::number(i) + QString::number(j));
			QLabel* button = ClickLabel;
			layoutPrincipal->addWidget(button, i, j);
			connect(ClickLabel, &CW::ClickableLabel::clicked, board, &Board::isClicked);
		}
	}
}

void GI::BoardWindow::render() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			CW::ClickableLabel* ClickLabel = addSquare(QString::number(i), i, j);
			ClickLabel->setObjectName(QString::number(i) + QString::number(j));
			QLabel* button = ClickLabel;
			mainLayout->addWidget(button, i, j);
			connect(ClickLabel, &CW::ClickableLabel::clicked, board, &Board::isClicked);
		}
	}
}

GI::BoardWindow::~BoardWindow() {
	delete board;
}

CW::ClickableLabel* GI::BoardWindow::addSquare(const QString& text, int col, int row) {
	CW::ClickableLabel* square = new CW::ClickableLabel(col, row, this);

	square->setFixedSize(40,40);
	square->setAlignment(Qt::AlignCenter);

	(col + row) % 2 == 0 ? square->setStyleSheet("background-color: rgb(42, 68, 102);") : square->setStyleSheet("background-color:rgb(222, 222, 222);");
	
	Piece* piecePtr = board->getPiece(col, row);
	if (piecePtr != nullptr) { 
		std::string imageStr = piecePtr->getImage();
		QPixmap pixmap;
		if (pixmap.load(imageStr.c_str())) {
			pixmap = pixmap.scaled(square->size(), Qt::KeepAspectRatio);
			square->setPixmap(pixmap);
		}
	};
	
	return square;
}

void GI::BoardWindow::hasChanged() {
	render();
}