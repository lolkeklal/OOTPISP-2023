#pragma once
#ifndef UGLYFACEBUILDER_H
#define UGLYFACEBUILDER_H
#include "builder.h"

class uglyFaceBuilder: public builder {
public:
	void buildEyes() override;
	void buildNose() override;
	void buildMouth() override;
	void buildEars() override;
	void buildHair()override{};
	void getResult() const override;
private:
	eyes* Eyes;
	ears* Ears;
	mouth* Mouth;
	nose* Nose;
};

#endif