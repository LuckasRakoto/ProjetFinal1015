#include "ClickabelLabel.hpp"

ClickableLabel::ClickableLabel(int i, int j, QWidget* parent, Qt::WindowFlags f) :
	QLabel(parent),
	row(i),
	col(j){}


ClickableLabel::~ClickableLabel() {}

void ClickableLabel::mousePressEvent(QMouseEvent* event) {
	int i = row;
	int j = col;
	std::cout << i <<", " << j << std::endl;
	emit clicked(i,j);
}