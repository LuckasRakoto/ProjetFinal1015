#pragma once

#include <QLabel>
#include <QWidget>
#include <Qt>
#include <iostream>

namespace CW { //CW= custom widgets
	class ClickableLabel : public QLabel { //inspir� de https://wiki.qt.io/Clickable_QLabel
		Q_OBJECT
	private:
		int col;
		int row;
	public:
		explicit ClickableLabel(int i, int j, QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
		~ClickableLabel();

	signals:
		void clicked(int row, int col);

	protected:
		void mousePressEvent(QMouseEvent* event);
	};
}