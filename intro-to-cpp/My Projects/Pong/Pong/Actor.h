#pragma once
#include <raylib/raylib.h>

class Actor
{
public:
	// This is called when the actor spawns
	virtual void BeginPlay();

	//This is called every frame... dt is the time between
	// frames
	virtual void Tick(float dt);
	// This is called every frame in the "draw" loop
	virtual void Render();

	// This is called when the actor is destroyed
	virtual void Endplay();

	Vector2 GetPosition();
	Vector2 GetSize(); 

protected:
	Vector2 m_position;
	Vector2 m_size;

protected:
	Actor();
	virtual ~Actor();
};

