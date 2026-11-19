#pragma once

class Actor {
public:
	Actor();
	Actor(float x, float y, float radius);
	virtual ~Actor();
	virtual void Update(float deltaTime, float speed);
	virtual void Draw();

private:
	float x_;
	float y_;
	float radius_;
	bool isMovingRight_;
};