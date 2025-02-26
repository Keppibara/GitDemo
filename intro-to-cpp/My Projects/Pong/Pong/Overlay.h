#pragma once
#include "raylib/raylib.h"

class Player;

class Overlay
{
public:
	Overlay(float screenW, float screenH);

public:
	void Render(Player* player1, Player* player2);

private:
	Color m_color;

	float m_courtLineSize;
	int m_courtSegmentCount;

	int m_scoreHeight;
	int m_scoreOffset;
	int m_scoreFontSize;

	float m_screenWidth;
	float m_screenHeight;

private:
	void RenderBackground();
	void RenderScore(Player* player);

};

