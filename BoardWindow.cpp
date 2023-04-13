#include "BoardWindow.hpp"

ClickableLabel::ClickableLabel(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags())
	: QLabel(parent) {}

ClickableLabel::~ClickableLabel() {}

void ClickableLabel::mousePressEvent(QMouseEvent* event) {
	emit clicked();
}

Square::Square() {
    QPalette palette(Square::palette());
    palette.setColor(backgroundRole(), Qt::white);
    setPalette(palette);
}

void Square::paintEvent(QPaintEvent*, bool color) { //true = blanc
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    color ? painter.setBrush(QBrush("#e8d5cc")) : painter.setBrush(QBrush("#6e625d"));
    painter.drawRect(10, 15, 90, 60);

}

template <typename T>
QLabel* BoardWindow::CreateSquare(const QString& text, const T& slot) { // Créer un label carré (clickable)

}


BoardWindow::BoardWindow(QWidget* parent = nullptr): /*QMainWindow(parent)*/ { //initialise ttes les positions du board a nullptr
    auto widgetPrincipal = new QWidget(this);
    auto layoutPrincipal = new QGridLayout(widgetPrincipal);

    


    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            Square square;
            layoutPrincipal->addWidget() // ajoute les carrés
        }
    }
}