#include "ConSnake.h"
#include <time.h>
#include <iostream>

using namespace std;

Vector2d Vector2d::Up = { 0, -1 };
Vector2d Vector2d::Down = { 0, 1 };
Vector2d Vector2d::Left = { -1, 0 };
Vector2d Vector2d::Right = { 1, 0 };




SnakeGame::SnakeGame()
{
	snake_head = &snake[0];

	RestartGame();
}


void SnakeGame::Run()
{
}


void SnakeGame::RiseSnake(int amount)
{
}


bool SnakeGame::BodyInCell(int x, int y, bool checkForHead)
{
	return false;
}


void SnakeGame::InitMap()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			map[i][j] = 0;
		}

	PlaceRandomFruit();
}


void SnakeGame::RestartGame()
{
	InitMap();

	//reset frame number
	frame_number = 0;

	//snake
	body_length = 1;
	*snake_head = Vector2d(N / 2, M / 2);
	dir = Vector2d::Right;
}


void SnakeGame::PlaceRandomFruit()
{
	int x, y;

	do
	{
		x = rand() % N;
		y = rand() % M;

	} while ((map[x][y] != 0) || BodyInCell(x, y, true));

	//finally
	map[x][y] = 1;
}


void SnakeGame::Tick()
{
}


void SnakeGame::ServeKeyboard()
{
}


void SnakeGame::Draw()
{
}


void SnakeGame::DrawMap()
{
}


void SnakeGame::DrawSnake()
{
}


void SnakeGame::DrawFruit()
{
}
