#pragma once
#include <vector>
#include "raylib/raylib.h"

using std::vector;

class Ball;
class Player;
class Overlay;
class Wall;

struct WallData
{
public:
	Wall* object;
	Vector2 ballVelocityMod;
};

class Application
{
public:
	Application();
	~Application();

public:
	// This will handle the entire game loop
	int Run();

private:
	float m_screenWidth;
	float m_screenHeight;

	Player* m_player1;
	Player* m_player2;
	Overlay* m_overlay;
	Ball* m_ball;

	float m_wallSize;
	vector<WallData> m_walls;

private:
	void BeginPlay();

	void Tick(float dt);
	void Render();

	void EndPlay();
};

