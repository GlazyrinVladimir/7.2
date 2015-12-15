#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "var.h"

using namespace sf;
using namespace std;

struct Block {
	Block(float x, float y, Vector2f size);
	RectangleShape *block;
	Vector2f sizeBlock;
	Vector2f posBlock;
	float speed;
	int opacity;
}; 

struct EndPositionStep {
	float oneEndStep = LIMIT_ONE_STEP;
	float twoEndStep = LIMIT_TWO_STEP;
	Vector2f fourEndStep = LIMIT_FOUR_STEP;
};

struct Animation {
	vector<Block> blocks;
	EndPositionStep endPosStep;
	int iterator = 1;
	void OneStep();
	void TwoStep();
	void ThreeStep();
	void FourStep();
	void FiveStep();
};

void InitBlocks(Animation & animation);
void DrawObject(vector<Block> & blocks, RenderWindow & window);
void Delete(vector<Block> & blocks);