#pragma once
#ifndef GOODFACEBUILDER_H
#define GOODFACEBUILDER_H
#include "builder.h"

class goodFaceBuilder : public builder {
public:
	void buildEyes() override;
	void buildNose() override;
	void buildMouth() override;
	void buildEars() override;
	void buildHair() override;
	void getResult() const override;
private:
	eyes* Eyes;
	ears* Ears;
	mouth* Mouth;
	nose* Nose;
	hair* Hair;
};

#endif