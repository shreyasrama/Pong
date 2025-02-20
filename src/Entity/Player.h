#pragma once

class Player
{
public:
	Vector2 Position = { 0, 0 };
	Vector2 Size = { 0, 0 };

	float Speed = 5.0f;

	Player(float x, float y, float width, float height, float speed);
	[[nodiscard]] Rectangle GetCollisionRect() const;
	void Draw() const;
};