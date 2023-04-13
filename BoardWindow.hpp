#include "Pieces.hpp"

#pragma warning(push, 0) // Sinon Qt fait des avertissements à /W4.
#include <QMainWindow>
#include <QPushButton>
#include <QString>
#include <QLabel>
#include <QGridLayout>
#pragma pop()
class Piece {};

class BoardWindow : public QMainWindow {
    Q_OBJECT
private:
    Piece* board_[8][8];
    QPushButton* addSquare(const QString& text, int col, int row/*, const T& slot*/) {
        QPushButton* button = new QPushButton(this);
        (col + row) % 2 == 0 ? button->setStyleSheet({ "background-color: rgb(31,85,6);" }) : button->setStyleSheet(QString::fromUtf8("background-color:rgb(213,255,208);"));
        button->setFlat(true);
        button->setGeometry(QRect(col * 71, (row + 1) * 71, 71, 71));
        button->setText(text);
        return button;

    }

public:
    BoardWindow(QWidget* parent = nullptr) : QMainWindow(parent) {
        auto widgetPrincipal = new QWidget(this);
        auto layoutPrincipal = new QGridLayout(widgetPrincipal);

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                QPushButton* button = addSquare(QString::number(i), i, j);
                layoutPrincipal->addWidget(button, i, j); // ajoute les carr�s
            }
        }
        this->resize(568, 568);
        setCentralWidget(widgetPrincipal);
        setWindowTitle("Echecs");
    }
    ~BoardWindow() override = default;


