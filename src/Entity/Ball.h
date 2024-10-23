#pragma once

class Ball
{
public:
	Vector2 Position = { 0, 0 };
	Vector2 Size = { 0, 0 };
	Vector2 Speed = { 0, 0 };

	Ball(float x, float y, float width, float height, float speed);
	[[nodiscard]] Rectangle GetCollisionRect() const;
	void Update();
	void Draw() const;

private:
	void Reset();
};