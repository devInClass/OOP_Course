#pragma once
#include "Actor.h"
#include "raylib.h"

Actor::Actor() : x_(400.0f), y_(300.0f), radius_(20.0f), isMovingRight_(true) {}

Actor::Actor(float x, float y, float radius) : x_(x), y_(y), radius_(radius), isMovingRight_(true) {}

Actor::~Actor() {}

void Actor::Update(float deltaTime, float speed) {
	// Example update logic: move the actor to the right over time

	float speed_ = speed * deltaTime; // units per second

	if (isMovingRight_) {
		x_ += speed_;
	} else {
		x_ -= speed_;
	}
	

	if (x_ + radius_ >= static_cast<float>(GetScreenWidth())) { // Wrap around if it goes off screen
		isMovingRight_ = false;
	} else if (x_ - radius_ <= 0.0f) {
		isMovingRight_ = true;
	}


}

void Actor::Draw() {
	DrawCircle(static_cast<int>(x_), static_cast<int>(y_), radius_, RED); // Draw a red circle representing the actor
}