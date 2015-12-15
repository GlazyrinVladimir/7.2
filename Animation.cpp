#include "Animation.h"

Block::Block(float x, float y, Vector2f size) {
	posBlock = { x, y };
	sizeBlock = size;
	block = new RectangleShape(sizeBlock);
	//block.setSize(sizeBlock);
	block->setPosition(posBlock);
	block->setFillColor(Color::Red);
	block->setOrigin(sizeBlock.x / 2, sizeBlock.y / 2);
	speed = SPEED;
	opacity = 255;
}

void Animation::OneStep() {
	int opacity = blocks[0].opacity;
	for (int i = 0; i < blocks.size(); ++i) {
		blocks[i].block->move(blocks[i].speed, 0);
		blocks[i].block->setFillColor(Color(0, 0, 0, opacity));
	}
	blocks[0].opacity -= DIFF_TO_OPACITY;
	if (blocks[0].block->getPosition().x == endPosStep.oneEndStep && iterator == 1)
		++iterator;
}

void Animation::TwoStep() {
	
	Vector2f size =  blocks[0].sizeBlock  ;
	for (int i = 0; i < blocks.size(); ++i) {
		blocks[i].block->move(-blocks[i].speed, blocks[i].speed / 2);
		blocks[i].block->setSize(size);
	}
	if (blocks[0].block->getPosition().x <= endPosStep.twoEndStep && iterator == 2)
		++iterator;
	blocks[0].sizeBlock.x += DIFF_TO_WIDTH;
	blocks[0].sizeBlock.y -= DIFF_TO_HEIGHT;
}

void Animation::ThreeStep() {
	for (int i = 1; i < blocks.size(); ++i) {
		if (blocks[0].block->getPosition().y != blocks[i].block->getPosition().y) 
			blocks[i].block->move(blocks[i].speed / 3, -blocks[i].speed / 4);
	}
	if (blocks[0].block->getPosition().y == blocks[blocks.size() - 1].block->getPosition().y && iterator == 3)
		++iterator;
}

void Animation::FourStep() {
	int opacity = blocks[0].opacity;
	Vector2f size = blocks[0].sizeBlock;
	for (int i = 0; i < blocks.size(); ++i) {
		blocks[i].block->move(0, -blocks[i].speed / 2);
		blocks[i].block->setSize(size);
		blocks[i].block->setFillColor(Color(0, 0, 0, opacity));
	}
	if (blocks[0].opacity < 255)
		blocks[0].opacity += DIFF_TO_OPACITY;
	if (blocks[0].sizeBlock.x > SIZE_BLOCK)
		blocks[0].sizeBlock.x -= DIFF_TO_WIDTH;
	if (blocks[0].sizeBlock.y < SIZE_BLOCK)
		blocks[0].sizeBlock.y += DIFF_TO_HEIGHT;
	if (blocks[0].block->getPosition().y == endPosStep.fourEndStep.y && iterator == 4)
		++iterator;
}

void Animation::FiveStep() {
	for (int i = 1; i < blocks.size(); ++i) {
		if (blocks[0].block->getPosition().x != blocks[i].block->getPosition().x) {
			blocks[i].block->move(-blocks[i].speed / 3, blocks[i].speed / 4);
		}
	}
	if (blocks[0].block->getPosition().x == blocks[blocks.size() - 1].block->getPosition().x && iterator == 5)
		++iterator;

}

void InitBlocks(Animation & animation) {
	Vector2f beginPosBlock = LIMIT_FOUR_STEP;
	for (int i = 0; i < COUNT_BLOCK; ++i) {
		Block addBlock(beginPosBlock.x, beginPosBlock.y, { SIZE_BLOCK, SIZE_BLOCK });
		beginPosBlock.y += SIZE_BLOCK * DISTANCE_BETWEEN_BLOCKS;
		animation.blocks.push_back(addBlock);
	}
}

void DrawObject(vector<Block> & blocks, RenderWindow & window) {
	for (int i = 0; i < blocks.size(); ++i) {
		window.draw(*blocks[i].block);
	}
}

void Delete(vector<Block> & blocks) {
	for (int i = 0; i < blocks.size(); ++i) {
		delete blocks[i].block;
	}
}