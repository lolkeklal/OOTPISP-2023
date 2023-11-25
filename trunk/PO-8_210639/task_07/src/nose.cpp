#include "nose.h"
#include <qDebug>

void nose::print() {
	qDebug() << "nose: " << color << " " << figure;
}