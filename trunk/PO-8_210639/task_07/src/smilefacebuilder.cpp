#include "smilefacebuilder.h"
#include <qDebug>

void smileFaceBuilder::buildEars() {
	ears* newEars = new ears();
	newEars->color = "beidge";
	newEars->figure = "half circle";
	Ears = newEars;
}

void smileFaceBuilder::getResult() const
{
	qDebug() << "good face: ";
	Eyes->print();
	Ears->print();
	Mouth->print();
	Nose->print();
	Hair->print();
}

void smileFaceBuilder::buildEyes() {
	eyes* newEyes = new eyes();
	newEyes->color = "yellow";
	newEyes->figure = "circle";
	Eyes = newEyes;
}

void smileFaceBuilder::buildMouth() {
	mouth* newMouth = new mouth();
	newMouth->color = "red";
	newMouth->figure = "half circle";
	Mouth = newMouth;
}

void smileFaceBuilder::buildNose() {
	nose* newNose = new nose();
	newNose->color = "beidge";
	newNose->figure = "circle";
	Nose = newNose;
}

void smileFaceBuilder::buildHair() {
	hair* newHair = new hair();
	newHair->color = "brown";
	newHair->figure = "oval";
	Hair = newHair;
}