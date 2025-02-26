#include "Ball.h"

Ball::Ball(float screenW, float screenH)
	: m_speed{ 300.f }, m_velocity{ 1, -1}
{
	m_size = { 15.f, 15.f };

	Vector2 halfSize = { m_size.x * .5f, m_size.y * .5f };
	Vector2 halfScreenSize = { screenW * .5f, screenH * .5f };

	m_position =
	{
		halfScreenSize.x - halfSize.x,
		halfScreenSize.y - halfSize.y
	};
	m_startPos = m_position;
}

void Ball::Tick(float dt)
{
	m_position.x += m_velocity.x * m_speed * dt;
	m_position.y += m_velocity.y * m_speed * dt;

}

void Ball::CheckCollisionWith(Actor* other, Vector2 velocityMod)
{
	// Create a box around the ball
	Rectangle myCollider =
	{
		m_position.x,
		m_position.y,
		m_size.x,
		m_size.y
	};
	// Create a box around the other actor
	Rectangle otherCollider =
	{
		other->GetPosition().x,
		other->GetPosition().y,
		other->GetSize().x,
		other->GetSize().y
	};

	// Check if there is any overlap between the two colliders
	if (CheckCollisionRecs(myCollider, otherCollider)) 
	{
		// Apply the velocity mod
		m_velocity.x *= velocityMod.x;
		m_velocity.y += velocityMod.y;
	}
}

void Ball::Reset()
{
	m_position = m_startPos;
}
