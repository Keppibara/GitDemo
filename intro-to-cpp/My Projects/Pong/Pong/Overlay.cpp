#include "Overlay.h"
#include <string>
#include "Player.h"

using std::string;

Overlay::Overlay(float screenW, float screenH)
	: m_color{ LIGHTGRAY }, m_courtLineSize{ 15.f }, m_courtSegmentCount{ 15 },
	m_scoreHeight{ 25 },m_scoreOffset{ 50 }, m_scoreFontSize{ 50 },
	m_screenWidth{ screenW }, m_screenHeight{ screenH }
{
}

void Overlay::Render(Player* player1, Player* player2)
{
	RenderBackground();
	RenderScore(player1);
	RenderScore(player2);
}

void Overlay::RenderBackground()
{
	float halfScreenWidth = m_screenWidth * .5f;
	float halfLineSize = m_courtLineSize * .5f;

	// Render the top line
	DrawRectangleV({ 0, 0 }, { m_screenWidth, m_courtLineSize }, m_color);
	// Render the Bottom line
	DrawRectangleV({ 0, m_screenHeight - m_courtLineSize }, { m_screenWidth, m_courtLineSize }, m_color);

	//Draw the shovel
	// How large is each segment vertically
	float segmentOffset = m_screenHeight / m_courtSegmentCount;
	// center the x
	float xPos = halfScreenWidth - halfLineSize;
	for (int i = 0; i < m_courtSegmentCount; ++i)
	{
		//Calculate where this segmate should go (segment offset * skips every
		// other segment
		float yPos = i * (segmentOffset * 2);
		DrawRectangleV({ xPos, yPos }, { m_courtLineSize, segmentOffset }, m_color);
	}
}

void Overlay::RenderScore(Player* player)
{
	float halfScreenWidth = m_screenWidth * .5f;

	string scoreText = std::to_string(player->GetScore());
	// Get the length of the text in pixels
	int textWidth = MeasureText(scoreText.c_str(), m_scoreFontSize);

	int x = player->GetId() == 0 ? -m_scoreOffset : m_scoreOffset;
	// Get the center of the screen offset by the width of the text
	x += (static_cast<int>(m_screenWidth) - textWidth) / 2;

	DrawText(scoreText.c_str(), x, m_scoreHeight, m_scoreFontSize, m_color);
}
