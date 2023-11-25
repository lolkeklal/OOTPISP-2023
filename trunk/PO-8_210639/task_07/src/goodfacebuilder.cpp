#include "goodfacebuilder.h"
#include <qDebug>

void goodFaceBuilder::buildEars() {
	ears* newEars = new ears();
	newEars->color = "beidge";
	newEars->figure = "circle";
	Ears = newEars;
}

void goodFaceBuilder::getResult() const
{
	qDebug() << "good face: ";
	Eyes->print();
	Ears->print();
	Mouth->print();
	Nose->print();
	Hair->print();
}

void goodFaceBuilder::buildEyes() {
	eyes* newEyes = new eyes();
	newEyes->color = "blue";
	newEyes->figure = "circle";
	Eyes = newEyes;
}

void goodFaceBuilder::buildMouth() {
	mouth* newMouth = new mouth();
	newMouth->color = "pink";
	newMouth->figure = "half circle";
	Mouth = newMouth;
}

void goodFaceBuilder::buildNose() {
	nose* newNose = new nose();
	newNose->color = "beidge";
	newNose->figure = "triangle";
	Nose = newNose;
}

void goodFaceBuilder::buildHair() {
	hair* newHair =  new hair();
	newHair->color = "blonde";
	newHair->figure = "rectangle";
	Hair = newHair;
}