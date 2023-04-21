#ifndef CLICKABEL_LABEL
#define CLICKABEL_LABEL

#include <QLabel>
#include <QWidget>
#include <Qt>
#include <iostream>

class ClickableLabel : public QLabel {
	Q_OBJECT
private:
	int col;
	int row;
public:
	explicit ClickableLabel(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags(),int i,int j);
	~ClickableLabel();

signals:
	void clicked(int row, int col);

protected:
	void mousePressEvent(QMouseEvent* event);
};

#endif