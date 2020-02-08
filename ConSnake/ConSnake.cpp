#include <time.h>
#include <conio.h>

#include "ConSnake.h"
#include "helpers.h"


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
	HideCursor();

	while (Tick())
	{
		Draw();
	}
}


bool SnakeGame::Tick()
{
	ServeKeyboard();


	//move snake body
	for (int i = body_length; i > 0; --i)
	{
		snake[i] = snake[i - 1];
	}

	//check for fruit
	if (map[snake_head->x][snake_head->y] == 1)
	{
		//rise snake
		RiseSnake();

		//place new fruit
		PlaceRandomFruit();

		map[snake_head->x][snake_head->y] = 0;
	}


	//update head position according to direction
	*snake_head += dir;
	//old_dir = dir;


	//check for area borders
	if (snake[0].x >= MAP_WIDTH) snake[0].x = 0;
	if (snake[0].x < 0) snake[0].x = MAP_WIDTH - 1;
	if (snake[0].y >= MAP_HEIGHT) snake[0].y = 0;
	if (snake[0].y < 0) snake[0].y = MAP_HEIGHT - 1;


	//check for self head intersect with body
	return (!BodyInCell(snake_head->x, snake_head->y, false));
}


void SnakeGame::RiseSnake(int amount)
{
	for (int i = 0; i < amount; i++)
	{
		body_length++;
		snake[body_length - 1] = snake[body_length - 2];
	}
}


bool SnakeGame::BodyInCell(int x, int y, bool checkForHead)
{
	int start_index = checkForHead ? 0 : 1;

	for (int i = start_index; i < body_length; i++)
	{
		if (x == snake[i].x && y == snake[i].y)
		{
			return true;
		}
	}


	return false;
}


void SnakeGame::InitMap()
{
	for (int i = 0; i < MAP_WIDTH; i++)
		for (int j = 0; j < MAP_HEIGHT; j++)
		{
			map[i][j] = 0;
		}

	PlaceRandomFruit();
}


void SnakeGame::RestartGame()
{
	InitMap();

	//snake
	body_length = 1;
	*snake_head = Vector2d(MAP_WIDTH / 2, MAP_HEIGHT / 2);
	dir = Vector2d::Right;
}


void SnakeGame::PlaceRandomFruit()
{
	int x, y;

	do
	{
		x = rand() % MAP_WIDTH;
		y = rand() % MAP_HEIGHT;

	} while ((map[x][y] != 0) || BodyInCell(x, y, true));

	//finally
	map[x][y] = 1;
}





void SnakeGame::ServeKeyboard()
{
	unsigned char key;
	do {
		key = _getch();
	} while (!(key == 75 || key == 77 || key == 72 || key == 80));
	

	if (key == 75 && (dir != Vector2d::Right))
		dir = Vector2d::Left;

	if (key == 77 && (dir != Vector2d::Left))
		dir = Vector2d::Right;

	if (key == 72 && (dir != Vector2d::Down))
		dir = Vector2d::Up;

	if (key == 80 && (dir != Vector2d::Up))
		dir = Vector2d::Down;

	
}


void SnakeGame::Draw()
{
	DrawMap();
	DrawSnake();
	DrawFruit();
}


void SnakeGame::DrawMap()
{
	for (int i = 0; i < MAP_WIDTH; i++)
		for (int j = 0; j < MAP_HEIGHT; j++)
		{
			switch (map[i][j])
			{
			case 0:
				PrintCharAtPos(i, j, '.');
				break;
			case 1:
				PrintCharAtPos(i, j, '@');
				break;
			}

		}
}


void SnakeGame::DrawSnake()
{
	for (int i = 0; i < body_length; i++)
		PrintCharAtPos(snake[i].x, snake[i].y, '#');
}


void SnakeGame::DrawFruit()
{

}
