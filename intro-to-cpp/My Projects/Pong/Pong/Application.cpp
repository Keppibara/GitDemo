#include "Application.h"
#include <cstdlib>
#include "raylib/raylib.h"
#include "Ball.h"
#include "Overlay.h"
#include "Player.h"
#include "Wall.h"

Application::Application()
	: m_screenWidth{ 1024.f }, m_screenHeight{ 768.f }, m_player1{ nullptr },
	m_player2{ nullptr }, m_overlay{ nullptr }, m_ball{ nullptr }, m_wallSize{10.f }
{
}

Application::~Application()
{
	delete m_ball;

	for (WallData wallData : m_walls)
	{
		delete wallData.object;
	}

	delete m_overlay;

	delete m_player2;
	delete m_player1;

}

int Application::Run()
{
	// Open the window and initialise the graphics context
	InitWindow(static_cast<int>(m_screenWidth), static_cast<int>(m_screenHeight), "Pong");

	// Did the dindow open correctly?
	if (!IsWindowReady())
	{
		// It didn't, so say failure
		return EXIT_FAILURE;
	}

	// Initialisation Logic
	BeginPlay();

	// While we haven't pressed the 'x' or Quit Key (default 'escape')
	while (!WindowShouldClose())
	{
		// Get frame time returns the time a single frame took (deltaTime)
		Tick(GetFrameTime());

		// Any drawing code MUST be between
		// these two functions
		BeginDrawing();

		ClearBackground(BLACK);
		Render();

		EndDrawing();
	}

	// Shutdown logic
	EndPlay();
	// Shutdown raylib
	CloseWindow();
	return 0;
}

void Application::BeginPlay()
{
	// Create the two player pointers
	m_player1 = new Player(0, m_screenWidth, m_screenHeight);
	m_player2 = new Player(1, m_screenWidth, m_screenHeight);

	// Run both players initalise logic
	m_player1->BeginPlay();
	m_player2->BeginPlay();

	// Create the Overlay object
	m_overlay = new Overlay(m_screenWidth, m_screenHeight);

	// Create the ball object and run initialise logic
	m_ball = new Ball(m_screenWidth, m_screenHeight);
	m_ball->BeginPlay();

	// Create top and bottom walls
	m_walls.emplace_back(WallData
		{
			new Wall({ 0, -m_wallSize }, { m_screenWidth, m_wallSize }),
			Vector2{1, -1 }
		});
	m_walls.emplace_back(WallData
		{
			new Wall({ 0, m_screenHeight + m_wallSize }, { m_screenWidth, m_wallSize }),
			Vector2{ 1, -1}
		});
}


void Application::Tick(float dt)
{
	m_player1->Tick(dt);
	m_player2->Tick(dt);

	m_ball->Tick(dt);

	for (WallData wallData : m_walls)
	{
		m_ball->CheckCollisionWith(wallData.object, wallData.ballVelocityMod);
	}

	m_ball->CheckCollisionWith(m_player1, { -1, 1 });
	m_ball->CheckCollisionWith(m_player2, { -1, 1 });

	if (m_ball->GetPosition().x + m_ball->GetSize().x > m_screenWidth)
	{
		m_ball->Reset();
		m_player1->ScoreGoal();
	}

	if (m_ball->GetPosition().x < m_ball->GetSize().x)
	{
		m_ball->Reset();
		m_player2->ScoreGoal();
	}
}

void Application::Render()
{
	m_overlay->Render(m_player1, m_player2);

	m_player1->Render();
	m_player2->Render();

	m_ball->Render();

}

void Application::EndPlay()
{
	m_player1->Endplay();
	m_player2->Endplay();


}