#include "ClickabelLabel.hpp"

ClickableLabel::ClickableLabel(QWidget* parent, Qt::WindowFlags f,int i,int j) :
	QLabel(parent), row(i), col(j) {}


ClickableLabel::~ClickableLabel() {}

void ClickableLabel::mousePressEvent(QMouseEvent* event) {
	int i = row;
	int j = col;
	std::cout << i << std::endl;
	emit clicked(i,j);
}