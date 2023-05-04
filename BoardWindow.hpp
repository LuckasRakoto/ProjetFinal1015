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
		CW::ClickableLabel* addSquare(const QString& text, int col, int row);
		void render();
	private:
		Board* board;
		QGridLayout* mainLayout;
	public slots:
		void hasChanged();
	};
}