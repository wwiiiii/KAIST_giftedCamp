#include <stdio.h>
#include "mazeapi.h"
#define LOOP(X) for(int i=0;i<X;i++)
int main()
{
	loadMapData();
	setModeShow(150);
	/*
	�ֺ� ��ġ �˻���
	int nearmap[3][3];
	findNear(nearmap);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++) printf("%d", nearmap[i][j]);
		puts("");
	} Sleep(3000); system("cls");
	
	*/
	move(RIGHT);
	LOOP(2) move(DOWN);
	move(LEFT);
	LOOP(3) move(DOWN);
	LOOP(4) move(RIGHT);
	LOOP(3) move(UP);
	LOOP(3) move(RIGHT);
	LOOP(3) move(DOWN);
	while (1);
}