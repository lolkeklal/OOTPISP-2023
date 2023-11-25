#pragma once
#ifndef BUILDER_H
#define BUILDER_H
#include "eyes.h"
#include "ears.h"
#include "mouth.h"
#include "hair.h"
#include "nose.h"

class builder {
public:
	virtual void buildEyes() = 0;
	virtual void buildNose() = 0;
	virtual void buildMouth() = 0;
	virtual void buildEars() = 0;
	virtual void buildHair() = 0;
	virtual void getResult() const = 0;
};

#endif