#pragma once
#include "myclass.h"

#define N 30	// width
#define M 20	// height



// 1 - fruit / apple
// 0 - empty cell

struct Vector2d
{
	int x = 0;
	int y = 0;

	int old_x = 0;
	int old_y = 0;

	static Vector2d Up;
	static Vector2d Down;
	static Vector2d Left;
	static Vector2d Right;


	Vector2d() {
		x = 0;
		y = 0;

		old_x = 0;
		old_y = 0;
	}

	Vector2d(int _x, int _y)
	{
		x = _x;
		y = _y;

		old_x = x;
		old_y = y;
	}


	bool operator != (const Vector2d other)
	{
		return !(this->x == other.x && this->y == other.y);
	}


	Vector2d operator += (const Vector2d np)
	{
		old_x = x;
		old_y = y;

		x += np.x;
		y += np.y;

		return *this;
	}

	bool isNull()
	{
		return x == 0 && y == 0;
	}
};






class SnakeGame {

private:
	int frame_number = 0;

	int map[N][M];

	int body_length = 1;
	Vector2d * snake_head;
	Vector2d snake[256];

	Vector2d dir;

	//game logic
	void RiseSnake(int amount = 1);
	bool BodyInCell(int x, int y, bool checkForHead);

	void InitMap();
	void RestartGame();

	void PlaceRandomFruit();
	void Tick();
	void ServeKeyboard();


	void Draw();
	void DrawMap();
	void DrawSnake();
	void DrawFruit();

public:
	SnakeGame();

	void Run();
};

