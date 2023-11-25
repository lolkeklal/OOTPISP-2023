#include "faceDirector.h"

void faceDirector::construct(builder* b) {
	b->buildEars();
	b->buildEyes();
	b->buildHair();
	b->buildMouth();
	b->buildNose();
	b->getResult();
}