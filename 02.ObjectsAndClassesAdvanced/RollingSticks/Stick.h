#ifndef STICK_H
#define STICK_H

class Stick {
public:
	Stick() : symbol(symbols[0]), position(0) {}
	char nextAnimation() const {
		return symbols[++position % ANIMATIONS_COUNT];
	}
	int getPosition() const {
		return position;
	}
private:
	static const ushort ANIMATIONS_COUNT = 4;
	const char symbols[ANIMATIONS_COUNT] = { '_', '\\', '|' ,'/' };
	mutable char symbol;
	mutable int position;
};

#endif // !STICK_H

