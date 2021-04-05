#include<bios.h>
#include<dos.h>
#include<process.h>
#include"battlesh.cpp"
#include"mouse.cpp"
#include<stdlib.h>
int jambu, rememberx = -1, remembery = -1, x, y;
struct lives
{
	int 	s;
	int 	d;
	int 	b;
	int 	c;
} u, p;
int check_pos1(int x, int y)
{
	int i, j;
	if (x < 340) i = 0;
	else if (x < 360) i = 1;
	else if (x < 380) i = 2;
	else if (x < 400) i = 3;
	else if (x < 420) i = 4;
	else if (x < 440) i = 5;
	else if (x < 460) i = 6;
	else if (x < 480) i = 7;
	if (y < 170) j = 0;
	else if (y < 190) j = 1;
	else if (y < 210) j = 2;
	else if (y < 230) j = 3;
	else if (y < 250) j = 4;
	else if (y < 270) j = 5;
	else if (y < 290) j = 6;
	else if (y < 310) j = 7;
	if (pc[1][j][i] != '\0') return 0;
	else return 1;
}
void pc_disp()
{
	for (int j = 0, x = 320; j < 8; j++)
	{
		for (int i = 0, y = 150; i < 8; i++)
		{
			if (pc[1][i][j] == 'x')  setcolor(GREEN);
			else setcolor(RED);
			outtextxy(x + 5, y + 5, ctos(pc[1][i][j]));
			y += 20;
		}
		x += 20;
	}
}
