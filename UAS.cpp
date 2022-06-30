#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;


struct  {
	bool gameOver;
	const int width = 20;
	const int height = 20;
	int x;
	int y; 
	int fruitX;
	int fruitY;
	int score;
	int tailX[100];
	int tailY[100];
	int nTail;	
} config;

//GameConfig config;

int level = 1;
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirecton dir;

void levelUp(int *level){
	
	*level = *level + 1; 
}
void Setup()
{
	
	config.gameOver = false;
	dir = STOP;
	config.x = config.width / 2;
	config.y = config.height / 2;
	config.fruitX = rand() % config.width;
	config.fruitY = rand() % config.height;
	config.score = 0;
}
void Draw()
{
	system("cls"); //system("clear");
	for (int i = 0; i < config.width+2; i++)
		cout << "#";
	cout << endl;

	for (int i = 0; i < config.height; i++)
	{
		for (int j = 0; j < config.width; j++)
		{
			if (j == 0)
				cout << "#";
			if (i == config.y && j == config.x)
				cout << "O";
			else if (i == config.fruitY && j == config.fruitX)
				cout << "F";
			else
			{
				bool print = false;
				for (int k = 0; k < config.nTail; k++)
				{
					if (config.tailX[k] == j && config.tailY[k] == i)
					{
						cout << "o";
						print = true;
					}
				}
				if (!print)
					cout << " ";
			}
				

			if (j == config.width - 1)
				cout << "#";
		}
		cout << endl;
	}

	for (int i = 0; i < config.width+2; i++)
		cout << "#";
	cout << endl;
	cout << "Score:" << config.score << endl;
	cout << "Level:" << level << endl;
}
void Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x':
			config.gameOver = true;
			break;
		}
	}
}
void Logic()
{
	int prevX = config.tailX[0];
	int prevY = config.tailY[0];
	int prev2X, prev2Y;
	config.tailX[0] = config.x;
	config.tailY[0] = config.y;
	for (int i = 1; i < config.nTail; i++)
	{
		prev2X = config.tailX[i];
		prev2Y = config.tailY[i];
		config.tailX[i] = prevX;
		config.tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	switch (dir)
	{
	case LEFT:
		config.x--;
		break;
	case RIGHT:
		config.x++;
		break;
	case UP:
		config.y--;
		break;
	case DOWN:
		config.y++;
		break;
	default:
		break;
	}
	//if (x > width || x < 0 || y > height || y < 0)
	//	gameOver = true;
	if (config.x >= config.width) config.x = 0; else if (config.x < 0) config.x = config.width - 1;
	if (config.y >= config.height) config.y = 0; else if (config.y < 0) config.y = config.height - 1;

	for (int i = 0; i < config.nTail; i++)
		if (config.tailX[i] == config.x && config.tailY[i] == config.y)
			config.gameOver = true;

	if (config.x == config.fruitX && config.y == config.fruitY)
	{
		config.score += 10;
		
		if(config.score/10%2==0){
			levelUp(&level);	
		}

		config.fruitX = rand() % config.width;
		config.fruitY = rand() % config.height;
		config.nTail++;
	}
}
int main()
{
	Setup();
	while (!config.gameOver)
	{
		Draw();
		Input();
		Logic();
		Sleep(10); //sleep(10);
	}
	return 0;
}



@
Link youtube
https://youtu.be/mgAkYEizjWg
