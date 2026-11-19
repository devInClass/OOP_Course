#pragma once
#include "raylib.h"

struct Vec2 {
	float x;
	float y;

	Vec2() : x(0.0f), y(0.0f) {}
	Vec2(float x, float y) : x(x), y(y) {}

	// operator overloads for vector addition and subtraction
	Vec2& operator+=(const Vec2& other) { // mutating addition
		x += other.x;
		y += other.y;
		return *this;
	}

	// free: builds on += Non mutating addition
	friend Vec2 operator+(Vec2 a, const Vec2& b) {
		a += b;
		return a;
	}



};

class Actor {
public:
	Actor();
	Actor(Vec2 position, float radius, float scale, Color color, float rotation);
	virtual ~Actor();
	virtual void Update(float deltaTime, float speed);
	virtual void Draw();

private:
	Vec2 position_;
	float scale_;
	Color color_;
	float rotation_;
	float radius_;
	bool isMovingRight_;
};