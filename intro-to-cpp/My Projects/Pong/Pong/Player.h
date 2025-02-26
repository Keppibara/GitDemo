#pragma once
#include "Actor.h"
class Player : public Actor
{
public:
	Player(int id, float screenW, float screenH);

public:
	void Tick(float dt) override;
	void Render() override;

	int GetId();
	int GetScore();

	void ScoreGoal();

private:
	int m_id;
	int m_score;

	float m_screenHeight;
	float m_speed;

	float m_hue;


};
