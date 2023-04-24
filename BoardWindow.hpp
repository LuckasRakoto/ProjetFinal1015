#pragma once

#include <QMainWindow>
#include <QGridLayout>
#include <QString>
#include <QLabel>
#include <string>
#include <QPixmap>
#include <iostream>

#include "Board.hpp"
#include "ClickabelLabel.hpp"

namespace GI { //GI = graphical interface
	class BoardWindow : public QMainWindow {
		Q_OBJECT

	public:
		BoardWindow(QWidget* parent = nullptr);
		~BoardWindow() override;
		QLabel* addSquare(const QString& text, int col, int row);

	private:
		Board* board;
	};
}