void startGame()
{
	system("cls");
	ShowConsoleCursor(false);

	drawBox();
	drawSnake();
	genApple();
	displayScore();

	while (true)
	{
		if (_kbhit())
		{
			char ch = _getch();
			ch = tolower(ch);
			if (ch == 'a' && direction != Direction::right)
				direction = Direction::left;
			else if (ch == 'w' && direction != Direction::down)
				direction = Direction::up;
			else if (ch == 's' && direction != Direction::up)
				direction = Direction::down;
			else if (ch == 'd' && direction != Direction::left)
				direction = Direction::right;
			else if (ch == 'q') // Quit game
			{
				showEndMenu();
				break;
			}
		}
		move();
		drawHeadnTail();
		if (isAteApple())
		{
			score++;
			displayScore();
			growing();
			genApple();
		}
		if (isBiteItself())
		{
			ShowConsoleCursor(true);
			showEndMenu();
			break;
		}
		if (isHitWall())
		{
			ShowConsoleCursor(true);
			showEndMenu();
			break;
		}
		Sleep(speed);
	}
}
