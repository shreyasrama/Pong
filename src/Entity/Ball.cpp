#include "raylib.h"

#include "Ball.h"
#include "Game/Game.h"

Ball::Ball(const float x, const float y, const float width, const float height, const float speed)
{
	Position.x = x;
	Position.y = y;
	Size.x = width;
	Size.y = height;
	Speed.x = speed;
	Speed.y = speed;
}

Rectangle Ball::GetCollisionRect() const {
	return Rectangle
	{
		Position.x, Position.y, Size.x, Size.y
	};
}

void Ball::Update()
{
	Position.x += Speed.x;
	Position.y += Speed.y;

	if (Position.x >= SCREEN_WIDTH)
	{
		PLAYER_1_SCORE++;
		Reset();
	}

	if (Position.x <= 0)
	{
		PLAYER_2_SCORE++;
		Reset();
	}

	if (Position.y <= 0 || (Position.y + Size.y) >= SCREEN_HEIGHT)
	{
		Speed.y = -Speed.y;
	}
}

void Ball::Draw() const {
	DrawRectangleV(Position, Size, RED);
}

void Ball::Reset()
{
	Position.x = static_cast<float>(SCREEN_WIDTH) / 2;
	Position.y = static_cast<float>(SCREEN_HEIGHT) / 2;
}
