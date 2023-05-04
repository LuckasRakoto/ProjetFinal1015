#include "ClickabelLabel.hpp"

CW::ClickableLabel::ClickableLabel(int i, int j, QWidget* parent, Qt::WindowFlags f) :
	QLabel(parent),
	row(i),
	col(j){}


CW::ClickableLabel::~ClickableLabel() {}

void CW::ClickableLabel::mousePressEvent(QMouseEvent* event) {
	int i = row;
	int j = col;
	emit clicked(i,j);
}