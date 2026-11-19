#pragma once
#include "Actor.h"


Actor::Actor() : position_(Vec2{100, 100}), 
	radius_(20.0f),
	scale_(1.0f),
	color_(RED),
	rotation_(0.0f),
	isMovingRight_(true) {}

Actor::Actor(Vec2 position, float radius, float scale, Color color, float rotation) : 
	position_(position), 
	radius_(radius), 
	scale_(scale), 
	color_(color), 
	rotation_(rotation),
	isMovingRight_(true) { }

Actor::~Actor() {}

void Actor::Update(float deltaTime, float speed) {
	// Example update logic: move the actor to the right over time

	float speed_ = speed * deltaTime; // units per second

	if (isMovingRight_) {
		position_.x += speed_;
	} else {
		position_.x -= speed_;
	}
	

	if (position_.x + radius_ >= static_cast<float>(GetScreenWidth())) { // Wrap around if it goes off screen
		isMovingRight_ = false;
	} else if (position_.x - radius_ <= 0.0f) {
		isMovingRight_ = true;
	}


}

void Actor::Draw() {
	DrawCircle(static_cast<int>(position_.x), static_cast<int>(position_.y), radius_, RED); // Draw a red circle representing the actor
}