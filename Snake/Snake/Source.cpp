﻿#include <iostream>

#include "Environment.h"
#include "Food.h"
#include "Snake.h"

using namespace  std;

int main()
{
	int gameSpeed = 100;
	Environment environment(5, 5, 45, 25);

	Snake snake(environment.margin);
	Food food(environment.margin);

	char controller = 'p';
	while (true)
	{
		environment.Clear();
		environment.DrawBorder();
		environment.Draw(snake);
		environment.Draw(food);
		environment.GetControl(controller);

		if (food.position == snake.Head())
		{
			snake.Eat();
			food.SetNewPosition();
		}

		switch (controller)
		{
		case 'w':
			snake.direction = Up;
			break;

		case 's':
			snake.direction = Down;
			break;

		case 'd':
			snake.direction = Right;
			break;

		case 'a':
			snake.direction = Left;
			break;
		}

		snake.Move();

		Sleep(gameSpeed);
	}

	return 0;
}