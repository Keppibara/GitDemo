#include "Player.h"


Player::Player(int id, float screenW, float screenH)
	: m_id{ id }, m_score{ 0 }, m_screenHeight{ screenH }, m_speed{ 300.f }, m_hue{0}
{
	m_size = { 13.f, 90.f };

	Vector2 halfSize = { m_size.x * .5f, m_size.y * .5f };

	m_position =
	{
		m_id == 0 ? halfSize.x : screenW - m_size.x - halfSize.x,
		screenH * .5f - halfSize.y
	};

}

void Player::Tick(float dt)
{
	// Player 1 move up is w, player 2 move up is up arrow
	int upKey = m_id == 0 ? KEY_W : KEY_UP;
	// Player 1 move down is s, player 2 move down is down arrow
	int downKey = m_id == 0 ? KEY_S : KEY_DOWN;


	if (IsKeyDown(upKey))
	{
		m_position.y -= m_speed * dt;
	}
	if (IsKeyDown(downKey))
	{
		m_position.y += m_speed * dt;
	}
	if (m_position.y + m_size.y > m_screenHeight)
	{
		m_position.y = m_screenHeight - m_size.y;
	}
	if (m_position.y < 0)
	{
		m_position.y = 0;
	}
}

void Player::Render()
{
	m_hue += GetFrameTime() * 100.f;
	if (m_hue > 360.f)
	{
		m_hue = 0.f;
	}
	DrawRectangleV(m_position, m_size, ColorFromHSV(m_hue, 1.f, 1.f));
}

int Player::GetId()
{
	return m_id;
}

int Player::GetScore()
{
	return m_score;
}

void Player::ScoreGoal()
{
	m_score++;
}
