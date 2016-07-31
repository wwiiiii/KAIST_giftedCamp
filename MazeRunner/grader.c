#include "grader.h"

int gradeAlgo()
{
	int result[MAP_NUM + 5];
	int sum = 0;
	//setModeNoShow();
	setModeShow(100);
	for (int i = 1; i <= MAP_NUM; i++)
	{
		loadMapData(i);
		myFunction();
		sum += getCount();
		result[i] = getCount();
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 16 * 0 + 07);
	system("cls");
	for (int i = 1; i <= MAP_NUM; i++)
	{
		printf("%dth result : %d\n", i, result[i]);
	}
	return sum;
}

