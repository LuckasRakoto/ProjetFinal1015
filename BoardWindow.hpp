#include "Pieces.hpp"
#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QMainWindow>
#include <QLabel>
#include <QWidget>
#include <Qt>
#include <QGridLayout>
#include <iostream>
#include <QtGui>

class ClickableLabel : public QLabel { // Permet de faire un label cliquable -> Servira à cliquer sur les pièces
	Q_OBJECT

public:
	explicit ClickableLabel(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());

signals:
	void clicked();

protected:
	void mousePressEvent(QMouseEvent* event);

};

#endif

class Square : public QWidget {
public:
    Square();
protected:
    void paintEvent(QPaintEvent*, bool color);
};

class BoardWindow: public QMainWindow {
    Q_OBJECT
private:
    Piece* board_[8][8];

public:
    BoardWindow(QWidget* parent = nullptr);
    ~BoardWindow() override = default;

public slots:
    void pieceClicked();

    template <typename T>
    QLabel* CreateSquare(const QString& text, const T& slot);

    //void addPiece(Piece* piece, std::pair<int, int > position) { //rajoute la piece au board
    //    board_[get<0>(position)][get<1>(position)] = piece;
    //}

    //TODO: movePiece()
};

