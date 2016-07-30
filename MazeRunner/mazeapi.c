#include "mazeapi.h"

//now location : arr[nowy][nowx]

int nearMap[3][3];

void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void loadMapData()
{
	FILE * f = fopen("map1.txt", "r");
	int a, b; fscanf(f, "%d %d", &a, &b); 
	row = a, col = b; mode = posx = posy = 1; cnt = 0;
	map = malloc(sizeof(int*) * a);
	for (int i = 0; i < a; i++)
	{
		map[i] = malloc(sizeof(int)*b);
		for (int j = 0; j < b; j++)
		{
			fscanf(f, "%d", &map[i][j]);
		}
	}
	if (mode == 1) initPrintMap();
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void deleteMap()
{
	for (int i = 0; i < row; i++) free(map[i]);
	free(map);
}

void printMap()
{
	int a = row;
	int b = col;
	int i = posy, j = posx;
	gotoxy(2*j+marginx, i+marginy);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GREEN);
	switch (lastDir) {
		case UP: printf("で"); break;
		case DOWN: printf("ぬ"); break;
		case LEFT: printf("っ"); break;
		case RIGHT: printf("た"); break;
		default: break;
	}
	i -= dy[lastDir]; j -= dx[lastDir];
	gotoxy(2 * j + marginx, i + marginy);
	if (map[i][j] == 0) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLACK);
		printf("け");
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		printf("し");
	}
	//printf("%d %d\n", row, col);
	gotoxy(1, 1);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 16 * 7 + 0);
	printf("Total Move Count : %d\nLocation %d/%d %d/%d\n", cnt,posx,col-2,posy,row-2);
	Sleep(delay);
}

int move(int dir)
{
	cnt++; lastDir = dir;
	if (map[posy + dy[dir]][posx + dx[dir]] == 0) {
		if (mode == 1) printMap();
		return -1;
	}
	posx += dx[dir]; posy += dy[dir];
	if (posx == col-2&& posy == row-2) winGame();
	if (mode == 1) printMap();
	return 1;
}


void findNear(int arr[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			arr[i][j] = map[posy+i-1][posx+j-1];
		}
	}
}

void setModeShow(int d) { mode = 1; delay = d; }
void setModeNoShow() { mode = 0; }

void winGame()
{
	printMap();
	gotoxy(1, 1); 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 16*0+07);
	printf("Total Move Count : %d\nClear!                 \n", cnt);
	exit(1);
}


void initPrintMap()
{
	int a = row; int b = col;
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			gotoxy(2* j + marginx, i + marginy);
			if (i == posy && j == posx) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GREEN);
				switch (lastDir) {
				case UP: printf("で"); break;
				case DOWN: printf("ぬ"); break;
				case LEFT: printf("っ"); break;
				case RIGHT: printf("た"); break;
				default: break;
				}
			}
			else if (map[i][j] == 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLACK);
				printf("け");
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
				printf("し");
			}
		}
		puts("");
	}
}
