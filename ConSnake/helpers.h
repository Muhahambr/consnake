#pragma once
#include <windows.h>
#include <time.h> 
#include <stdio.h>



int Clamp(int min_value, int max_value, int value)
{
	if (value < min_value)
		value = min_value;

	if (value > max_value)
		value = max_value;

	return value;
}



void SetCursorPosition(int X, int Y)
{
	HANDLE Screen;
	Screen = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Position = { X, Y };

	SetConsoleCursorPosition(Screen, Position);
}


void HideCursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}


void PrintChar(unsigned char c) {
	printf("%c", c);
}


void PrintCharAtPos(int x, int y, unsigned char c) {
	SetCursorPosition(x, y);
	PrintChar(c);
}

/*
void PrintCharAtPoint(struct Vector2 p, unsigned char c) {
	SetCursorPosition(p.x, p.y);
	PrintChar(c);
} */



void Delay(int ms)
{
	// Storing start time 
	clock_t start_time = clock();

	// looping till required time is not achieved 
	while (clock() < start_time + ms)
		;
}