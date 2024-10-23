#include "raylib.h"

#include "Player.h"

Player::Player(const float x, const float y, const float width, const float height, const float speed)
{
	Position.x = x;
	Position.y = y;
	Size.x = width;
	Size.y = height;
	Speed = speed;
}

Rectangle Player::GetCollisionRect() const {
	return Rectangle
	{
		Position.x, Position.y, Size.x, Size.y
	};
}

void Player::Draw() const
{
	DrawRectangleV(Position, Size, RAYWHITE);
}