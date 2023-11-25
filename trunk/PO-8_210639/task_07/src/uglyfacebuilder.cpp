#include "uglyfacebuilder.h"
#include <qDebug>

void uglyFaceBuilder::buildEars() {
	ears* newEars = new ears();
	newEars->color = "red";
	newEars->figure = "square";
	Ears = newEars;
}

void uglyFaceBuilder::getResult() const
{
	qDebug() << "ugly face: ";
	Eyes->print();
	Ears->print();
	Mouth->print();
	Nose->print();
}

void uglyFaceBuilder::buildEyes() {
	eyes* newEyes = new eyes();
	newEyes->color = "black";
	newEyes->figure = "oval";
	Eyes = newEyes;
}

void uglyFaceBuilder::buildMouth() {
	mouth* newMouth = new mouth();
	newMouth->color = "red";
	newMouth->figure = "rectangle";
	Mouth = newMouth;
}

void uglyFaceBuilder::buildNose() {
	nose* newNose = new nose();
	newNose->color = "yellow";
	newNose->figure = "triangle";
	Nose = newNose;
}