#include "raylib.h"

#include "Player.h"

Player::Player(float x, float y, float width, float height, float speed)
{
	Position.x = x;
	Position.y = y;
	Size.x = width;
	Size.y = height;
	Speed = speed;
}

Rectangle Player::GetCollisionRect()
{
	return Rectangle
	{
		Position.x, Position.y, Size.x, Size.y
	};
}

void Player::Draw()
{
	DrawRectangleV(Position, Size, RAYWHITE);
}