#pragma once

class Input
{
	bool isInit;
	float keyRelease[400];
	float keyPress[400];
	bool  keyState[400];

	float mouseRelease[10];
	float mousePress[10];
	bool  mouseState[10];

	Input::Input() : isInit(false) { }

	float mouseX, mouseY;
public:
	static Input &instance() { static Input instance; return instance; }

	bool init();
	bool step();
	void term() { }

	// Based on the state of the input at the beginning of the frame
	bool getKey(unsigned); // true if key is down
	bool getKeyPress(unsigned); // true on frame when key is pressed
	bool getKeyRelease(unsigned); // true on frame when key is released  

	bool getMouseButton(unsigned); // true if key is down
	bool getMouseButtonPress(unsigned); // true on frame when key is pressed
	bool getMouseButtonRelease(unsigned); // true on frame when key is released

	float keyDelta(unsigned); // difference between last press and release

	float getMouseX();
	float getMouseY();

	bool     isInitialized() { return isInit; }
};