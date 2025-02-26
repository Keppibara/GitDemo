#include "Actor.h"
#include "raylib/raylib.h"

void Actor::BeginPlay()
{
}

void Actor::Tick(float dt)
{
}

void Actor::Render()
{
	DrawRectangleV(m_position, m_size, WHITE);
}

void Actor::Endplay()
{
}

Vector2 Actor::GetPosition()
{
	return m_position;
}

Vector2 Actor::GetSize()
{
	return Vector2();
}



Actor::Actor()
	: m_position{ 0, 0}, m_size{ 0, 0}
{
}

Actor::~Actor()
{
}
