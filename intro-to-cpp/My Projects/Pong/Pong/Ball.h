#pragma once
#include "Actor.h"
class Ball : public Actor
{
public:
	Ball(float screenW, float screenH);

public:
	void Tick(float dt) override;

	void CheckCollisionWith(Actor* other, Vector2 velocityMod);

	void Reset();

private:
	float m_speed;

	Vector2 m_velocity;
	Vector2 m_startPos;
};

