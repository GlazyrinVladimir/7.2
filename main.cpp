#include <SFML/Graphics.hpp>
#include "Animation.h"


using namespace sf;
using namespace std;

const Time TIME_PER_FRAME = seconds(1.f / 60.f);

void processEvents(RenderWindow & window) {
	Event event;
	while (window.pollEvent(event)) {

		if ((event.type == Event::Closed) || (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)) {
			window.close();
		}
	}
}

void update(RenderWindow & window, const Time & deltaTime, Animation & animation) {
	if (animation.iterator == 1)
		animation.OneStep();
	if (animation.iterator == 2)
		animation.TwoStep();
	if (animation.iterator == 3)
		animation.ThreeStep();
	if (animation.iterator == 4)
		animation.FourStep();
	if (animation.iterator == 5)
		animation.FiveStep();
	if (animation.iterator == 6)
		animation.iterator = 1;
}

void render(RenderWindow & window, Animation & animation) {
	window.clear(Color::White);
	DrawObject(animation.blocks, window);
	window.display();
}

void StartAnimation() {
	RenderWindow window(VideoMode(SCREEN_SIZE.x, SCREEN_SIZE.y), "Lab 7_2");

	Animation *animation = new Animation;
	InitBlocks(*animation);

	Clock clock;
	Time timeSinceLastUpdate = Time::Zero;

	while (window.isOpen()) {
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TIME_PER_FRAME) {
			timeSinceLastUpdate -= TIME_PER_FRAME;
			processEvents(window);
			update(window, TIME_PER_FRAME, *animation);
		}
		render(window, *animation);
	}
	Delete(animation->blocks);
	delete animation;
}

int main() {
	StartAnimation();
	return 0;
}