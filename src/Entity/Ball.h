#pragma once

class Ball
{
public:
	Vector2 Position = { 0, 0 };
	Vector2 Size = { 0, 0 };
	Vector2 Speed = { 0, 0 };

public:
	Ball(float x, float y, float width, float height, float speed);
	Rectangle GetCollisionRect();
	void Update();
	void Draw();

private:
	void Reset();
};