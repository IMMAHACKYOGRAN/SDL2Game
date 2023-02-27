#pragma once
#include "Vec2.h"

class Player
{
public:
	Player(Vec2 pos);

	void Update();

private:
	Vec2 m_Pos;
};